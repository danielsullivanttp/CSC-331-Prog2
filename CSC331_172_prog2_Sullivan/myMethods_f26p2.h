//***********************************************************************************************************************
//  CSC331-Section172
//  Daniel Sullivan
//  Due date: 10/9/2026
//  Program 2: Linked List
//  
//  myMethods_f26p2.h: 
//     This file contains the linked list methods for Project 2: 
//        daniel1: Removes a person by ID
//        daniel2: Updates a person's first and last name by ID
//        daniel3: Adds a new person to the list (with duplicate ID checking), inserting the new node in sequential order.
//***********************************************************************************************************************
#ifndef MYMETHODS_F26P2_H                                     // If this header hasn't been included yet, start including it.
#define MYMETHODS_F26P2_H                                     // Mark this header as included so it won't be included again.
                                                              
#include <iostream>                                           // Import the input/output stream library
using namespace std;                                          // Allows the use of cout without needing to type std:: every time.

// ******************************
// daniel1: REMOVE PERSON BY ID
// ******************************
void List_f26::daniel1(int id) {                              // Defines daniel1: removes a person by id.        
   personType* current = firstNode;                           // Creates a pointer: current. Makes it point to same node firstNode points to.
   personType* previous = NULL;                               // Creates a pointer: previous. Makes it point to NULL.

   //***********************************************
   // SEARCH THROUGH THE LIST FOR THE SPECIFIED ID
   //*********************************************** 
   while (current != NULL)                                    // Continue until the end of the list.
    {
       //*******************************************************
       // IF THIS NODE'S ID MATCHES THE ONE BEING SEARCHED FOR
       //*******************************************************
       if (current->id_pt == id)                    
       {  
          //*********************************
          // CASE 1: IF REMOVING FIRST NODE
          //*********************************
          if (previous == NULL)                        
          {
             firstNode = current->next_pt;                    // Move the head to next node.
          }                                                   
          else                                                
          {                                                   
             previous->next_pt = current->next_pt;            // Link previous node to node after current.
          }
          
          //*********************************
          // CASE 2: IF REMOVING FINAL NODE
          //*********************************
          if (current == lastNode)                     
          {
             lastNode = previous;                             // Previous node becomes new last node.
          }                                                   
                                                              
          delete current;                                     // Delete matching person
                                                              
            cout << "\nPerson removed\n\n";                     // Output confirmation message and start a new line.
            return;                                           // Exit- removal complete.
        }                                                     
                                                              
        previous = current;                                   // Assign the value of the current node pointer to previous.
        current = current->next_pt;                           // Advance to the next node in the list.
    }                                                         
                                                              
    //***************************                             
    // CASE 3: ID WAS NOT FOUND                               
    //***************************                             
    cout << "\nPerson not removed\n\n";                         // Id not found output "Person not removed".
}

// ****************************************************
// daniel2: UPDATE PERSONS FIRST AND LAST NAMES BY ID  
// ****************************************************
void List_f26::daniel2(int id, string newFirstName, string newLastName) { // Defines daniel2: updates a person by id.
   personType* current = firstNode;                           // Creates a pointer: current. Points to same node firstNode points to.

   //*********************************************** 
   // SEARCH THROUGH THE LIST FOR THE SPECIFIED ID
   //***********************************************
   while (current != NULL) {                                  // Continue until the end of the list.
      
      //**************************************************************
      // CASE 1: THIS NODE'S ID MATCHES THE ID BEING SEARCHED FOR
      //**************************************************************
      if (current->id_pt == id) {                            
         current->fname_pt = newFirstName;                    // Change current first name to the value of newFirstName.
         current->lname_pt = newLastName;                     // Change current last name to the value of newLastName.

         cout << "\nName updated successfully\n\n";             // Output confimation message. Start new line.
         return;                                              // Exit- update complete.            
      }

      //******************************************************************
      // CASE 2: THIS NODE'S ID DOES NOT MATCH THE ID BEING SEARCHED FOR
      //******************************************************************
      current = current->next_pt;                             // Advance to the next node in the list.
   }

   //****************************************************************
   // CASE 3: NO NODE IN THE LIST MATCHED THE ID BEING SEARCHED FOR
   //****************************************************************
   cout << "\nID not found\n\n";                              // Output "ID not found." Start new line.
}

