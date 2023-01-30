/************************************************************************
University of Leeds
School of Computing
COMP1711/XJCO1711- Procedural Programming
Coursework 2

I confirm that the following code has been developed and written by me and it is entirely the result of my own work.
I also confirm that I have not copied any parts of this program from another person or any other source or facilitated someone to copy this program from me.
I confirm that I will not publish the program online or share it with anyone without permission of the module leader.

Student Name: Luke Roberts
Student ID:201521685
Email:  sc21lor@leeds.ac.uk
Date Work Commenced:  19/11/21
*************************************************************************/


// ********************************************************************************************************************
// DO NOT CHANGE ANYTHING IN THE FOLLOWING SECTION. IF YOU CHANGE ANYTHING, YOUR CODE WILL FAIL THE AUTOGRADER TESTS.
// However, please read through this section and look at the array declaration and other functions that you will use in your code

#include <stdio.h>
#include <stdlib.h>
#include "tic.h"

// use this 2d array to store the moves of the game, please don't change its name or size
char grid[MaxGrid][MaxGrid]; // this is the grid that will be used to store the moves of the game

int __Check_Count; // do not use this variable, it is for the grader only

// USE THE FOLLOWING FUNCTIONS TO DISPLAY THE CORRECT PROMPTS AND MESSAGES WHEN YOU NEED THEM
// IN YOUR CODE. THIS WILL GUARANTEE THAT YOU PROGRAM'S OUTPUT MATCHES MINE AND FACILITATE AUTOGRADING

// please use this function to prompt the user to enter the grid size to start a new game
void promptEnterGridSize ()
{
  printf ("Enter grid size (3-10):");
}

// please use this function to prompt the user to enter the winning length for the new game
// the parameter represents the maximum winning length for this game
void promptEnterWinLength (int max_win_length)
{
	printf ("Enter winning length (3-%i):", max_win_length);
}

// please use this function to prompt the user to enter the location of the symbol
// this function takes as a parameter the symbol of the player to be prompted
void promptChooseLocation (char symbol)
{
	printf ("Player %c, Choose Location (row,col): ", symbol);
}

// please use this function to show an error message when an index is out of range
void showErrIndex ()
{
  printf ("Index out of range, please re-enter\n");
}

// please use this function to show an error message when a location is already taken
void showErrTaken ()
{
  printf ("This location is already taken\n");
}

// please use this function to show the win message at the end of the game
// this function takes as parameter the symbol of the player who won the game
void showWinMessage (char symbol)
{
	printf ("**************************\n");
	printf ("Player %c has won the game\n", symbol);
	printf ("**************************\n");
}

// please use this function to show a game over (draw) message at the end of the game
void showGameOverMessage ()
{
	printf ("Game over; there are no winners\n");
}

//  please use this function to prompt the user to choose if they want to play back the game (at the end of the game)
void promptPlayBackGame ()
{
  printf ("\nWould you like to play back the recorded game? (y,n)?");
}

// please use this function to prompt the user to answer with n (next) or e (exit)
// to indicate if they want to proceed with the game's replay or exit the program
void promptNextOrExit ()
{
  printf ("Next or Exit (n,e)?");
}

// You will use this function in effPlayerHasWon (see below).
// This function is basically a wrapper around an if statement to compare the content of the cell at row,col with symbol
// However, it also counts the number of times the function is called
// Needless to say again, don't change this function
int check (int row, int col, char symbol)
{
	__Check_Count++;
	if (grid[row][col] == symbol)
		return 1;
	return 0;
}

// Used by the grader to peek at a certain cell in the grid. Don't use this function
int peek (int row, int col)
{
	return grid[row][col];
}


// END OF CODE SECTION THAT SHOULD NOT BE CHANGED
// ************************************************

// --------------------------------------------------------------------------------------------------
// NOW IT IS YOUR TURN, YOU CAN DEFINE ANY OTHER GLOBAL VARIABLES YOU MAY NEED IN YOUR CODE BELOW THIS LINE

typedef struct
{
  char player;
  int row;
  int collum;
} playerTurn; //stores each players turn

int NOturns = 0;  //stores the amount of turns there have been in the game
int gridSize; //stores th size of the game grid


// END OF SECTION FOR DECLARRING ADDITIONAL GLOBAL VARIABLES
// ----------------------------------------------------------

