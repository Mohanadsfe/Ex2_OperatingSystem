CC= gcc
FLAGS= -Wall -g
AR= ar

#make all
all: cmp copy encode decode stshell
.PHONY: clean
#make clean
clean:
	rm -f *.o *.a *.so cmp copy encode decode stshell

stshell: stshell.o
		$(CC) $(FLAGS) -o stshell stshell.o

stshell.o : stshell.c
	$(CC) $(FLAGS) -c stshell.c

copy: copy.o
	$(CC) $(FLAGS) -o copy copy.o
copy.o : copy.c
	$(CC) $(FLAGS) -c copy.c
	
cmp: cmp.o
	$(CC) $(FLAGS) -o cmp cmp.o
cmp.o : cmp.c
	$(CC) $(FLAGS) -c cmp.c


codecA: codecA.so
codecA.so: codecA.o
	$(CC) -shared -o codecA.so codecA.o
codecA.o: codecA.c codec.h
	$(CC) $(FLAGS) -c codecA.c

codecB: codecB.so
codecB.so: codecB.o
	$(CC) -shared -o codecB.so codecB.o
codecB.o: codecB.c codec.h
	$(CC) $(FLAGS) -c codecB.c

encode: encode.o codecA.so codecB.so
	$(CC) $(FLAGS) -o encode encode.o ./codecA.so -ldl
	$(CC) $(FLAGS) -o encode encode.o ./codecB.so -ldl
encode.o: encode.c
	$(CC) $(FLAGS) -c encode.c -ldl

decode: decode.o codecA.so codecB.so
	$(CC) $(FLAGS) -o decode decode.o ./codecA.so -ldl
	$(CC) $(FLAGS) -o decode decode.o ./codecB.so -ldl
decode.o: decode.c
	$(CC) $(FLAGS) -c decode.c -ldl





