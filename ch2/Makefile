# Define Macros here
CC = gcc
CFLAGS = -Wall -g

replaceByte.exe: replace-byte.c
	${CC} ${CFLAGS} $? -o $@

showBytes.exe: show-bytes.c
	${CC} ${CFLAGS} $? -o $@

isLittleEndian.exe: is-little-endian.c
	${CC} ${CFLAGS} $? -o $@

intShiftsAreArithmetic.exe: int-shifts-are-arithmetic.c
	${CC} ${CFLAGS} $? -o $@

srl-and-sra.exe: srl-and-sra.c
	${CC} ${CFLAGS} $? -o $@

clean:
	-rm -f -r core core* *.o *exe exe* *dSYM
