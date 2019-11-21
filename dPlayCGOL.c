#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int dPlayCGOL(int *cGrid, int *fGrid, int row, int col){

int k = 0;
int i = 0;
int numOfNeighbours = 0;

  for (k = 0; k < row; k++) {
    for (i = 0; i< col; i++){

        if(k == 0 && i == 0){
          if(*(cGrid+(k*col)+i+1) == 1){
            numOfNeighbours++;
          }
          if(*(cGrid+((k*col)+1)+i)== 1){
              numOfNeighbours++;
          }
          if(*(cGrid+((k*col)+1)+i+1)==1){
              numOfNeighbours++;
          }
        }
        else if(k == 0 && i == col-1){
          if(*(cGrid+(k*col)+i-1) == 1){
            numOfNeighbours++;
          }
          if(*(cGrid+((k*col)+1)+i)== 1){
              numOfNeighbours++;
          }
          if(*(cGrid+((k*col)-1)+i-1)==1){
              numOfNeighbours++;
          }
        }
        else if(k == row-1 && i == 0){
          if(*(cGrid+(k*col)+i+1) == 1){
            numOfNeighbours++;
          }
          if(*(cGrid+((k*col)-1)+i)== 1){
              numOfNeighbours++;
          }
          if(*(cGrid+((k*col)-1)+i+1)==1){
              numOfNeighbours++;
          }
        }
        else if (k == row-1 && i == col-1){
          if(*(cGrid+(k*col)+i-1) == 1){
            numOfNeighbours++;
          }
          if(*(cGrid+((k*col)-1)+i)== 1){
              numOfNeighbours++;
          }
          if(*(cGrid+((k*col)-1)+i-1)==1){
              numOfNeighbours++;
          }
        }
        else if (k == 0 && (i >0 && i < col-1)){
          if(*(cGrid+(k*col)+i-1) == 1){
            numOfNeighbours++;
          }
          if(*(cGrid+(k*col)+i+1)== 1){
              numOfNeighbours++;
          }
          if(*(cGrid+((k*col)+1)+i)==1){
              numOfNeighbours++;
          }
          if(*(cGrid+((k*col)+1)+i+1)==1){
              numOfNeighbours++;
          }
          if(*(cGrid+((k*col)+1)+i-1)==1){
              numOfNeighbours++;
          }
        }
        else if (k == row-1 && (i >0 && i < col-1)){
          if(*(cGrid+k*col+i-1) == 1){
            numOfNeighbours++;
          }
          if(*(cGrid+(k*col)+i+1)== 1){
              numOfNeighbours++;
          }
          if(*(cGrid+((k*col)-1)+i)==1){
              numOfNeighbours++;
          }
          if(*(cGrid+((k*col)-1)+i+1)==1){
              numOfNeighbours++;
          }
          if(*(cGrid+((k*col)-1)+i-1)==1){
              numOfNeighbours++;
          }
        }
        else if (i == 0 && (k > 0 || k < col-1)){
          if(*(cGrid+(k*col)+i+1) == 1){
            numOfNeighbours++;
          }
          if(*(cGrid+((k*col)-1)+i)== 1){
              numOfNeighbours++;
          }
          if(*(cGrid+((k*col)+1)+i)==1){
              numOfNeighbours++;
          }
          if(*(cGrid+((k*col)+1)+i+1)==1){
              numOfNeighbours++;
          }
          if(*(cGrid+((k*col)-1)+i+1)==1){
              numOfNeighbours++;
          }
        }
        else if (i == col-1 && (k > 0 || k < col-1)){
          if(*(cGrid+(k*col)+i-1) == 1){
            numOfNeighbours++;
          }
          if(*(cGrid+((k*col)-1)+i)== 1){
              numOfNeighbours++;
          }
          if(*(cGrid+((k*col)+1)+i)==1){
              numOfNeighbours++;
          }
          if(*(cGrid+((k*col)+1)+i-1)==1){
              numOfNeighbours++;
          }
          if(*(cGrid+((k*col)-1)+i-1)==1){
              numOfNeighbours++;
          }
        }
        else{
          if(*(cGrid+(k*col)+i+1) == 1){
            numOfNeighbours++;
          }
          if(*(cGrid+((k*col)-1)+i)== 1){
              numOfNeighbours++;
          }
          if(*(cGrid+((k*col)+1)+i)==1){
              numOfNeighbours++;
          }
          if(*(cGrid+((k*col)+1)+i+1)==1){
              numOfNeighbours++;
          }
          if(*(cGrid+((k*col)-1)+i+1)==1){
              numOfNeighbours++;
          }
          if(*(cGrid+((k*col)+1)+i-1)==1){
              numOfNeighbours++;
          }
          if(*(cGrid+((k*col)-1)+i-1)==1){
              numOfNeighbours++;
          }
          if(*(cGrid+(k*col)+i-1) == 1){
            numOfNeighbours++;
          }
        }

        if(*(cGrid+(k*col)+i) == 1){
          if(numOfNeighbours < 2 || numOfNeighbours > 3){
            *(fGrid+(k*col)+i)=0;
          }
          else if(numOfNeighbours > 1 || numOfNeighbours < 4){
            *(fGrid+(k*col)+i)=1;
          }
        }
        else if (*(cGrid+(k*col)+i)==0){

          if(numOfNeighbours == 3){
            *(fGrid+(k*col)+i)=1;
          }
          else{
              *(fGrid+(k*col)+i) = 0;
          }
        }

        numOfNeighbours = 0;
    }
  }
  return(0);
}
