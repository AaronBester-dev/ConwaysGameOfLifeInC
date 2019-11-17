#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROWS 20
#define COLS 40


int playCGOL(int currentGrid[ROWS][COLS], int futureGrid[ROWS][COLS]){

int k = 0;
int i = 0;
int numOfNeighbours = 0;

  for (k = 0; k < ROWS; k++) {
    for (i = 0; i< COLS; i++){

        if(k == 0 && i == 0){
          if((currentGrid[k][i+1]) == 1){
            numOfNeighbours++;
          }
          if((currentGrid[k+1][i])== 1){
              numOfNeighbours++;
          }
          if((currentGrid[k+1][i+1])==1){
              numOfNeighbours++;
          }
        }
        else if(k == 0 && i == COLS-1){
          if((currentGrid[k][i-1]) == 1){
            numOfNeighbours++;
          }
          if((currentGrid[k+1][i])==1){
              numOfNeighbours++;
          }
          if((currentGrid[k+1][i-1])==1){
              numOfNeighbours++;
          }
        }
        else if(k == ROWS-1 && i == 0){
          if(currentGrid[k-1][i] == 1){
            numOfNeighbours++;
          }
          if(currentGrid[k][i+1]==1){
              numOfNeighbours++;
          }
          if(currentGrid[k-1][i+1]==1){
              numOfNeighbours++;
          }
        }
        else if (k == ROWS-1 && i == COLS-1){
          if(currentGrid[k-1][i] == 1){
            numOfNeighbours++;
          }
          if(currentGrid[k][i-1]==1){
              numOfNeighbours++;
          }
          if(currentGrid[k-1][i-1]==1){
              numOfNeighbours++;
          }
        }
        else if (k == 0 && (i >0 && i < COLS-1)){
          if(currentGrid[k][i-1] == 1){
            numOfNeighbours++;
          }
          if(currentGrid[k][i+1]==1){
              numOfNeighbours++;
          }
          if(currentGrid[k+1][i]==1){
              numOfNeighbours++;
          }
          if(currentGrid[k+1][i+1]==1){
              numOfNeighbours++;
          }
          if(currentGrid[k+1][i-1]==1){
              numOfNeighbours++;
          }
        }
        else if (k == ROWS-1 && (i >0 && i < COLS-1)){
          if(currentGrid[k][i-1] == 1){
            numOfNeighbours++;
          }
          if(currentGrid[k][i+1]==1){
              numOfNeighbours++;
          }
          if(currentGrid[k-1][i]==1){
              numOfNeighbours++;
          }
          if(currentGrid[k-1][i+1]==1){
              numOfNeighbours++;
          }
          if(currentGrid[k-1][i-1]==1){
              numOfNeighbours++;
          }
        }
        else if (i == 0 && (k > 0 || k < COLS-1)){
          if(currentGrid[k+1][i] == 1){
            numOfNeighbours++;
          }
          if(currentGrid[k-1][i]==1){
              numOfNeighbours++;
          }
          if(currentGrid[k][i+1]==1){
              numOfNeighbours++;
          }
          if(currentGrid[k+1][i+1]==1){
              numOfNeighbours++;
          }
          if(currentGrid[k-1][i+1]==1){
              numOfNeighbours++;
          }
        }
        else if (i == COLS-1 && (k > 0 || k < COLS-1)){
          if(currentGrid[k+1][i] == 1){
            numOfNeighbours++;
          }
          if(currentGrid[k-1][i]==1){
              numOfNeighbours++;
          }
          if(currentGrid[k][i-1]==1){
              numOfNeighbours++;
          }
          if(currentGrid[k+1][i-1]==1){
              numOfNeighbours++;
          }
          if(currentGrid[k-1][i-1]==1){
              numOfNeighbours++;
          }
        }
        else{
          if((currentGrid[k+1][i]) == 1){
            numOfNeighbours++;
          }
          if((currentGrid[k-1][i])==1){
              numOfNeighbours++;
          }
          if((currentGrid[k][i-1])==1){
              numOfNeighbours++;
          }
          if((currentGrid[k][i+1])==1){
              numOfNeighbours++;
          }
          if((currentGrid[k+1][i-1])==1){
              numOfNeighbours++;
          }
          if((currentGrid[k-1][i-1])==1){
              numOfNeighbours++;
          }
          if((currentGrid[k-1][i+1])==1){
              numOfNeighbours++;
          }
          if((currentGrid[k+1][i+1])==1){
              numOfNeighbours++;
          }
        }

        if(currentGrid[k][i] == 1){
          if(numOfNeighbours < 2 || numOfNeighbours > 3){
            futureGrid[k][i]=0;
          }
          else if(numOfNeighbours > 1 || numOfNeighbours < 4){
            futureGrid[k][i]=1;
          }
        }
        else if (currentGrid[k][i]==0){
      
          if(numOfNeighbours == 3){
            futureGrid[k][i]=1;
          }
          else{
            futureGrid[k][i] = 0;
          }
        }

        numOfNeighbours = 0;
    }
  }
  return(0);
}