// ***********************************************
// daniel3: ADD PERSON ONLY IF ID DOES NOT EXIST  
// ***********************************************
void List_f26::daniel3(int id, string firstName, string lastName) { // Defines daniel3: add person only if Id doesn't exist.
   personType* current = firstNode;                           // Creates a pointer: current. Points to same node firstNode points to.

   //*********************************************** 
   // SEARCH THROUGH THE LIST FOR THE SPECIFIED ID
   //***********************************************
   while (current != nullptr) {                               // Continue until the end of the list. 
      
      //***********************************************************
      // CASE 1: THIS NODE'S ID MATCHES THE ID BEING SEARCHED FOR
      //***********************************************************
      if (current->id_pt == id) {                       
          cout << "\nPerson not added\n\n";                   // Id found- Output "Person not added."
         return;                                              // Exit— ID already exists.
      }

      //******************************************************************
      // CASE 2: THIS NODE'S ID DOES NOT MATCH THE ID BEING SEARCHED FOR
      //******************************************************************
      current = current->next_pt;                             // Advance to the next node in the list. 
   }  

   //******************************************************** 
   // CASE 3: THIS NODE'S ID DOES NOT EXIST. ADD NEW PERSON
   //********************************************************
   personType* p = new personType;                            // Create a new persontype object.Store its pointer in p.    
   p->id_pt = id;                                             // Store value of id in new node's id field.     
   p->fname_pt = firstName;                                   // Store value of firstName in new node's first-name field.              
   p->lname_pt = lastName;                                    // Store value of lastName in new node's last-name field. 
   p->next_pt = NULL;                                         // Set the new node's next pointer to NULL. 
                                                            
   //*************************************************************************************************************
   // INSERT NEW NODE IN SEQUENTIAL ORDER BASED ON ID
   //*************************************************************************************************************

   //****************************************************
   // CASE 1: EMPTY LIST OR NEW ID BELONGS AT THE FRONT
   //****************************************************
   if (firstNode == NULL || id < firstNode->id_pt) {
      p->next_pt = firstNode;                                 // New node points to old first node.
      firstNode = p;                                          // New node becomes first node.
                                                              
      if (lastNode == NULL)                                   // If list was empty.
         lastNode = p;                                        // New node is also last node.
                                                              
      cout << "\nPerson added\n\n";                           // Output Success message: "Person added."
      return;                                                 // Exit- add successful.
   }                                                          
                                                              
   //**********************************                       
   // CASE 2: INSERT IN MIDDLE OR END                         
   //**********************************                       
   current = firstNode;                                       // Set current to point at firstNode. 
   
   //**********************************************************************************
   // ADVANCE CURRENT UNTIL THE NEXT NODE'S ID IS GREATER THAN OR EQUAL TO THE NEW ID
   //**********************************************************************************
   while (current->next_pt != NULL && current->next_pt->id_pt < id) {
      current = current->next_pt;                             // Move current forward to the next node in the list.
   }                                                          
                                                              
   //******************                                       
   // INSERT NEW NODE                                         
   //******************                                       
   p->next_pt = current->next_pt;                             // New node points to next node.
   current->next_pt = p;                                      // Current node points to new node.
                                                              
   //*********************************************            
   // CASE 3: INSERT AT THE END, UPDATE lastNode              
   //*********************************************            
   if (p->next_pt == NULL)                                    
      lastNode = p;                                           // The new node is now the last node in the list.                             
                                                              
   cout << "\nPerson added\n\n";                              // Output the message "person added" and start a new line.
}                                                             

#endif                                                        // End of the header guard.