// -------------------------------------------------------------------------------------------------
// NOW, IMPLEMENT THE FOLLOWING FUNCTIONS BY WRITING THE CORRECT CODE IN THE BODIES OF THE FUNCTIONS
// please, don't change the functions' name, return type, or parameters. If you change any of these the grader will crash
// initially these functions contain 'return -99'. Before implementing a function you should delete this statement

// The purpose of this function is to to start a new game
// It is used to initialise everything at the start of a new game
// This functions takes two integer parameters:
// The first parameter (gridsize) represents the size of the grid of the new game, .e.g. 3 for 3x3 game
// The minimum size of the grid is 3 and the maximum size is 10, if the value of the parameter is wrong (less than 3 or > 10)
// the function returns 0 indicating failure to start a new game.
// The second parameter (winlength) is the number of consecutive symbols for the winning case.
// This number cannot be less than 3 or > gridsize (why?), think but don't click :-)
// If the value of the second parameter is invalid (<3 or >gridsize) the function returns 0 (failure)
// If everything is correct the function returns 1 indicating success in initialising the game.
int newGame (int gridsize, int winlength)
{
  if ((gridsize > 10) || (gridsize < 3))  //Ensures the grid size is a valid length
    return 0;
  else
  {
    if ((winlength > gridsize) || (winlength < 3))
      return 0;
    else
      return 1;
  }
}

// The purpose of this function is to show the game's grid on the screen
// The grid should exactly look like the examples in the assignment specification
// Please note the following when you implement the function:
// There is one empty line before the grid to make it stand out from text before it
// The column indices are printed at the top and the first one is indented by exactly one tab (\t); indices are separated by exactly one space
// The row indices are printed at the left followed by exactly one tab (\t)
// The grid symbols are separated by exactly one space
// There is one empty line after the grid to make it stand out from text after it
void showGrid ()
{
  printf("\n"); // prints the first empty line
  putchar('\t');  //ensures there is a tab
  int i = 0;
  while(i < gridSize) //for loop prints the top row
  {
    putchar(i+48);
    putchar(32);
    i++;
  }
  printf("\n");
  printf("\n");
  i = 0;
  while(i < gridSize) //for loop fills out the grid, numbering each row
  {
    printf("%i\t", i);
    int j = 0;
    while(j < gridSize) //prints the values stored in the grid with a space inbetween them
    {
      putchar((int) grid[i][j]);
      putchar(32);
      j++;
    }
    printf("\n"); //starts a new line after each row
    i++;
  }
  printf("\n");

}

// The purpose of this function is to make a move by a player.
// Making a move means putting the player's symbol (letter) in the desired cell
// This function takes 3 parameters. The first two represent indices of the row and column of the cell in which the player
// wants to place their symbol.
// The last parameter is the symbol (letter) of that player.
// A move can only be made if:
// 1- The row and column numbers are valid (not less than 0 or greater than the game's grid size), and
// 2- the cell is not already occupied by another symbol, and
// 3- the symbol is a valid one (X or O).
// If the move can be made (because it is valid), the function makes the move (i.e. puts the symbol in the cell) and returns 1 indicating success.
// otherwise the function returns 0 indicating failure to make the move
// my solution is 4 lines only
int makeMove(int row, int col, char symbol)
{
  if ((row >= 0)&&(row < gridSize)&&(col >= 0)&&(col < gridSize)&&(grid[row][col] == '.') && ((symbol == 'X')||(symbol == 'O')))  //if the entered grid position is valid and the position is empty and the symbold are valid
  {
    grid[row][col] = symbol;  //place the symbol in the requested position
    return 1;
  }
  else
    return 0;
}

// This function is used to check if the board is full, i.e. every location in the grid is filled with either X or O
// it returns 1 if the grid is full, 0 otherwise
// my solution is 5 lines
int boardIsFull()
{
  int i = 0;
  int j;
  while(i < gridSize)  //traverses each valid row
  {
    j = 0;
    while(j < gridSize)  //traverses each valid cell in each row
    {
      if (grid[i][j] == '.')  //if any cells don't have a symbol
        return 0;
      j++;
    }
    i++;
  }
  return 1; //return 1 if every cell has a symbol
}


