#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int dPrintGrid(int *cGrid,int currentTickNum,int row, int col){
int k = 0;
int i = 0;

printf(" ----------------------------------------\n");
printf("|");
for (k = 0; k < row; k++) {
for (i = 0; i < col; i++) {
  if (*(cGrid+k*col+i) == 1) {
    printf("X");
  }
  else if (*(cGrid+k*col+i-1)==0){
    printf(" ");
  }

}
printf("|\n");
if (k < row-1) {
  printf("|");
}
}
printf(" ----------------------------------------%d\n",currentTickNum );

return(0);
}
