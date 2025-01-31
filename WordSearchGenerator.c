#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

//Maximum allotted size of the word search
#define MAX 20;


/*
A function that increments the positions of the column and row when searching for positions for each word
*/
void incrementingPosition(int *colPos, int *rowPos, int *ogColPos, int *ogRowPos, bool *incremented, int *directionsTested, int *size, const char *word){
	//if the positions have been incremented once before and the col and row positions have cycle through all positions
	if(*incremented == true && ( *colPos == *ogColPos && *rowPos == *ogRowPos)){
		//All options have been checked.
		//Current puzzle

		
		printf("The program has failed because the word %s could not be placed\n", word);
		exit(1);

	//Increment the positions otherwise
	}else{
		if(*colPos < *size){
			*colPos = *colPos + 1;
		}else if(*rowPos < *size){
			*rowPos = *rowPos + 1;
			*colPos = 0;
		}else if(*rowPos == *size && *colPos == *size){
			*rowPos = 0;
			*colPos = 0;
		}
		

	}

	*directionsTested = 0;
	//Debugging
  	//printf("INSIDE INCEMENTING! Column Position: %d\n", *colPos);
  	//printf("INSIDE INCREMENTING! Row Position: %d\n", *rowPos);

}

/*
Function used to print the ending puzzle
*/
void printTable(int size, char table[size][size]){
	for(int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			printf("%3c", table[i][j]);
		}
		printf("\n");
	}
}

/*
Function to determine a random char to put into the puzzle
*/
char randomChar(){
	//generating a random number between 0 and 26
	//printf("Inside function\n");
	int num = rand() % 26;
	if(num == 0){
		return 'a';
	}
	if(num == 1){
		return 'b';
	}
	if(num == 2){
		return 'c';
	}
	if(num == 3){
		return 'd';
	}
	if(num == 4){
		return 'e';
	}
	if(num == 5){
		return 'f';
	}
	if(num == 6){
		return 'g';
	}
	if(num == 7){
		return 'h';
	}
	if(num == 8){
		return 'i';
	}
	if(num == 9){
		return 'j';
	}
	if(num == 10){
		return 'k';
	}
	if(num == 11){
		return 'l';
	}
	if(num == 12){
		return 'm';
	}
	if(num == 13){
		return 'n';
	}
	if(num == 14){
		return 'o';
	}
	if(num == 15){
		return 'p';
	}
	if(num == 16){
		return 'q';
	}
	if(num == 17){
		return 'r';
	}
	if(num == 18){
		return 's';
	}
	if(num == 19){
		return 't';
	}
	if(num == 20){
		return 'u';
	}
	if(num == 21){
		return 'v';
	}
	if(num == 22){
		return 'w';
	}
	if(num == 23){
		return 'x';
	}
	if(num == 24){
		return 'y';
	}
	if(num == 25){
		return 'z';
	}
	return 'a';


}


/*------------------------------------------------------------------------------------------------------------------------*/


