//********************************************************************************************
//  CSC331-Section 172
//  Daniel Sullivan
//  Program 2: Linked List 
//  
//  myDefs_f26p2.h:  
//     This file contains the function prototypes for the three required linked list operations:
//        daniel1 – removes a person by ID
//        daniel2 – updates a person's name by ID
//        daniel3 – adds a new person to the list only if the ID entered does not exist
//********************************************************************************************

void daniel1(int id);											// Declare daniel1, which removes a person using their ID.
void daniel2(int id, string newFirstName, string newLastName);	// Declare daniel2, which updates a person using their ID.	
void daniel3(int id, string firstName, string lastName);		// Declare daniel3, which adds a person if ID doen't exist.