// This function is used to check if there is any horizontal line in the grid that contains a consecutive sequence of the same symbol
// It can be used to check that a player has won the game by forming a horizontal run of their own symbol
// The function returns 1 if the player given by parameter symbol has formed a horizontal line of the required length otherwise it returns 0
// The first parameter is the player's symbol (X or O), and the second parameter is the required length (number of cells) of consecutive symbols
// If any of the parameters is invalid the function should return -1 indicating failure to make a move
int checkHorizontal (char symbol, int length)
{
  if (((symbol != 'X') && (symbol != 'O')) || (length > gridSize) || (length < 3))
    return -1;  //return -1 if any parameters are invalid

  int i = 0;
  int j;
  while (i < gridSize)  //traverses every row
  {
    j = 0;
    while (j <= gridSize - length)  //checks every cell that could be the left side of a winning horizontal line
    {
      int score = 0; //stores the number of consecutive horizontal symbols from each position
      while (score < length)  //loops untill it wins
      {
        if (grid[i][j + score] == symbol)
        {
          score++;
        }
        else
          break;  //stops the loop if the line is not a winning line
      }
      if (score == length)
        return 1; //returns 1 if a winning horizontal is found
      j++;
    }
    i++;
  }
  return 0;
}


// This function is used to check if there is any vertical line in the grid that contains a consecutive sequence of the same symbol
// It can be used to check that a player has won the game by forming a vertical run of their own symbol
// The function returns 1 if the player given by parameter symbol has formed a vertical line of the required length otherwise it returns 0
// The first parameter is the player's symbol (X or O), and the second parameter is the required length (number of cells) of consecutive symbols
// If any of the parameters is invalid the function should return -1 indicating failure to make a move
int checkVertical (char symbol, int length)
{
  if (((symbol != 'X') && (symbol != 'O')) || (length > gridSize) || (length < 3))
    return -1;  //returns -1 if any arguments are invalid

  int i = 0;
  int j;
  while(i <= gridSize - length)  //traverses each row that could be the top of a winning collum
  {
    j = 0;
    while(j < gridSize)  //traverses each cell in a row
    {
      int score = 0; //stores the number of consecutive horizontal symbols from each position
      while (score < length) //loop until a win is confirmed
      {
        if (grid[i + score][j] == symbol)
          score++;
        else
          break;  //breaks loop if collum won't win
      }
      if (score == length)
        return 1; //returns 1 if a winning collum was found
      j++;
    }
    i++;
  }
  return 0;
}

// This function is used to check if there is any diagonal line in the grid that contains a consecutive sequence of the same symbol
// A diagonal line runs from higher left to lower right (or vice versa). Note that there are more than one diagonal line in a grid.
// It can be used to check that a player has won the game by forming a diagonal run of their own symbol
// The function returns 1 if the player given by parameter symbol has formed a diagonal line of the required length otherwise it returns 0
// The first parameter is the player's symbol (X or O), and the second parameter is the required length (number of cells) of consecutive symbols
// If any of the parameters is invalid the function should return -1 indicating failure to make a move
int checkDiagonals (char symbol, int length)
{
  if (((symbol != 'X') && (symbol != 'O')) || (length > gridSize) || (length < 3))
    return -1;  //return -1 if any parameter is invalid

  int i = 0;
  int j;
  while(i <= gridSize - length)  //traverses each row that could be the end of a diagonal
  {
    j = 0;
    while(j <= gridSize - length)  //traverses each cell that could be the end of a diagonal in a row
    {
      int score = 0; //stores the number of consecutive horizontal symbols from each position
      while (score < length)  //loop until we find a winning line
      {
        if (grid[i + score][j + score] == symbol)
          score++;
        else
          break;  //move onto next cell if we haven't found a winning row
      }
      if (score == length)
        return 1; //return 1 if we have found a winning line
      j++;
    }
    i++;
  }
  return 0;
}

// This function is used to check if there is any anti-diagonal (reverse diagonal) section in the grid that contains a consecutive sequence of the same symbol
// An anti-diagonal line runs from higher right to lower left (or vice versa). Note that there are more than one anti-diagonal line in a grid.
// It can be used to check that a player has won the game by forming an anti-diagonal run of their own symbol
// The function returns 1 if the player given by parameter symbol has formed an anti-diagonal line of the required length otherwise it returns 0
// The first parameter is the player's symbol (X or O), and the second parameter is the required length (number of cells) of consecutive symbols
// If any of the parameters is invalid the function should return -1 indicating an failure to make a move
int checkAntiDiagonals (char symbol, int length)
{
  if (((symbol != 'X') && (symbol != 'O')) || (length > gridSize) || (length < 3))
    return -1;  //return -1 if any parameters are invalid

  int i = 0;
  int j;
  while(i <= gridSize - length)  //traverses each row that could be the end of an antidiagonal
  {
    j = length - 1;
    while(j < gridSize) //traverses each cell that could be the end of an antidiagonal in a row
    {
      int score = 0; //stores the number of consecutive horizontal symbols from each position
      while (score < length)  //while we haven't won
      {
        if (grid[i + score][j - score] == symbol) //if the adjacent anti-diagonal symbol is the same as the symbol being checked for
          score++;
        else
          break;  //move onto next cell if we havent got a winning line
      }
      if (score == length)
        return 1; //if the amount of anti-diagonally adjacent symbols = the win length then return 1
      j++;
    }
    i++;
  }
  return 0;
}


