# a44enc

S44/WAV to A44 encoder for Linux/macOS

Raspberry Pi OSを含むLinuxとmacOS上で動作する、S44/WAV形式16bit PCMデータ to A44(YM2608) ADPCMデータコンバータです。

以下のPCM形式をサポートしています。ファイルの拡張子とWAVヘッダで判別します。

- .s32/.s44/.s48 ... 16bit Raw PCM (big endian) stereo
- .m32/.m44/.m48 ... 16bit Raw PCM (big endian) mono
- .wav ... Windows WAV 16bit Raw PCM (little endian) stereo/mono

---

## How to Install

ソースコードをコンパイルする必要があります。`git` が入っていない場合は導入しておいてください。

Raspberry Piでの例：

        sudo apt-get install git

このリポジトリを clone してビルドします。

        cd
        mkdir oss
        cd oss
        git clone https://github.com/tantanGH/a44enc
        cd a44enc
        cd src
        make

出来上がった `a44enc` をパスの通ったところに置きます。

---

## How to Use

        a44enc [options] <input-file[.sXX|.mXX|.wav]> <output-file(.a44|.n44)>

        options:
          -v[n] ... ボリューム (1-200, default:100)
          -h ... ヘルプメッセージの表示

ボリュームは上げすぎると音割れの原因になるので注意してください。

---

## Special Thanks

- .a44形式(YM2608)のエンコードについては、X68kでの標準ライブラリである Otankonas氏のライブラリと完全互換とするため、氏のadpcmlibライブラリの生成した変換テーブルをそのまま使わせてもらった上で、変換ロジックについてはMC68000のニーモニックをC言語に置き換える形での実装としています。この場を借りてお礼申し上げます。

---

## 変更履歴

- 0.2.0 (2023/06/02) ... 初版
