
// Name:
// Username:
// Date started:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libraryStructures.h"
#include "library.h"

////
// Code module for main()
// main function takes command line arguments
// and opens the library menu
// Input: book data filename via command line
// Usage: ./library books.txt

int main( int argc, char **argv )
{
    char bookFile[40];

    //TO DO :

    // check that correct number of command line arguments are entered
    if (argc != 2)
    {
    // use the error message
      printf("Error\nExpected use: ./library books.txt\n");
    // exit the application if there is an error
      exit(0);
    }
    // assign command line value to filename string
    int i = 0;  //used to travers the string command line argument
    while (argv[1][i] != '\0')  //traverses each character of the command line argument
    {
      bookFile[i] = argv[1][i];
      i++;
    }
    bookFile[i] = '\0'; //makes bookFile into a string

    // DO NOT ALTER
    // start the system
    printf("\nIntialising library system!\n");
    libraryCLI( bookFile );
    printf("\nClosing library system!\n\n");

    return 0;
}
