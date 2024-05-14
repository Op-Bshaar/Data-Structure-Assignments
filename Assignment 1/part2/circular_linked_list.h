/*
this the header file of the linked list class that
define the class of the sigle linked list

Auther mahmoud Ahmed
email mahmoudadam5555@gmail.com
*/

#ifndef CIRCLAR_LINKED_LIST_H
#define CIRCLAR_LINKED_LIST_H
template <typename T>
class c_linked_list
{

	private:
	int Size;

	struct node  
	{
		T data;
		node *next;
	};
	node *Head;
	node *Tail;

	public:
	c_linked_list(T data);
	c_linked_list();
	void insertAtHead(T element);
	void insertAtTail (T element);
	void insertAt(T element, int index);
 	void removeAtHead();
 	void removeAtTail();
 	void removeAt(int index);
 	T retrieveAt(int index);
 	void replaceAt(T newElement, int index);
	
 	bool isExist(T element);
	bool isItemAtEqual(T element, int index);
 	void swap (int firstItemIdx, int secondItemIdx);

	bool isEmpty ();
	int linkedListSize ();
	void clear ();
	void print ();
	

	

};
#include "circular_linked_list.cpp"

#endif