int main(int argc, char *argv[])
{
  	//TODO: Delete before turnning in
  	//printf("Beginning of the Word Search Generator\n");

  /*
  	Declaring variables
  */
	//Variables that are used for iterating
	int i, j, x, r, y;
  	int size, charLength, directionsTested;
  	bool fit, repeat, incremented;
	
	//debugging
	// printf("Variables initialized\n");

    //Setting size = to given size of word search
    size = atoi(argv[1]);

	//Used for debuggin
	//printf("Size created: %d\n", size);
    //Used for debugging
    // printf("%d\n", size);


    //Creating the table with the size
    char table[size][size];

    //Creating a 2D array
    for (i = 0; i < size; i++){
      for (j = 0; j < size; j++){
        table[i][j] = '1';
      }
    }

	//Debugging
	//printf("Table Created\n");

    //srand
    srand(time(NULL));
    

/*Beginning iterations ---------------------------------------------------------------------------------------------------------------------------------*/ 
	

	//iterating through each word provided
	i = 2;
	while(i < argc){

		//create random number for the column location
		int colPos = 0 + rand() % (size - 0 + 1);
		//saving original position
		int ogColPos = colPos;
		//debugging
		//printf("Column Position: %d\n", colPos);

		//Creating random number for the row location
		int rowPos = 0 + rand() % (size - 0 + 1);
		//saving original position
		int ogRowPos = rowPos;
		//debugging
		//printf("Row Position: %d\n", rowPos);

		//Getting the length of the word
		charLength = strlen(argv[i]);
		//Debugging
		//printf("Character Length of current word: %d\n", charLength);

		//Turning word into an array pf characters
		char *str = argv[i];

		//Generate a random number for the direction
		int direction = 0 + rand() % (3 - 0 + 1);
		directionsTested = 0;
		repeat = true;
		incremented = false;

/*-Entering next loop---------------------------------------------------------------------------------------------------------------------------*/


		//Loop that will continue until word has position or it is determined their is no valid position
		while(repeat){


/*Diagonal Down ---------------------------------------------------------------------------------------------------------------------------*/


			//If direction number is 0 or the first option has alreayd been checked
			if(direction == 0 || (directionsTested > 0 && directionsTested < 4)){
				//Debugging
				//printf("Diagonal Down\n");

				//Check if their is enough character space for the word
				if(charLength < size - colPos && charLength <= size - rowPos){


					//Debugging
					//table[1][1] = 'w';


					r = 0;
					x = colPos;
					y = rowPos;
					while (r < charLength){
						if(table[x][y] != '1' && table[x][y] != str[r]){
							fit = false;
							r = charLength;
						}else{
							x++;
							y++;
							r++;
							fit = true;
						}
					}

	
					//If the position is valid
					if(fit == true){
						//Place word in position
						r = 0;
						x = colPos;
						y = rowPos;
						while (r < charLength){
							table[x][y] = str[r];
							x++;
							y++;
							r++;
						}

						//Position of word was found. Leave the loop
						repeat = false;
						//Debugging
						//printf("\nSuccess\n\n");
						break;

					//If no valid position was found due to letters
					}else{
						if(directionsTested == 3){
							//Increment the positions
							//printTable(size, table);

							incrementingPosition(&colPos, &rowPos, &ogColPos, &ogRowPos, &incremented, &directionsTested, &size, str);

							//Debugging
							//printf("Column Position Updated: %d\n", colPos);
							//printf("Row Position Updated: %d\n", rowPos);
							incremented = true;

						}else{
							directionsTested++;
							//printf("Directions tested Increased: %d\n", directionsTested);

						}
					}
				//If location is invalid due to lack of space
				}else{
					//printf("Invalid: Diagonal-Down, Space\n");

					//If all directions have been tested
					if(directionsTested == 3){
						//Increment the positions

						//printTable(size, table);
						incrementingPosition(&colPos, &rowPos, &ogColPos, &ogRowPos, &incremented, &directionsTested, &size, str);

						//Debugging
						//printf("Column Position Updated: %d\n", colPos);
						//printf("Row Position Updated: %d\n", rowPos);
						incremented = true;
						

					//If there are more directions that need to be tested
					}else{
						directionsTested++;
						//printf("Directions tested Increased: %d\n", directionsTested);

					}
				}
			}

/*Direction Diagonal Up -----------------------------------------------------------------------------------------------------------------------------------------------*/

			//if the direction number was 1 or the original direction has already been checked
			if(direction == 1 || (directionsTested > 0 && directionsTested < 4)){
				//The direction is diagonal up
				//Debugging
				//printf("Diagonal Up\n");

				//check if the word will fit
				if (charLength <= size - colPos && charLength <= size - rowPos){
					//if the word fits we will check if their are any letters in the way
					fit = true;
					r = 0;
					x = colPos;
					y = rowPos;
					while (r < charLength){
						if(table[x][y] != '1' && table[x][y] != str[r]){
							fit = false;
							r = charLength;
						}else{
							r++;
							x--;
							y--;
						}
					}

					//printf("R: %d\n", r);

					//If the position is valid
					if(fit == true){
						//Fill word
						r = 0;
						x = colPos;
						y = rowPos;
						while(r < charLength){
							table[x][y] = str[r];
							r++;
							x--;
							y--;
						}
						//Word was given a spot so exit the loop
						repeat = false;
						//Debugging
						//printf("\nSuccess\n\n");

						break;

					//If the position is not valid because of letters
					}else{
						//Debugging
						//printf("Invalid: Diagonal-Up, Letters\n");
						//If all directions have been tested
						if(directionsTested == 3){
							//Increment the positions
							//printTable(size, table);

							incrementingPosition(&colPos, &rowPos, &ogColPos, &ogRowPos, &incremented, &directionsTested, &size, str);

							//Debugging
							//printf("Column Position Updated: %d\n", colPos);
							//printf("Row Position Updated: %d\n", rowPos);
							incremented = true;
						

						//If there are more directions that need to be tested
						}else{
							directionsTested++;
							//printf("Directions tested Increased: %d\n", directionsTested);

						}
					}

				//If the work will not fit
				}else{
					//Debugging
					//printf("Invalid: Diagonal-Up, Spcae\n");

					//All directions where tested
					if(directionsTested == 3){
						//Increment the positions
						//printTable(size, table);

						incrementingPosition(&colPos, &rowPos, &ogColPos, &ogRowPos, &incremented, &directionsTested, &size, str);

						//Debugging
						//printf("Column Position Updated: %d\n", colPos);
						//printf("Row Position Updated: %d\n", rowPos);
						incremented = true;

						

					//More directions can be tested
					}else{
						directionsTested++;
						//debuggin
						//printf("Directions Tested Updated: %d\n", directionsTested);
					}
				}
			}

/*Direction Rightward -----------------------------------------------------------------------------------------------------*/

			if(direction == 2 || (directionsTested > 0 && directionsTested < 4)){
				//Direction is rightward
				//debugging
				//printf("Rightward\n");

				//If the word will fit
				if(charLength <= size - colPos){
					//check for letters
					r = 0;
					x = colPos;
					while(r < charLength){
						if(table[rowPos][x] != '1' && table[rowPos][x] != str[r]){
							fit = false;
							r = charLength;
						}else{
							fit = true;
							r++;
							x++;
						}
					}

					//printf("R: %d\n", r);


					//If the spot is valid
					if(fit == true){
						//Add the word
						r = 0;
						x = colPos;
						while(r < charLength){
							table[rowPos][x] = str[r];
							r++;
							x++;
						}
						repeat = false;
						//Debugging
						//printf("\nSuccess\n\n");
						break;


					//If the spot is not valid due to letters
					}else{
						//debugging
						//printf("Invalid: Righward, Letters\n");
						//All directions where tested
					if(directionsTested == 3){
						//Increment the positions
						//printTable(size, table);

						incrementingPosition(&colPos, &rowPos, &ogColPos, &ogRowPos, &incremented, &directionsTested, &size, str);

						//Debugging
						//printf("Column Position Updated: %d\n", colPos);
						//printf("Row Position Updated: %d\n", rowPos);
						incremented = true;

						

					//More directions can be tested
					}else{
						directionsTested++;
						//debuggin
						//printf("Directions Tested Updated: %d\n", directionsTested);
					}
					}

				//If thw work will not fit due to space
				}else{

					//Debugging
					//printf("Invalid: Righward, Space\n");

					//If all the directions have been tested
					if(directionsTested == 3){
						//Increment the positions
						//printTable(size, table);

						incrementingPosition(&colPos, &rowPos, &ogColPos, &ogRowPos, &incremented, &directionsTested, &size, str);

						//Debugging
						//printf("Column Position Updated: %d\n", colPos);
						//printf("Row Position Updated: %d\n", rowPos);
						incremented = true;
						

					//More directions to be tested
					}else{
						//increment 
						directionsTested++;
						//printf("Directions tested Updated: %d\n", directionsTested);

					}

				}

			}

/*Direction Downward --------------------------------------------------------------------------------------------------------------------*/

			//Downward Direction
			if (direction == 3 || (directionsTested > 0 && directionsTested < 4)){
				//Debugging
				//printf("Downward\n");

				//Check if the work will fit
				if(charLength <= size - rowPos){
					//Check for letters
					r = 0;
					x = rowPos;
					while(r < charLength){
						if(table[x][colPos] != '1' && table[x][colPos] != str[r]){
							fit = false;
							r =charLength;
						}else{
							fit = true;
							r++;
							x++;
						}
					}

					//printf("R: %d\n", r);


					//If the position is valid
					if(fit){
						//Fill in word
						r = 0;
						x = rowPos;
						while(r < charLength){
							table[x][colPos] = str[r];
							r++;
							x++;
						}
						//Word was place so leave loop
						repeat = false;

						//Debugging
						//printf("\nSuccess\n\n");
						break;


					//If the word did not fit due to letter
					}else{
						//debugging
						//printf("Invalid: Downward. Letters\n");
						//All directions where tested
					if(directionsTested == 3){
						//Increment the positions
						//printTable(size, table);

						incrementingPosition(&colPos, &rowPos, &ogColPos, &ogRowPos, &incremented, &directionsTested, &size, str);

						//Debugging
						//printf("Column Position Updated: %d\n", colPos);
						//printf("Row Position Updated: %d\n", rowPos);
						incremented = true;

						

					//More directions can be tested
					}else{
						directionsTested++;
						//debuggin
						//printf("Directions Tested Updated: %d\n", directionsTested);
					}
					}

				//If word does not fit due to space
				}else{


					//And all directions have been used
					if (directionsTested == 3){
						//Increment the positions
						//printTable(size, table);

						incrementingPosition(&colPos, &rowPos, &ogColPos, &ogRowPos, &incremented, &directionsTested, &size, str);

						//Debugging
						//printf("Column Position Updated: %d\n", colPos);
						//printf("Row Position Updated: %d\n", rowPos);
						incremented = true;
						

					//If more directions to be checked
					}else{
						//incremenmt
						directionsTested++;
						//debugging
						//printf("Directions updated again: %d\n", directionsTested);

					}

				}

			}

		}


	i++;
	}




/*Filling in all remaining empty spots of the puzzle with randome letters------------------------------------------------------------------------------------------------------------------*/

//printf("Filling in letters\n");
//Loop through the table
for( i = 0; i < size; i++){
	for(j = 0; j < size; j++){
		if(table[i][j] == '1'){
			//Generate a random char
			table[i][j] = randomChar();
		}
	}
}




/*Generating puzzle and printing thw word list ---------------------------------------------------------------------------------------------------------------------------------------*/


  //Once the puzzle generation is complete, print the puzzle and word list
  

  //debugging
  //printf("Printing the Puzzle\n");


  //printing the puzzle
  for (i = 0; i < size; i++){
    for (j = 0; j < size; j++){
      printf("%3c", table[i][j]);
    }
    printf("\n");
  }


  //printing the words
  printf("Word List\n");
  for (i = 2; i < argc; i++){
    printf("%s\n", argv[i]);
  }


}