// This function is used to check if a player has won the game by forming a horizontal, vertical, diagonal, or anti-diagonal line
// of the required length. This function should use the above four functions (checkHorizontal, checkVertical, checkDiagonals, and checkAntiDiagonals)
// to determine if the player has one
// The function returns 1 if the player given by symbol has won, and 0 if the player has not won
// If any of the parameters is invalid the function returns -1 indicating failure to check
// my solution is 5 lines
int playerHasWon (char symbol , int length)
{
  if (((symbol != 'X') && (symbol != 'O')) || (length > MaxGrid) || (length < 3))
    return -1;  //return -1 if any parameters are invalid
  if ((checkHorizontal(symbol, length) == 1) || (checkVertical(symbol, length) == 1) || (checkDiagonals(symbol, length) == 1) || (checkAntiDiagonals(symbol, length) == 1))
    return 1; //if the player has won in any direction, return 1
  else
    return 0; //return 0 if the player has not won
}

// Do you think the above function (playerHasWon) is the most efficient way of detecting a win?
// Do we do this as humans when we play the game?
// The answer is NO.
// The purpose of this function is to implement a much more efficient version of the playerHasWon function
// The function takes four parameters.
// The first two parameters represent the location (row, and col) of the last move made
// by a player.
// The second parameter is the symbol of that player.
// The last parameter is the length of the winning line
// We will assess the efficiency of the function by the number of times we need to check the contents of a cell.
// To count the number of checks, I have prepared a function called check - see the top of this file - that you have
// to use instead of an if statement when you need to compare the contents of a cell to a given symbol.
//
// This function returns 1 if the player has formed a winning line immediately after placing their symbol in the
// cell given by row,col. If the player did not win, the function returns 0
// It returns -1 if any of the parameters have an invalid value.
int effPlayerHasWon (int row, int col, char symbol , int length)
{
  if (((symbol != 'X') && (symbol != 'O')) || (row > gridSize) || (col > gridSize) || (length > gridSize) || (row < 0) || (col < 0) || (length < 3))
    return -1;

  int score = 1;
  //chacking horizontally
  int i = col + 1;
  while (i < gridSize)
  {
    if (check(row, i, symbol) == 0)
      break;
    else
      score++;
    i++;
  }
  i = col - 1;
  while (i >= 0)
  {
    if (check(row, i, symbol) == 0)
      break;
    else
      score++;
    i--;
  }
    if (score >= length)
      return 1;
    else
      score = 1;

  //checking vertically
  i = row + 1;
  while (i < gridSize)
  {
    if (check(i, col, symbol) == 0)
      break;
    else
      score++;
    i++;
  }
  i = row - 1;
  while (i >= 0)
  {
    if (check(i, col, symbol) == 0)
      break;
    else
      score++;
    i--;
  }
  if (score >= length)
    return 1;
  else
    score = 1;

  //checking Diagonally
  i = row + 1;
  int j = col + 1;
  while ((i < gridSize) && (j < gridSize))
  {
    if (check(i, j, symbol) == 0)
      break;
    else
      score++;
    i++;
    j++;
  }
  i = row - 1;
  j = col - 1;
  while ((i >= 0) && (j >= 0))
  {
    if (check(i, j, symbol) == 0)
      break;
    else
      score++;
    i--;
    j--;
  }
  if (score >= length)
    return 1;
  else
    score = 1;

  //checking anti-diagonally
  i = row + 1;
  j = col - 1;
  while ((i < gridSize) && (j >= 0))
  {
    if (check(i, j, symbol) == 0)
      break;
    else
      score++;
    i++;
    j--;
  }
  i = row - 1;
  j = col + 1;
  while((i >= 0) && (j < gridSize))
  {
    if (check(i, j, symbol) == 0)
      break;
    else
      score++;
    i--;
    j++;
  }
  if (score >= length)
    return 1;
  else
    score = 1;

  return 0;

}

// IF YOU NEED ADDITIONAL FUNCTIONS YOU CAN DEFINE THEM BELOW THIS LINE
//----------------------------------------------------------------------






