#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include "ym2608_encode.h"

//
//  initialize ym2608 encoder handle
//
int32_t ym2608_encode_open(YM2608_ENCODE_HANDLE* ym2608, int32_t sample_rate, int16_t channels) {

  int32_t rc = -1;

  ym2608->sample_rate = sample_rate;
  ym2608->channels = channels;

  ym2608->ra = ym2608_ptoa_conv_table + 6;
  ym2608->la = ym2608_ptoa_conv_table + 6;

  ym2608->ry = 0;
  ym2608->ly = 0;

  rc = 0;

exit:
  return rc;
}

//
//  close ym2608 encoder handle
//
void ym2608_encode_close(YM2608_ENCODE_HANDLE* ym2608) {

}

//
//  one frame conversion macro (respect to adpcmlib.s by Otankonas-san)
//
static inline void onef(int16_t pcm_data, int16_t* rd_, uint8_t** ra_, int16_t* rd2_) {

  int16_t rd = *rd_;                                    // 予測値
  uint8_t* ra = *ra_;                                   // 変換テーブルポインタ
  int16_t rd2 = *rd2_;                                  // 出力値

  int16_t d5;                                           // 実測値
  int32_t cc, cs;                                       // キャリーフラグチェック用
  int16_t btst;                                         // ビットテスト用
  int32_t vc;                                           // オーバーフローチェック用

  // ソースPCMデータ読み込み
  d5 = pcm_data;                                        //  move.w (a1)+,d5

  // 予測値との差分を取る
  d5 -= rd;                                             //  sub.w RD,d5

  // プラスなら何もしない
  if (d5 > 0) goto at1;                                 //  bpl.w @f

  // マイナスなら符号反転して絶対値に戻す
  d5 = -d5;                                             //  neg.w d5

  // 出力ADPCMの符号をマイナスにしておく
  rd2 |= 0x08;                                          //  or.b #$8,RD2

at1:                                                    // @@:
  // 変換テーブル上のデルタ予測との差分を取る
  cc = d5 - (int16_t)(ra[0] * 256 + ra[1]);             //  cmp.w (RA),d5

  // 0以上であればlabel1に飛ぶ
  if (cc >= 0) goto label1;                             //  bcc.w 1f

  // 変換テーブルポインタを4バイト戻してat2に飛ぶ
  ra -= 4;                                              //  subq.w #4,RA
  goto at2;                                             //  bra @f

label1:                                                 // 1:
  // 変換テーブルポインタを4バイト進める
  ra += 4;                                              //  addq.w #4,RA

at2:                                                    // @@:
  // 変換テーブル上のデルタ予測との差分をもう一度取る
  // 変換テーブルポインタは2バイト進めておく
  cc = d5 - (int16_t)(ra[0] * 256 + ra[1]); ra += 2;    //  cmp.w (RA)+,d5

  // 0以上であればat3に飛ぶ
  if (cc >= 0) goto at3;                                //  bcc.w @f

  // 変換テーブルポインタを4バイト戻す
  ra -= 4;                                              //  subq.w #4,RA

at3:                                                    // @@:
  // 変換テーブル上のデルタ予測との差分を取る(三度目)
  cs = d5 - (int16_t)(ra[0] * 256 + ra[1]);             //  cmp.w (RA),d5

  // マイナスならat4に飛ぶ
  if (cs < 0) goto at4;                                 //  bcs @f

  // 変換テーブルポインタを2バイト進める
  ra += 2;                                              //  addq.w #2,RA

at4:                                                    // @@:
  // 変換テーブルポインタを8バイト進める
  ra += 8;                                              //  addq.w #8,RA

  // 変換テーブルポインタを8バイト進める
  ra += 8;                                              //  addq.w #8,RA

  // ADPCM値がマイナスだっけ？
  btst = rd2 & 0x08;                                    //  btst #3,RD2

  // マイナスならlabel2に飛ぶ
	if (btst != 0) goto label2;                           //  bne 2f      * minus

  // オーバーフローが発生していないかチェック用
  vc = rd + (int16_t)(ra[0] * 256 + ra[1]);

  // 予測値に確定したデルタ値をプラスする
  rd += (int16_t)(ra[0] * 256 + ra[1]);                 //  add.w (RA),RD

  // オーバーフローが発生していないならlabel3に飛ぶ
  if (vc >= -32768 && vc <= 32767) goto label3;         //  bvc 3f

  // オーバーフローが発生してしまったのでマイナスして元に戻す
  rd -= (int16_t)(ra[0] * 256 + ra[1]);                 //  sub.w (RA),RD

  // 上限値を入れておくことにする
  d5 = (int16_t)(ra[32] * 256 + ra[33]);                //  move.w 32(RA),D5

  // もし入れた値が0ならばat5に飛ぶ
  if (d5 == 0) goto at5;                                //  beq @f

  // 0でないならば、変換テーブルポインタを2マイナスしたデルタ値をプラス
  ra -= 2; rd += (int16_t)(ra[0] * 256 + ra[1]);        //  add.w -(RA),RD

  // label3に飛ぶ
  goto label3;                                          //  bra 3f

at5:                                                    // @@:
  // ADPCM値のマイナス符号ビットを立てておく
  rd2 |= 8;                                             //  or.b #$8,RD2

  // デルタ値に特別な値をプラスしておく
  rd += (int16_t)(ra[16] * 256 + ra[17]);               //  add.w 16(RA),RD

  // label3に飛ぶ
  goto label3;                                          //  bra 3f

// マイナスの処理
label2:	                                                // 2:	
  // 変換テーブルポインタを8バイト進める
  ra += 8;                                              //  addq.w #8,RA

  // 変換テーブルポインタを8バイト進める
  ra += 8;                                              //  addq.w #8,RA

  // オーバーフローが発生しているかのチェック用
  vc = rd + (int16_t)(ra[0] * 256 + ra[1]);

  // 予測デルタ値にプラスする
  rd += (int16_t)(ra[0] * 256 + ra[1]);                 //  add.w (RA),RD

  // オーバーフローが発生していないならlabel4に飛ぶ
  if (vc >= -32768 && vc <= 32767) goto label4;         //  bvc 4f

  // オーバーフローが発生してしまったのでマイナスして元に戻す
  rd -= (int16_t)(ra[0] * 256 + ra[1]);                 //  sub.w (RA),RD

  // 下限値を入れておくことにする
  d5 = (int16_t)(ra[16] * 256 + ra[17]);                //  move.w 16(RA),D5

  // 下限値0ならat6に飛ぶ
  if (d5 == 0) goto at6;                                //  beq @f

  // 変換テーブルポインタを2バイト戻してデルタ値を加える
  ra -= 2; rd += (int16_t)(ra[0] * 256 + ra[1]);        //  add.w -(RA),RD

  // label4に飛ぶ
  goto label4;                                          //  bra 4f

at6:                                                    // @@:
  // ADPCM出力値の符号ビットを寝かせる
  rd2 &= 0xf7;                                          //  and.b #$F7,RD2

  // デルタ値に特別な値をプラスしておく、ポインタは動かさない
  rd += (int16_t)(*(ra - 16) * 256 + *(ra - 15));       //  add.w -16(RA),RD

  // label4に飛ぶ
  goto label4;                                          //  bra 4f

label3:                                                 // 3:
  // 変換テーブルポインタを8バイト進める
  ra += 8;                                              //  addq.w	#8,RA

  // 変換テーブルポインタを8バイト進める
  ra += 8;                                              //  addq.w	#8,RA

label4:                                                 // 4:
  // 変換テーブルポインタを8バイト進める
  ra += 8;                                              //  addq.w #8,RA

  // 変換テーブルポインタを8バイト進める
  ra += 8;                                              //  addq.w #8,RA

  // 出力ADPCM値と論理和を取る
  rd2 |= (int16_t)(ra[0] * 256 + ra[1]);                //  or.w (RA),RD2

  // 変換テーブルポインタを8バイト進める
  ra += 8;                                              //  addq.w #8,RA

  // 変換テーブルポインタを8バイト進める
  ra += 8;                                              //  addq.w #8,RA

  // 変換テーブルポインタを進める
  ra += (int16_t)(ra[0] * 256 + ra[1]);                 //  add.w (RA),RA

  // 呼び出し元の変数を書き換える
  *rd_ = rd;
  *ra_ = ra;
  *rd2_ = rd2;
}

