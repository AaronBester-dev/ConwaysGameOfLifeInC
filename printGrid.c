#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROWS 20
#define COLS 40


int printGrid(int currentGrid[ROWS][COLS],int currentTickNum){
int k = 0;
int i = 0;

printf(" ----------------------------------------\n");
printf("|");
for (k = 0; k < ROWS; k++) {
for (i = 0; i < COLS; i++) {
  if (currentGrid[k][i] == 1) {
    printf("X");
  }
  else if (currentGrid[k][i]==0){
    printf(" ");
  }

}
printf("|\n");
if (k < ROWS-1) {
  printf("|");
}
}
printf(" ----------------------------------------%d\n",currentTickNum );

return(0);
}