// DON'T CHANGE THE FOLLOWING 3 LINES
#ifndef TEST
int  main (int argc, char* argv[])
{
	// ENTER THE CODE OF YOUR main FUNCTION BELOW
  int winLength;
  promptEnterGridSize ();
  scanf("%i", &gridSize);
  promptEnterWinLength(gridSize);
  scanf("%i", &winLength);
  while (newGame(gridSize, winLength) != 1)
  {
    winLength = 0;
    gridSize = 0;
    promptEnterGridSize ();
    scanf("%i", &gridSize);
    promptEnterWinLength(gridSize);
    scanf("%i", &winLength);
  }
  playerTurn* turnsInGame;  //creates an array of playerTurn to store each players turn
  turnsInGame = (playerTurn *) calloc(gridSize * gridSize, sizeof(playerTurn)); //sets the size of turns InGameto the number og grid spaces

  int i = 0;
  int j;
  while (i < gridSize)  //traverses the grid rows
  {
    j = 0;
    while (j < gridSize)  //traverses each element in each grid row
    {
      grid[i][j] = '.'; //initialises each relevent element in the grid to .
      j++;
    }
    i++;
  }

  showGrid();

  while(NOturns < gridSize * gridSize)
  {
    if (NOturns % 2 == 1) //determines which player's turn it is
      turnsInGame[NOturns].player = 'O';
    else
      turnsInGame[NOturns].player = 'X';

    char playerInput[4];  //stores the user input

    while (1) //infinite loop to get the players
    {
      promptChooseLocation(turnsInGame[NOturns].player);  //prompts that player to enter where they would like to place their character
      scanf("%s", playerInput);
      int row = (int) playerInput[0] - 48;  //uses the input string to get the row
      int collum = (int) playerInput[2] - 48; //uses the input string to get the collum
      if (makeMove(row, collum, turnsInGame[NOturns].player) == 0)  //if the input was invalid
      {
        if ((row < 0) || (row >= gridSize) || (collum < 0) || (collum >= gridSize)) //if the grid index was out of range
        {
          showErrIndex();
          continue; //prompt user again to enter a location
        }
        else
        {
          if (grid[row][collum] != '.')
          {
            showErrTaken();
            continue; //prompt user again to enter a location
          }
        }
      }
      turnsInGame[NOturns].row = row;
      turnsInGame[NOturns].collum = collum;
      break;  //ends loop if input was valid
    }

    showGrid(); //displays the grid with the most recent move
    if (effPlayerHasWon(turnsInGame[NOturns].row, turnsInGame[NOturns].collum ,turnsInGame[NOturns].player, winLength)  == 1)  //checks if the last move was a winning move
    {
      showWinMessage(turnsInGame[NOturns].player);  //displays the win message if a player has won
      break;  //ends the game if a player has won
    }
    if (boardIsFull() == 1) //if the board is full and no more moves can take place
    {
      showGameOverMessage();  //the draw message is shown
      break;  //the game has ended
    }
    NOturns++;  //increment to the next players turn if they can still go
  }

  promptPlayBackGame(); //asks the user if they want to view the game they just played
  char playBack;  //used to store the users response
  scanf(" %c", &playBack);  //gets the users input to the prompt
  if (playBack == 'y')  //if the user does want to see the playback
  {
    int a = 0;
    int b;
    while (a < gridSize)
    {
      b = 0;
      while (b < gridSize)
      {
        grid[a][b] = '.'; //reset the grid
        b++;
      }
      a++;
    }
    showGrid(); //display the original grid before the game started
    int currentReplayTurn = 0;
    while(currentReplayTurn <= NOturns) //for every move made by either player in the game
    {
      promptNextOrExit(); //ask the user if they want to see the next move
      char nextOrExit;  //used to store the users response
      scanf(" %c", &nextOrExit);  //gets the users response
      if (nextOrExit == 'e')  //if the user wants to exit
        break;  //end the playback
      makeMove(turnsInGame[currentReplayTurn].row, turnsInGame[currentReplayTurn].collum, turnsInGame[currentReplayTurn].player); //make the relevent move, adding relevent symbol to the correct grid position
      showGrid(); //display the grid with the move made
      currentReplayTurn++;
    }
  }



  free(turnsInGame);



// DON'T CHANGE THE FOLLOWING 3 LINES
  return 0;
}
#endif
// DON'T WRITE ANYTHING BELOW THIS LINE
