
CC = gcc
CFLAGS = -O3 -fPIC -shared
CFLAGS_SO = -fvisibility=hidden -DBUILD_BEA_ENGINE_DLL

SRC = BeaEngine.c
ALLSRCS = $(SRC) $(wildcard beaengine/*.h) $(wildcard Includes/*.[ch]) $(wildcard Includes/instr_set/*.[ch])

all: shared

libBeaEngineFork.so: $(ALLSRCS)
	$(CC) $(CFLAGS) $(CFLAGS_SO) -o $@ $(SRC)
	strip -s $@

shared: libBeaEngineFork.so

clean:
	rm libBeaEngineFork.so

