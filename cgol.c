#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROWS 20
#define COLS 40


int main(int argc, char *argv[]){
int printGrid(int currentGrid[ROWS][COLS],int currentTickNum);
int playCGOL(int (currentGrid[ROWS][COLS]),int (futureGrid[ROWS][COLS]));
char filename[200];
char string[200];
char userResponse[200];
int i = 0;
int k = 0;
int userTickNum = 0;
int currentTickNum = 0;
int currentGrid[ROWS][COLS];
int futureGrid[ROWS][COLS];
int startCheck = 0;
int continueCheck = 0;

FILE *f1;

if (argc < 3){
  printf("Incorrect number of command line arguments\n");
  return(1);
}

strcpy(filename,argv[1]);

userTickNum = atoi(argv[2]);

if((f1 = fopen(filename,"r")) !=NULL){
k = 0;
  while(fgets(string,200,f1)){

     for (i = 0; i < COLS; i++) {
       sscanf(string+2*i,"%d", &currentGrid[k][i]);
     }
     k++;
  }
}
if(f1 == NULL){
  printf("File not found\n");
  return(2);
}
printf("%d\n", currentGrid[2][1]);
fclose(f1);

printGrid(currentGrid,currentTickNum);

while(startCheck == 0){
  printf("Start? [Y Or N]\n");
  fgets(userResponse,200,stdin);
  if (userResponse[0] == *"Y"){
    startCheck = 1;
  }
  else if(userResponse[0] == *"N"){
    startCheck = 1;
    return(0);
  }
  else{
    printf("Only acceptable response is Y or N.\n");
  }
}
while((continueCheck == 0)){


for (i = 0;i<userTickNum; i++ ){

  playCGOL(currentGrid,futureGrid);
  currentTickNum++;

if (memcmp(futureGrid,currentGrid,sizeof(currentGrid))== 0){
  return(0);
}

memcpy(currentGrid,futureGrid,sizeof(currentGrid));
system("clear");
printGrid(currentGrid,currentTickNum);

system("sleep 0.25");

}
printf("Continue? [y or n]\n");
fgets(userResponse,200,stdin);
  if(strcmp(userResponse,"y")==0){
    continueCheck=0;
  }
  else if(strcmp(userResponse,"n")==0){
    return(0);
  }
  else{
    printf("Please enter either a y or n\n");
  }
}
return(0);
}