all:NHammadProject1	run

NHammadProject1: main.o matrixLib.o
	gcc main.o matrixLib.o -o NHammadProject1
main.o:main.c
	gcc -c main.c
matrixLib.o: matrixLib.c matrixLib.h
	gcc -c matrixLib.c
clean:
	del *.o NHammadProject1.exe
run:
	NHammadProject1.exe 400