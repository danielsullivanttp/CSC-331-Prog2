//************************************************************************************************************
//  CSC331-Section 172
//  Daniel Sullivan
//  Program 2: Linked List
//  Due: Friday 10/9/2026 @ 11:59pm
// 
//  CSC331_172_prog2_sullivan.cpp
//  This file contains the main function for Program 2. It processes the following linked-list transactions:
//  1. 'A'- add (with duplicate ID checking)
//  2. 'R'- remove
//  3. 'U'- update
//  4. 'L'- list
//  5. 'Q'- quit
// ***********************************************************************************************************
#include <iostream>							                                    // Import the input/output library.
#include "List_f26.h"						                                    // Import List_f26 header file.
											                                    
using namespace std;														    // Allows the use of cin and cout without having to type std:: every time.
																			    
//*********************************************		    
// TMAIN FUNCTION IS WHERE THE PROGRAM STARTS							    
//*********************************************		    
int main() {																    
   List_f26 people;							                                    // Declare a new List_f26 type object named people.
   char transaction;						                                    // Declare a new char variable named transaction.
   int id;									                                    // Declare an integer named id.			
   string firstName;						                                    // Declare a new string named firstName.
   string lastName;							                                    // Declare a new string named lastName.
   string newFirstName;						                                    // Declare a new string named newFirstName.	
   string newLastName;															// Declare a new string named newLastName.

   //********************************************************
   // BEGIN A LOOP THAT CONTINUES UNTIL THE USER ENTERS 'Q'
   //********************************************************
   do {										
      cout << "Enter transaction: ";											// Prompt user for transaction.
	  cin >> transaction;														// Store user input in transaction.						
	  
	  //*************************
	  // CASE 1: USER PICKS 'A'
	  //*************************
	  if (transaction == 'A') {															
		 cin >> id >> firstName >> lastName;									// Store user inputs in associated variable. 
		 //********************************************************************************
		 // Call daniel3 method on the people list using the user inputs as the arguments
		 //********************************************************************************
		 people.daniel3(id, firstName, lastName);									
	  }
	  
	  //*************************
	  // CASE 2: USER PICKS 'R'
	  //*************************
	  else if (transaction == 'R') {										     	
		 cin >> id;																// Store user input in id variable.

		 //******************************************************************************
		 // Call daniel1 method on the people list using the user input as the argument
		 //******************************************************************************
    	 people.daniel1(id);
	  }
	  
	  //*************************
	  // CASE 3: USER PICKS 'L'
	  //*************************
	  else if (transaction == 'L') {										
		 cout << endl;															// Output on a new line.
		 //********************************************
   		 // Call personList method on the people list
		 //********************************************
		 people.personList();
		 cout << endl;
	  }
	  
	  //*************************
	  // CASE 4: USER PICKS 'U'
	  //*************************
	  else if (transaction == 'U') {
	     cin >> id >> newFirstName >> newLastName;			   			        // Store user inputs in associated variables.
		 //*******************************************************************************
		 // Call daniel2 method on the people list using the user input as the arguments.
		 //*******************************************************************************
		 people.daniel2(id, newFirstName, newLastName);
		}

	  //*************************
	  // CASE 5: USER PICKS 'Q'
	  //*************************
	} while (transaction != 'Q');									            // Exit loop 

	return 0;														            // Successfully exit program.
}