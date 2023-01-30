#include <stdio.h>
#include <string.h>

typedef struct
 {
   char word[20];
   int occurances;
   int wordLength;
 } wordOccurances;

int main(void)
{
  printf("Please enter the scentance:\n");  //prompts the user to enter a scentance
  char inputScentance[1000];  //creates a variable to store the input scentance
  scanf("%[^\n]s", &inputScentance);  //stores the input scentance in the variable

  wordOccurances wordsInInput[20];  //stores all the unique words in the input scentance along with their length and the number of times they occur
  int uniqueWordCount = 0;  //stores the number of unique words in the scentance so far
  int currentPosition = 0;  //Stores how far along the input scentance the program has traversed

  if ((int) inputScentance[0] != 32)  //block only executed if first character is not a space
  {
    while((int)inputScentance[currentPosition] != 32) //traverses the input scentance until the first space
    {
      wordsInInput[0].word[currentPosition] = inputScentance[currentPosition];  //stores each character of the first word in the word attribute of the first element in the wordsInInput array
      currentPosition++;  //increments the current position so next character can be added
    }
    uniqueWordCount++;  //increments the uniqueWordCount
    wordsInInput[0].word[currentPosition] = '\0'; //appends the word attribute of the first element of the wordsInInput array so it can be outputted as a string
    wordsInInput[0].wordLength = currentPosition; //sets the word length of the first element of the wordsInInput array
    wordsInInput[0].occurances = 1;
    for(int i = 0; i < strlen(wordsInInput[0].word); i++) //Traverses the word to ensure all characters are lower case
    {
      if ((int)wordsInInput[0].word[i] < 90)  //if statement adjusts any uppercase characters to lower case
      {
        wordsInInput[0].word[i] += 32;
      }
    }
  }

  char currentWord[20]; //Variable stores each word when it is tested
  int currentWordLength;  //variable stores the length of the word so it can be appended with \0 to make it a string
  while (currentPosition < strlen(inputScentance))  //Traverses the entire scentance
  {
    if ((int)inputScentance[currentPosition] == 32) //starts a new word after a space
    {
      currentPosition++;  //increments the current position so it allignes with the first letter of the word
      currentWordLength = 0;  //sets word length to 0 for each new word
      while ((((int)inputScentance[currentPosition] > 64) && ((int)inputScentance[currentPosition] < 91)) || (((int)inputScentance[currentPosition] > 96) && ((int)inputScentance[currentPosition] < 123)))  //stops travrsal at end of word
      {
        currentWord[currentWordLength] = inputScentance[currentPosition]; //sets the values of currentWord = word being tested
        currentWordLength++;  //increments current word length so \0 can be appended to make the word a string
        currentPosition++;  //increments currentPosition
      }
      currentWord[currentWordLength] = '\0';  //makes currentWord a string by appending the charactrs in the word with a null character
      for(int i = 0; i < strlen(currentWord); i++)  //traverses each character in the word to ensure they are lower case
      {
        if ((int)currentWord[i] < 90) // if statement adjusts any capitalized characters to lower case
        {
          currentWord[i] += 32;
        }
      }

      int wordAlreadyCounted = 0; // variable used to check if the word being tested has already been accounted for
      for (int i = 0; i < uniqueWordCount; i++) //traverses all words currently in the array "wordsInInput"
      {
        if (strcmp(wordsInInput[i].word, currentWord) == 0) //if the word being tested is the same as one already in the array
        {
          wordsInInput[i].occurances++; //increments occurances attribute for the word if it has ben previously found
          wordAlreadyCounted++; //increments wordAlreadyCounted so we know not to add it to wordsInInput array
          break;  //end the loop
        }
      }
      if (wordAlreadyCounted == 0)  //if the word is not already in the wordsInInput array
      {
        strcpy(wordsInInput[uniqueWordCount].word, currentWord);  //sets the word attribute of the next available element in the array to the word being tested
        wordsInInput[uniqueWordCount].wordLength = currentWordLength;
        wordsInInput[uniqueWordCount].occurances = 1;
        uniqueWordCount++; //increments uniqueWordCount to account for most recently added word.
      }
    }
    else
      currentPosition++;  //increments current position if it is not a space (to account for punctuation)
  }

  for(int i = 0; i < uniqueWordCount; i++)  //traverses the array of unique words, printing each word and the number of times it occurs
  {
    printf("\"%s\" occurs %i times.\n", wordsInInput[i].word, wordsInInput[i].occurances);
  }
}
