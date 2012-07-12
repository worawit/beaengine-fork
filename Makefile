
INC = .

CC = gcc
CFLAGS = -I$(INC) -O3 -fPIC -shared
CFLAGS_SO = -fvisibility=hidden -DBUILD_BEA_ENGINE_DLL

SRC = BeaEngine.c
ALLSRCS = $(SRC) $(wildcard beaengine/*.h) $(wildcard Includes/*.[ch]) $(wildcard Includes/instr_set/*.[ch])

all: shared lite

libBeaEngine.so: $(ALLSRCS)
	$(CC) $(CFLAGS) $(CFLAGS_SO) -o $@ $(SRC)
	strip -s $@

libBeaEngineLite.so: $(ALLSRCS)
	$(CC) $(CFLAGS) $(CFLAGS_SO) -DBEA_LIGHT_DISASSEMBLY -o $@ $(SRC)
	strip -s $@

shared: libBeaEngine.so

lite: libBeaEngineLite.so

clean:
	rm libBeaEngine.so libBeaEngineLite.so

