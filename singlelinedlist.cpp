#include<iostream>
using namespace std;
struct nodeType
{
    int info;
    nodeType *next;
};

class linkedlist{
public:
    void insterAthead(int);
    void insertAtTail();
    void insertAt (int,int);
    void removeAtHead ();
    void removeAttail();
    void removeAtTail(int); 
    void removeAt(int);
    bool isempty();
    int linkedListSize(); 
    void clear();
    void print();
private:
    nodeType *first,*last;
    int length;

void linkedlist::insertAthead(int item){
    nodeType *newNode = new nodeType;
    newNode->info = item;
    if(length == 0){
        first = last = newNode;
        newNode->next = NULL;
 
    }
    else{
        newNode->next = first;
        last = newNode;
    }
    length++;
}

void linkedlist::insertAtTail(int item){
    nodeType *newNode = new nodeType;
    if(length == 0){
        first = last = newNode;
        newNode->next = NULL;
    }
    else{
      last->next = newNode;
      newNode->next = NULL;
      last = NULL;
    }

}
void linkedlist::insertAt (int loc,int item){

}

void linkedlist::removeAt(){

}
void linkedlist::removeAtHead(){
    
    
}
};
int main(){
    

}