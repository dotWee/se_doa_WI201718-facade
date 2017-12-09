SRC_PATH=./src
SRC_FILES=src/Automobil.cpp src/Frontscheinwerfer.cpp src/Motor.cpp src/main.cpp

OUT_BINARY=Automobil
GCC_FLAGS=-Wall

all: executable run clean

executable:
	g++ ${GCC_FLAGS} -I${SRC_PATH} ${SRC_FILES} -o ${OUT_BINARY}
	chmod +x ${OUT_BINARY}

run:
	./${OUT_BINARY}

clean:
	$(RM) ${OUT_BINARY}
