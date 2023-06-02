TARGET = a44enc

CC = gcc
LD = gcc

CFLAGS = -O2
LDFLAGS =
LIBS =

OBJS = raw_decode.o wav_decode.o ym2608_encode.o ym2608_table.o main.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	-rm -f *.o $(TARGET)