all: cgol dynCGOL

cgol: cgol.o playCGOL.o printGrid.o
	gcc -ansi -Wall cgol.o playCGOL.o printGrid.o -o cgol

dynCGOL: dynCGOL.o 
	gcc -ansi -Wall dynCGOL.o  -o dynCGOL

dynCGOL.o: dynCGOL.c
		gcc -ansi -Wall -c dynCGOL.c



cgol.o: cgol.c
	gcc -ansi -Wall -c cgol.c
playCGOL.o: playCGOL.c
	gcc -ansi -Wall -c playCGOL.c
printGrid.o: printGrid.c
		gcc -ansi -Wall -c printGrid.c

clean:
	rm cgol cgol.o printGrid.o playCGOL.o dynCGOL.o dynCGOL
