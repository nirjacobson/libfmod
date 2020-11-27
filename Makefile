MODULES = algorithm/algorithm  \
		  algorithm/algorithm0 \
		  algorithm/algorithm1 \
		  algorithm/algorithm2 \
		  algorithm/algorithm3 \
		  algorithm/algorithm4 \
		  algorithm/algorithm5 \
		  algorithm/algorithm6 \
		  algorithm/algorithm7 \
		  envelope \
		  generator \
		  operator \
		  patchfile
OBJECTS = $(foreach MODULE, ${MODULES}, build/${MODULE}.o)
CC      = /home/nir/raspi/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin/arm-linux-gnueabihf-gcc
CCFLAGS = -std=c++11 -O2 -Wall
LIB		= fmod
LIB_FILE = lib${LIB}.so

all: build/ ${LIB_FILE}

${LIB_FILE}: ${OBJECTS}
	${CC} -shared $^ -o ${LIB_FILE}

build/%.o: src/%.cpp
	${CC} -c $< -fPIC -o $@ ${CCFLAGS}

build/:
	mkdir -p build/algorithm

clean:
	rm -rf build
	rm -rf ${LIB_FILE}