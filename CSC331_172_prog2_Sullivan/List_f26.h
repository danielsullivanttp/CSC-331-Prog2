//************************************************************
// List_f26.h
// Author: BMCC CSC331 Fall 2026
//
// class List_f26
// This class specifies the members of a linked list object.
//************************************************************
#include <string>
using namespace std;
class List_f26{
  public:
    void personAdd(int id, string first, string last);
    void personList();
    List_f26();
#include "myDefs_f26p2.h"
  private:
    struct personType{
      int id_pt;           // ID
      string fname_pt;     // first name
      string lname_pt;     // last name
      personType *next_pt; // address of next person in the linked list
    };
  personType *firstNode,       // address of first person in the linked list
             *lastNode;        // address of last person in the linked list
};
void List_f26::personAdd(int ID, string firstName, string lastName) {
  personType *p = new personType;
  p->id_pt = ID;
  p->fname_pt = firstName;
  p->lname_pt = lastName;
  p->next_pt = NULL;  
  if(firstNode == NULL)
    firstNode=p;
  else
    lastNode->next_pt=p;
  lastNode=p;
} 
void List_f26::personList() {
  if(firstNode == NULL)
    cout << "The list is empty." << endl;
  else {
    personType *current=firstNode;
    int i=0;
    while(current != NULL){
      i++;
      cout << i << ". " << current->id_pt << " " << current->fname_pt << " " << current->lname_pt << endl;
      current=current->next_pt;
    }
  }
}
#include "myMethods_f26p2.h"
//Default constructor
List_f26::List_f26(){
  firstNode=NULL;
  lastNode=NULL;
}

