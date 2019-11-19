all: cgol dcgol

cgol: cgol.o playCGOL.o printGrid.o
	gcc -ansi -Wall cgol.o playCGOL.o printGrid.o -o cgol

dcgol: dcgol.o dPlayCGOL.o dPrintGrid.o
	gcc -ansi -Wall dcgol.o dPlayCGOL.o dPrintGrid.o -o dcgol

dcgol.o: dcgol.c
		gcc -ansi -Wall -c dcgol.c
dPlayCGOL.o: dPlayCGOL.c
		gcc -ansi -Wall -c dPlayCGOL.c
dPrintGrid.o: dPrintGrid.c
			gcc -ansi -Wall -c dPrintGrid.c


cgol.o: cgol.c
	gcc -ansi -Wall -c cgol.c
playCGOL.o: playCGOL.c
	gcc -ansi -Wall -c playCGOL.c
printGrid.o: printGrid.c
		gcc -ansi -Wall -c printGrid.c

clean:
	rm cgol cgol.o printGrid.o playCGOL.o dcgol.o dcgol dPlayCGOL.o dPrintGrid.o
