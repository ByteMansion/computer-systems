# Define Macros here
CC = gcc
CFLAGS = -Wall -g -std=c11

replaceByte.exe: replace-byte.c
	${CC} ${CFLAGS} $? -o $@

showBytes.exe: show-bytes.c
	${CC} ${CFLAGS} $? -o $@

isLittleEndian.exe: is-little-endian.c
	${CC} ${CFLAGS} $? -o $@

intShiftsAreArithmetic.exe: int-shifts-are-arithmetic.c
	${CC} ${CFLAGS} $? -o $@

srlAndSra.exe: srl-and-sra.c
	${CC} ${CFLAGS} $? -o $@

anyOddOne.exe: any-odd-one.c
	${CC} ${CFLAGS} $? -o $@

oddOnes.exe: odd-ones.c
	${CC} ${CFLAGS} $? -o $@

leftmostOne.exe: leftmost-one.c
	${CC} ${CFLAGS} $? -o $@

intSizeIs32.exe: int-size-is-32.c
	${CC} ${CFLAGS} $? -o $@

lowerOneMask.exe: lower-one-mask.c
	${CC} ${CFLAGS} $? -o $@

rotateLeft.exe: rotate-left.c
	${CC} ${CFLAGS} $? -o $@



clean:
	-rm -f -r core core* *.o *exe exe* *dSYM
