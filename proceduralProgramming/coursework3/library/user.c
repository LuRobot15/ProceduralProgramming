#include <stdio.h>
#include <stdlib.h>

#include "libraryStructures.h"
#include "user.h"
#include "utility.h"

////
// Code module for the library user
// They can look for available books,
// borrow and return books

// List the books that are available to borrow
// Input
// bookList - the array of Book structures
// numBooks - the number of books

void listAvailableBooks( Book *bookList, int numBooks ) {

  // TO DO :

  // print out available books with format "list number - author - title" on each line

  for (int i = 0; i < numBooks; i++)
  {
    if (bookList[i].available == 1)
      printf("%i - %s - %s\n", i, bookList[i].author, bookList[i].title);
  }

  return;
}

// Borrow a book
// Input
// theUser - user data structure
// bookList - the array of Book structures
// numBooks - the number of books
// maxBorrowed - max books we can borrow

void borrowBook( User *theUser, Book *bookList, int numBooks, int maxBorrowed ) {

  // TO DO :

  // For any error message you should return to the menu

  // check that the user can borrow a book

  // request the choice of book

  // check that the choice is valid
  // error messages

  // borrow the book, update the data structures

  if (theUser->numBorrowed == maxBorrowed)  //error message if the user has already borrowed the maximum allowed
  {
    printf("You have to return a book before you can borrow another\n");
    return;
  }

  printf("Which book? (number):"); //requests the user to input the index of the book they want to borrow
  int bookToBorrow; //stores the index of the book the user wishes to borrow
  scanf("%i", &bookToBorrow);
  getchar();//clears the new line character from the input buffer

  if ((bookToBorrow >= numBooks) || (bookToBorrow < 0)) //if the user input is above the number of books in the list
  {
    printf("Error\nInvalid choice\n");
    return;
  }
  if (bookList[bookToBorrow].available == 0)  //if the index entered is not available
  {
    printf("Book is not available\n");
    return;
  }

  for (int i = 0; i < maxBorrowed; i++)
  {
    if (theUser->borrowed[i] == 0)
    {
      theUser->borrowed[i] = bookList + bookToBorrow;  //adds the book to the array of books the user has borrowed
      theUser->numBorrowed++; //increments the number of books the user has borrowed
      bookList[bookToBorrow].available = 0; //sets the book to be unavailable
      break;
    }
  }

  return;
}

// List books I have borrowed
// Input
// theUser - user data structure
// bookList - the array of Book structures
// maxBorrowed - max books we can borrow

void listMyBooks( User *theUser, Book *bookList, int maxBorrowed ) {

  // TO DO :

  // list my books in format "number - author - title"

  for (int i = 0; i < maxBorrowed; i++)
  {
    if (theUser->borrowed[i] != 0)
    {
      printf("%i - %s - %s\n", i, theUser->borrowed[i]->author, theUser->borrowed[i]->title);
    }
  }

  return;
}

// Return a book
// Input
// theUser - user data structure
// bookList - the array of Book structures
// numBooks - the number of books
// maxBorrowed - max books we can borrow

void returnBook( User *theUser, Book *bookList, int numBooks, int maxBorrowed ) {

  // TO DO :

  // For any error message you should return to the menu

  // check that we have borrowed books
  // error messages

  // request the choice of book
  // message

  // check the choice is valid
  // error messages

  // return the book and update data structures

  if (theUser->numBorrowed == 0)  //if the user hasn't borrowed any books
  {
    printf("Error\nYou have not borrowed any books\n");
    return;
  }

  printf("Which book? (number):");  //prompts the user to enter the index of the book they want to borrow
  int bookToReturn; //stores th users input
  scanf("%i", &bookToReturn);
  getchar();  //clears the new line character from the input buffer

  if ((bookToReturn >= maxBorrowed) || (bookToReturn < 0)) //if the user's input is out of range
  {
    printf("Error\nInvalid choice\n");
    return;
  }

  int indexOfBookInUsersBorrowed = 0;
  while (indexOfBookInUsersBorrowed < maxBorrowed) //finds the index of the book in the user's "borrowed" array
  {
    if (theUser->borrowed[indexOfBookInUsersBorrowed] != 0)
    {
      if (indexOfBookInUsersBorrowed == bookToReturn)
        break;
      else
        indexOfBookInUsersBorrowed++;
    }
    else
        indexOfBookInUsersBorrowed++;
  }

  if (indexOfBookInUsersBorrowed == maxBorrowed) //if the book the user is trying to return was not taken out by them, this error message shows and we return to the menu
  {
    printf("Error\nInvalid choice\n");
    return;
  }
  else
  {
    for (int i = 0; i < numBooks; i++)
    {
      if ((bookList[i].author == theUser->borrowed[indexOfBookInUsersBorrowed]->author) && (bookList[i].title == theUser->borrowed[indexOfBookInUsersBorrowed]->title))
      {
        bookList[i].available = 1; //sets the book to being available again
        theUser->numBorrowed--; //decrements the number of books borrowed
        theUser->borrowed[indexOfBookInUsersBorrowed] = 0;
        break;
      }
    }
  }

  return;
}

// DO NOT ALTER THIS FUNCTION

// Menu system for library user

void userCLI( Library *theLibrary ) {
    int userLoggedIn = 1;
    int option;

    while( userLoggedIn ){
        printf("\n User options\n 1 List available books\n 2 Borrow book\n 3 Return book\n 4 Log out\n Choice:");
        option = optionChoice();

        if( option == 1 ) {
            printf("\nList available books:\n");
            listAvailableBooks( theLibrary->bookList, theLibrary->numBooks );
        }
        else if( option == 2 ) {
            printf("\nBorrow book from library:\n");
            listAvailableBooks( theLibrary->bookList, theLibrary->numBooks );
            borrowBook( &(theLibrary->theUser), theLibrary->bookList, theLibrary->numBooks, theLibrary->maxBorrowed );
        }
        else if( option == 3 ) {
            printf("\nReturn book from my list:\n");
            listMyBooks( &(theLibrary->theUser), theLibrary->bookList, theLibrary->maxBorrowed );
            returnBook( &(theLibrary->theUser), theLibrary->bookList, theLibrary->numBooks, theLibrary->maxBorrowed );
        }
        else if( option == 4 ) {
            userLoggedIn = 0;
            printf("\nLogging out\n");
        }
        else
            printf("\nUnknown option\n");
    }
    return;
}
