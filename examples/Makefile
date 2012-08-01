
CC = gcc
CFLAGS = -c -I.. -O2

LDFLAGS = -L../build -O2
LIBS = -lBeaEngineFork

STATIC_BEA = ../build/libBeaEngineFork.a

all: diself

diself: readcode.o diself.o $(STATIC_BEA)
	$(CC) $(LDFLAGS) -o $@ diself.o readcode.o $(STATIC_BEA)

diself.o: diself.c
	$(CC) $(CFLAGS) -o $@ diself.c

readcode.o: readcode.c
	$(CC) $(CFLAGS) -o $@ readcode.c

testbea.o diself.o readcode.o: readcode.h


clean:
	rm -f *.o diself

