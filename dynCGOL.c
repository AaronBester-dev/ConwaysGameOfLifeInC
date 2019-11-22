#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char * argv[]) {

  char userResponse[200];
  int i = 0;
  int k = 0;
  int j = 0;
  int f = 0;

  int numOfNeighbours;
  int userTickNum = 0;
  int currentTickNum = 0;

  int startCheck = 0;
  int numOfInts = 0;
  int continueCheck = 0;

  if (argc != 5) {
    printf("Incorrect number of command line arguments.\n");
    return (1);
  }

  if ( * argv[3] < * "0" || * argv[3] > * "9") {
    printf("Acceptable row number is any number greater than 0.\n");
    return (-3);
  }
  if ( * argv[4] < * "0" || * argv[4] > * "9") {
    printf("Acceptable column number is any number greater than 0.\n");
    return (-3);
  }

  int row = atoi(argv[3]);
  int col = atoi(argv[4]);
  int currentGrid[row][col];
  int futureGrid[col][col];
  char string[((col * 2) + 2)];
  FILE * f1;

  userTickNum = atoi(argv[2]);

  if (row < 1 || col < 1) {
    printf("Acceptable tick number is any number greater than 0.\n");
    return (4);
  }

  if ((f1 = fopen(argv[1], "r")) != NULL) {
    k = 0;
    while (fgets(string, (col * 2) + 2, f1)) {

      for (f = 0; f < sizeof(string); f++) {
        if (string[f] == * "1" || string[f] == * "0") {
          numOfInts++;
        }
      }

      if (numOfInts != col) {
        printf("File is not the same size as the 2d array!\n");
        return (3);
      }
      numOfInts = 0;

      for (i = 0; i < col; i++) {
        sscanf(string + 2 * i, "%d", & currentGrid[k][i]);

      }
      k++;

    }
    if (k != row) {
      printf("File is not the same size as the 2d array!\n");
      return (3);
    }
  }
  if (f1 == NULL) {
    printf("File not found\n");
    return (2);
  }

  fclose(f1);
  printf(" ");
  for (i = 0; i < col; i++) {
    printf("-");
  }
  printf("\n");
  printf("|");
  for (k = 0; k < row; k++) {
    for (i = 0; i < col; i++) {
      if (currentGrid[k][i] == 1) {
        printf("X");
      } else if (currentGrid[k][i] == 0) {
        printf(" ");
      }

    }
    printf("|\n");
    if (k < row - 1) {
      printf("|");
    }
  }
  printf(" ");
  for (i = 0; i < col; i++) {
    printf("-");
  }
  printf("%d\n", currentTickNum);

  while (startCheck == 0) {
    printf("Start? [y Or n]\n");
    fgets(userResponse, 200, stdin);
    if (userResponse[0] == * "y" || userResponse[0] == * "Y") {
      startCheck = 1;
    } else if (userResponse[0] == * "n" || userResponse[0] == * "N") {
      startCheck = 1;
      return (0);
    } else {
      printf("Only acceptable response is y or n.\n");
    }
  }
  while ((continueCheck == 0)) {

    for (j = 0; j < userTickNum; j++) {

      for (k = 0; k < row; k++) {
        for (i = 0; i < col; i++) {

          if (k == 0 && i == 0) {
            if ((currentGrid[k][i + 1]) == 1) {
              numOfNeighbours++;
            }
            if ((currentGrid[k + 1][i]) == 1) {
              numOfNeighbours++;
            }
            if ((currentGrid[k + 1][i + 1]) == 1) {
              numOfNeighbours++;
            }
          } else if (k == 0 && i == col - 1) {
            if ((currentGrid[k][i - 1]) == 1) {
              numOfNeighbours++;
            }
            if ((currentGrid[k + 1][i]) == 1) {
              numOfNeighbours++;
            }
            if ((currentGrid[k + 1][i - 1]) == 1) {
              numOfNeighbours++;
            }
          } else if (k == row - 1 && i == 0) {
            if (currentGrid[k - 1][i] == 1) {
              numOfNeighbours++;
            }
            if (currentGrid[k][i + 1] == 1) {
              numOfNeighbours++;
            }
            if (currentGrid[k - 1][i + 1] == 1) {
              numOfNeighbours++;
            }
          } else if (k == row - 1 && i == col - 1) {
            if (currentGrid[k - 1][i] == 1) {
              numOfNeighbours++;
            }
            if (currentGrid[k][i - 1] == 1) {
              numOfNeighbours++;
            }
            if (currentGrid[k - 1][i - 1] == 1) {
              numOfNeighbours++;
            }
          } else if (k == 0 && (i > 0 && i < col - 1)) {
            if (currentGrid[k][i - 1] == 1) {
              numOfNeighbours++;
            }
            if (currentGrid[k][i + 1] == 1) {
              numOfNeighbours++;
            }
            if (currentGrid[k + 1][i] == 1) {
              numOfNeighbours++;
            }
            if (currentGrid[k + 1][i + 1] == 1) {
              numOfNeighbours++;
            }
            if (currentGrid[k + 1][i - 1] == 1) {
              numOfNeighbours++;
            }
          } else if (k == row - 1 && (i > 0 && i < col - 1)) {
            if (currentGrid[k][i - 1] == 1) {
              numOfNeighbours++;
            }
            if (currentGrid[k][i + 1] == 1) {
              numOfNeighbours++;
            }
            if (currentGrid[k - 1][i] == 1) {
              numOfNeighbours++;
            }
            if (currentGrid[k - 1][i + 1] == 1) {
              numOfNeighbours++;
            }
            if (currentGrid[k - 1][i - 1] == 1) {
              numOfNeighbours++;
            }
          } else if (i == 0 && (k > 0 || k < col - 1)) {
            if (currentGrid[k + 1][i] == 1) {
              numOfNeighbours++;
            }
            if (currentGrid[k - 1][i] == 1) {
              numOfNeighbours++;
            }
            if (currentGrid[k][i + 1] == 1) {
              numOfNeighbours++;
            }
            if (currentGrid[k + 1][i + 1] == 1) {
              numOfNeighbours++;
            }
            if (currentGrid[k - 1][i + 1] == 1) {
              numOfNeighbours++;
            }
          } else if (i == col - 1 && (k > 0 || k < col - 1)) {
            if (currentGrid[k + 1][i] == 1) {
              numOfNeighbours++;
            }
            if (currentGrid[k - 1][i] == 1) {
              numOfNeighbours++;
            }
            if (currentGrid[k][i - 1] == 1) {
              numOfNeighbours++;
            }
            if (currentGrid[k + 1][i - 1] == 1) {
              numOfNeighbours++;
            }
            if (currentGrid[k - 1][i - 1] == 1) {
              numOfNeighbours++;
            }
          } else {
            if ((currentGrid[k + 1][i]) == 1) {
              numOfNeighbours++;
            }
            if ((currentGrid[k - 1][i]) == 1) {
              numOfNeighbours++;
            }
            if ((currentGrid[k][i - 1]) == 1) {
              numOfNeighbours++;
            }
            if ((currentGrid[k][i + 1]) == 1) {
              numOfNeighbours++;
            }
            if ((currentGrid[k + 1][i - 1]) == 1) {
              numOfNeighbours++;
            }
            if ((currentGrid[k - 1][i - 1]) == 1) {
              numOfNeighbours++;
            }
            if ((currentGrid[k - 1][i + 1]) == 1) {
              numOfNeighbours++;
            }
            if ((currentGrid[k + 1][i + 1]) == 1) {
              numOfNeighbours++;
            }
          }

          if (currentGrid[k][i] == 1) {
            if (numOfNeighbours < 2 || numOfNeighbours > 3) {
              futureGrid[k][i] = 0;
            } else if (numOfNeighbours > 1 || numOfNeighbours < 4) {
              futureGrid[k][i] = 1;
            }
          } else if (currentGrid[k][i] == 0) {

            if (numOfNeighbours == 3) {
              futureGrid[k][i] = 1;
            } else {
              futureGrid[k][i] = 0;
            }
          }

          numOfNeighbours = 0;
        }
      }
      currentTickNum++;

      if (memcmp(futureGrid, currentGrid, sizeof(currentGrid)) == 0) {
        system("clear");
        printf(" ");
        for (i = 0; i < col; i++) {
          printf("-");
        }
        printf("\n");
        printf("|");
        for (k = 0; k < row; k++) {
          for (i = 0; i < col; i++) {
            if (currentGrid[k][i] == 1) {
              printf("X");
            } else if (currentGrid[k][i] == 0) {
              printf(" ");
            }

          }
          printf("|\n");
          if (k < row - 1) {
            printf("|");
          }

        }
        printf(" ");
        for (i = 0; i < col; i++) {
          printf("-");
        }
        printf("%d\n", currentTickNum);
        return (0);
      }

      memcpy(currentGrid, futureGrid, sizeof(currentGrid));
      system("clear");

      printf(" ");
      for (i = 0; i < col; i++) {
        printf("-");
      }
      printf("\n");
      printf("|");
      for (k = 0; k < row; k++) {
        for (i = 0; i < col; i++) {
          if (currentGrid[k][i] == 1) {
            printf("X");
          } else if (currentGrid[k][i] == 0) {
            printf(" ");
          }

        }
        printf("|\n");
        if (k < row - 1) {
          printf("|");
        }

      }
      printf(" ");
      for (i = 0; i < col; i++) {
        printf("-");
      }
      printf("%d\n", currentTickNum);

      system("sleep 0.25");

    }
    printf("Continue? [y or n]\n");
    fgets(userResponse, 200, stdin);
    if (userResponse[0] == * "y" || userResponse[0] == * "Y") {
      continueCheck = 0;
    } else if (userResponse[0] == * "n" || userResponse[0] == * "N") {
      return (0);
    } else {
      printf("Only acceptable response is y or n.\n");
    }
  }
  return (0);
}
