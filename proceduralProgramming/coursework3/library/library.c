#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libraryStructures.h"
#include "library.h"
#include "user.h"
#include "librarian.h"
#include "utility.h"

////
// Code module for main library menu and file management
// Reads the book and initialises the problem data

// Initialise library data
// Input:
// bookfile - name of book file
// theLibrary - library data structure

void initLibrary( char *bookFile, Library *theLibrary ) {

  theLibrary->maxBooks = 12;
  theLibrary->maxBorrowed = 4;

  // TO DO :

  // dynamically allocate the bookList array for storing books

  // check the book file exists

  // use the error message and exit the program if it does not

  // open it if it exists

  // use the readBooks function to read in the file and add the book records into the bookList array

  // remember to close the file

  // Initialise the User data

  theLibrary->bookList = (Book *) calloc(theLibrary->maxBooks, sizeof(Book));

  FILE *pointerToBookFile;
  pointerToBookFile = fopen(bookFile, "r");
  if (pointerToBookFile == NULL)
  {
    printf("Error\nBook file does not exist: %s\n",bookFile);
    exit(0);
  }

  theLibrary->numBooks = readBooks(pointerToBookFile, theLibrary->bookList);

  fclose(pointerToBookFile);

  theLibrary->theUser.numBorrowed = 0;

  for (int i = 0; i < theLibrary->maxBorrowed; i++) //sets value of all elements in users "borrowed array to 0"
  {
    theLibrary->theUser.borrowed[i] = 0;
  }

  return;
}

// Read in book file and create the books data structure
// the book file is in a fixed format:
// * book author
// * book title
// * blank line
// Input:
//   books - file pointer to text input file
//   bookList - alocated array for storing Book structures
// Output:
//   numBooks - number of books read

int readBooks( FILE *books, Book *bookList ) {

  int numBooks = 0;

  // TO DO:

  // read from the book file pointer

  // assign values to a Book structure in the bookList array for each complete record

  // read data until the file ends

  int currentChar = getc(books); //currentChar stores the character most recently read from the file
  while(currentChar != -1)  //while we are not at the end of the file
  {
    int stringLength = 0; //records the length of the line so \0 can be appended to the cgharacter array to make it a string
    while ((currentChar != '\n') && (currentChar != -1))  //loop traverses the line and sets the author field of this book structure to thestring on the line
    {
      bookList[numBooks].author[stringLength] = (char)currentChar;
      currentChar = getc(books);
      stringLength++;
    }
    bookList[numBooks].author[stringLength] = '\0'; //appends the line (now stored in author field of this book structure) with \0 to make it a string

    if (currentChar == -1)  //checks to ensure we haven't reached the end of file
      break;

    currentChar = getc(books);  //reads the next character
    stringLength = 0; //resets stringLength as we are starting a new string
    while ((currentChar != '\n') && (currentChar != -1))  //loop traverses the line and sets the book field of this book structure to the string on the line
    {
      bookList[numBooks].title[stringLength] = (char)currentChar;
      currentChar = getc(books);
      stringLength++;
    }
    bookList[numBooks].title[stringLength] = '\0';  //appends the line (now stored in book field of this book structure) with \0 to make it a string

    bookList[numBooks].available = 1; //sets the book just read from the file to "available"

    currentChar = getc(books);  //reads the next character
    if (currentChar == -1)  //checks to ensure we haven't reached the end of file
      break;
    if (currentChar == '\n')  //if we are on the blank line between details
    {
        numBooks++; //increment numBooks
        currentChar = getc(books);  //read the next character
    }

  }

  return numBooks;
}

// Free any allocated library data
// Input:
// theLibrary - library data structure

void exitLibrary( Library *theLibrary ) {

  // TO DO:

  // free the allocated lists
  free(theLibrary->bookList);

  return;
}

// DO NOT ALTER THIS FUNCTION
// Library menu system

void libraryCLI( char *bookFile ) {
    int libraryOpen = 1;
    int option;

    // create the library structure
    Library *theLibrary = (Library *)malloc( sizeof(Library) );

    initLibrary( bookFile, theLibrary );

    while( libraryOpen ){
        printf("\n Main menu options\n 1 User login\n 2 Librarian login\n 3 Exit system\n Choice:");
        option = optionChoice();

        if( option == 1 ) {
            printf("\nUser login\n");
            userCLI( theLibrary );
        }
        else if( option == 2 ) {
            printf("\nLibrarian login\n");
            librarianCLI( theLibrary );
        }
        else if( option == 3 ) {
            libraryOpen = 0;
            printf("\nClosing\n");
        }
        else
            printf("\nUnknown option\n");
    }

    exitLibrary( theLibrary );

    // free the library structure
    free( theLibrary );

    return;
}
