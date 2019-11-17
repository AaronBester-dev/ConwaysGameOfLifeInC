#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROWS 20
#define COLS 40


int main(int argc, char* argv[]){
char filename[200];
char string[200];
int indexRow = 0;
int indexCol = 0;
int i = 0;
int k = 0;
int tickNum;
int currentGrid[ROWS][COLS];
int futureGrid[ROWS][COLS];
FILE *f1;

if (argc < 3){
  printf("Incorrect number of command line arguments\n");
  return(1);
}

strcpy(filename,argv[1]);

tickNum = atoi(argv[2]);

if((f1 = fopen("diehard.seed","r")) !=NULL){

  while(fgets(string,200,f1)){

     for (i = 0; i < COLS; i++) {
       sscanf(string,"%d",&currentGrid[k][i]);
     }
     k++;
  }
}
if(f1 == NULL){
  printf("File not found\n");
  return(2);
}

fclose(f1);

printf("----------------------------------------\n");
for (k = 0; k < ROWS; k++) {
for (i = 0; i < COLS; i++) {
  if (currentGrid[k][i] == 1) {
    printf("X");
  }
  else{
    printf(" ");
  }
}
printf("\n");
}
printf("----------------------------------------\n");



return(0);
}