//
//  execute ym2608 encoding (respect to adpcmlib.s by Otankonas-san)
//
size_t ym2608_encode_exec(YM2608_ENCODE_HANDLE* ym2608, uint8_t* output_buffer, int16_t* source_buffer, size_t source_buffer_len) {

  size_t source_buffer_ofs = 0;
  size_t output_buffer_ofs = 0;
  size_t output_buffer_len = 0;

  if (ym2608->channels == 1) {

/*
conv_monob:
		subq.l	#1,d0                     * d0 = 16bit PCMデータのバイト数 (1引いておくのはbcc命令の辻褄を合わせるため)

		move.l	pcma_add(a6),a1           * a1 = PCMデータ読み出し元アドレス
		move.l	ra(a6),a3                 * a3 = 変換テーブルポインタ
		move.l	ada_add(a6),a4            * a4 = ADPCMデータ格納先アドレス

		moveq	  #0,d6                     * ADPCM初期値
		move.w	y(a6),d2                  * d2 = 予測値
*/

    uint8_t* a4 = output_buffer;
    uint8_t* a3 = ym2608->ra;
    int16_t d6 = 0;
    int16_t d2 = ym2608->ry;

    while (source_buffer_ofs < source_buffer_len) {

/*
	lpbm:	onef	d2,a3,d6                * 1サンプル d2 = PCMデータ予測値, a3 = テーブルアドレス, d6 = ADPCMデータ(下位4bit)
		lsl.w	#4,d6                       * 得られたコードを4bit左シフトする(ということはa44はbig endian的にADPCMデータが格納されている。MSVと逆)
		onef	d2,a3,d6                    * もう一度エンコードする
		move.b	d6,(a4)+                  * 4bit+4bitの1バイトを(a4)に書き出す
		moveq	#0,d6                       * ADPCM値をリセット
		subq.l	#4,d0                     * ソースPCMデータのカウンタを4バイト減らす = 16bit PCMデータ2つで 1バイトのADPCMデータとなるため
		bcc	lpbm
*/
      onef(source_buffer[ source_buffer_ofs ++ ], &d2, &a3, &d6);
      d6 <<= 4;
      onef(source_buffer[ source_buffer_ofs ++ ], &d2, &a3, &d6);
      a4[ output_buffer_ofs ++ ] = d6;
      d6 = 0;

    }

/*
		move.w	d2,y(a6)                  * 予測値を保存
		move.l	a3,ra(a6)                 * テーブルアドレスを保存
		rts
*/

    ym2608->ry = d2;
    ym2608->ra = a3;

    output_buffer_len = output_buffer_ofs;

  } else {

/*
conv_stereob:
		subq.l	#2,d0                 * d0 = 16bit PCMデータのバイト数 (2引いておくのはbcc命令の辻褄を合わせるため)

		move.l	pcma_add(a6),a1       * a1 = PCMデータ読み出し元アドレス
		move.l	la(a6),a2             * a2 = 変換テーブルポインタ(L)
		move.l	ra(a6),a3             * a3 = 変換テーブルポインタ(R)
		move.l	ada_add(a6),a4        * a4 = ADPCMデータ格納先アドレス

		moveq	#0,d6                   * d6 = ADPCM初期値(L)
		moveq	#0,d7                   * d7 = ADPCM初期値(R)
		move.w	ly(a6),d1             * d1 = 前回予測値(L)
		move.w	ry(a6),d2             * d2 = 前回予測値(R)
*/

    uint8_t* a4 = output_buffer;
    uint8_t* a2 = ym2608->la;
    uint8_t* a3 = ym2608->ra;
    int16_t d6 = 0;
    int16_t d7 = 0;
    int16_t d1 = ym2608->ly;
    int16_t d2 = ym2608->ry;

    while (source_buffer_ofs < source_buffer_len) {

/*
	lpb:	onef	d2,a3,d6
		lsl.w	#4,d6
		onef	d1,a2,d7
		lsl.w	#4,d7
		onef	d2,a3,d6
		onef	d1,a2,d7

		move.b	d6,(a4)+
		move.b	d7,(a4)+
		moveq	#0,d6
		move.b	d6,d7
		subq.l	#8,d0
		bcc	lpb
*/
      onef(source_buffer[ source_buffer_ofs ++ ], &d2, &a3, &d6);
      d6 <<= 4;
      onef(source_buffer[ source_buffer_ofs ++ ], &d1, &a2, &d7);
      d7 <<= 4;
      onef(source_buffer[ source_buffer_ofs ++ ], &d2, &a3, &d6);
      onef(source_buffer[ source_buffer_ofs ++ ], &d1, &a2, &d7);
      a4[ output_buffer_ofs ++ ] = d6;
      a4[ output_buffer_ofs ++ ] = d7;
      d6 = 0;
      d7 = 0;

    }

/*
		move.w	d1,ly(a6)
		move.l	a2,la(a6)
		move.w	d2,ry(a6)
		move.l	a3,ra(a6)
		rts
*/

    ym2608->ly = d1;
    ym2608->la = a2;
    ym2608->ry = d2;
    ym2608->ra = a3;

    output_buffer_len = output_buffer_ofs;

  }

  return output_buffer_len;
}
