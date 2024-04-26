/**
 * Auther: Mahmoud Ahmed Ibrahim Adam
 * email:  mahmoudadam5555@gmail.com 
*/
#include <iostream>
#include "circular_linked_list.h"

/**
 * c_linked_list - constructor with one paramiter
 * @data: the value insaide the first node <Head>
 * Return: no return value
*/

template <typename T>
c_linked_list <T>:: c_linked_list(T data){

	/*create the node*/
	node *new_node = new node;
	//check if the node locate right
	if (new_node == NULL)
		exit(1);

	
	Head  = new_node;
	this->Head->data = data;
	this->Head->next = NULL;
	this->Tail = Head;
	this->Tail->next == this->Head;
	this->Size = 1; 
}


/**
 * c_linked_list - constructor defult
 * Return: no return value
*/
template <typename T>
c_linked_list <T>:: c_linked_list(){
	/*defult class values */
	this->Size = 0;
	this->Head = NULL;
	this->Tail = NULL;
}

/**
 * insertAtHead - function that insert new node in the head
 * @element: with any type T after 
*/
template <typename  T>
void c_linked_list <T>::insertAtHead(T element)
{
	node *new_node = new node;
    if (!new_node) {
        exit(1);
    }

    // Assign data to the new node
    new_node->data = element;


	// If the list is empty
    if (!this->Head) 
	{  
        Head = new_node;
        Tail = new_node;
        new_node->next = new_node;  // Circular linking
    } 
	else {
        new_node->next = Head;  // Link new node to current head
        Head = new_node;  // Update head to point to the new node
        Tail->next = Head;  // Update tail's next to point to the new head
    }
    
    Size++;  // Increase the size of the list
}

/**
 * insertAt - function that inser in the specific indix
 * @element: the data that will be inside the new node
*/
template <typename T>
void c_linked_list<T>::insertAt(T element, int index)
{
	// ckeck if the indix is not out of the buondry
	if (index > this->Size || index < 0)
	{
		std::cout << "Out of the range\n";
		return;
	}
	// create the new node
	node *new_node = new node;
	// check if the new node locate right if it didnt close the program
	if (!new_node)
		exit(1);
	// but the value inside the node
	new_node->data = element;

	// if the node is the first node
	if (index == 0)
		insertAtHead(element);
	// if the code is the last node

	else if (index == this->Size)
		insertAtTail(element);

	else
	{

		node *it = this->Head;
		// loop to the index
		while (index > 1)
		{
			it = it->next;
			index --;
		}

		new_node->next =  it->next;
		it->next = new_node;
		this->Size++;
	}
	

}


/**
 * insertAtHead - function that insert new node in the tail
 * @element: with any type T after
 * Return: No return value 
*/
template <typename T>
void c_linked_list<T>::insertAtTail(T element) {

    node *new_node = new node;

    if (!new_node)
        exit(1);

    new_node->data = element;

	// if the list is empty
    if (!this->Head) 
	{ 
        Head = new_node;
        Tail = new_node;
    } 
	else
	{
		// Link new node to the head
        new_node->next = Head; 
		// Update current tail's next to point to the new node
        this->Tail->next = new_node;
		// Update Tail to point to the new node 
        this->Tail = new_node; 
    }

    this->Size++;
}

/**
 * clear -  function that delete all the nodes in the linked list
 * Return: no return value
*/
template <typename T>
void c_linked_list<T>::clear() {

	// The list empty
    if (!this->Head)
        return;
	// There's only one node in the list
    if (this->Head == this->Tail) 
	{
        delete this->Head;
        this->Head = NULL;
        this->Tail = NULL;
    }
    // There are multiple nodes in the list
	else
	{
        node *it = this->Head->next;
		// Start from the second node
        while (it != Head)
		{
            node *temp = it;
            it = it->next;
            delete temp;
        }
        delete Head;  // Delete the last node
    }

    // Reset size and pointers
    Size = 0;
    Head = NULL;
    Tail = NULL;
}

template <typename T>
void c_linked_list<T>::print() {
    if (!Head) {
        // The list is empty
        std::cout << "The list is empty\n";
        return;
    }

    // Iterator to traverse the list
    node *it = Head;

    // Traverse the list and print each node's data
    do {
        std::cout << it->data << '\n';
        it = it->next;
    } while (it != Head);

    std::cout << '\n';
}

/**
 * removeAtHead -  function that pop from the head side
 * Return: No return value
*/
template<typename T> 
void c_linked_list<T>::removeAtHead()
{
	// if the linked list is empty
	if (!this->Head)
		return;
	// check it's just one node so the head and the tail is
	// the same node

	if (this->Size == 1)
	{
		delete this->Head;
		this->Head = NULL;
		this->Tail = NULL;
		this->Size = 0;
		return;
	}
	
	node * my_node = this->Head;
	this->Head = this->Head->next;
	this->Tail->next = this->Head;
	delete my_node;
	this->Size--;
}

/**
 * isEmpty -  function that check if the linked_list is impty or not
 * Return: true if linked list is empty atherwise false 
*/

template <typename T>
bool c_linked_list<T>::isEmpty ()
{
	return bool(!this->Size);
}

/**
 * c_linked_list - function that return number of the nodes in the linked_list
*/
template <typename T>
int c_linked_list<T>:: linkedListSize ()
{
	return this->Size;
}

/**
 * isExist -  function that check if the element in the linked list or not
 * @element: the element that you search for 
*/
template <typename T> 
bool c_linked_list<T>::isExist(T element)
{
	node *it = this->Head;
	do
	{
		if(it->data == element)
			return true;
		it = it->next;
	}
	while (it->next != Head);

	return false;
}

/**
 * isItemAtEqual -  function that check if the element in spcefic indx or not
 * @element: the element that you search for
 * @index: the index of the element
 * Return: True if elemnt is exist atherwise false
*/
template <typename T>
bool c_linked_list<T>::isItemAtEqual(T element, int index)
{
	node *it  = this->Head;
	//check if the linked list is empty or not or the index is out of the boundry
	if (!this->Head  || index < 0)
		return false;
	if (index ==  this->Size - 1)
		return this->Tail->data == element;
	else if (index == 0)
		return this->Head->data == element;
	else
	{
		while (index && it)
		{
			it = it->next;
			index--;
		}
		return it->data == element;
	}
	return false;
}

/**
 * removeAtTail - function that remove from the tail side
 * Return: No return value
*/
template <typename T>
void c_linked_list<T>::removeAtTail()
{
	int number = this->Size;
	//check if the linked list is empaty
	if (!this->Size)
		return;
	// check it's just one node so the head and the tail is
	//the same node

	if (this->Size == 1)
	{
		delete this->Head;
		this->Head = NULL;
		this->Tail = NULL;
		this->Size = 0;
		return;
	}

	node *it = this->Head;
    while (it->next->next != Head)
    {
        it = it->next;
    }

    // Delete the last node and update the tail pointer
    delete it->next;
    it->next = this->Head;
    this->Tail = it;
    this->Size--;
}

/**
 * removeAt -  function that remove from specific index
 * @index: the index of the deleted node
 * Return: no return value
*/
template<typename T>
void c_linked_list<T>::removeAt(int index)
{
	//@it: itretor
	node *it = Head;
	// if the index point to las node
	if (index % this->Size == this->Size - 1)
	{
		this->removeAtTail();
		return;
	}
	// if the indix point to the frist node
	if (index % this->Size == 0)
	{
		this->removeAtHead();
		return;
	}

	while(it && index > 1)
	{
		it = it->next;
		index--;
	}
	node *deleted_node = it->next;
	it->next = it->next->next;
	delete deleted_node;
	this->Size--;
}
/**
 * retrieveAt -  function that return element secific index in the linkid list
 * @index: indiex of the node
 * @Return: the value in the node or NULL if it out of the range 
*/
template <typename T>
T c_linked_list<T>::retrieveAt(int index)
{
	//@it: itretor
	node *it = Head;
	if(index < 0)
	{
		std:: cout << "Out of the range\n";
		return T(NULL);
	}
	while(it && index)
	{
		it = it->next;
		index--;
	}
	if(it)
		return it->data;
}
/**
 * replaceAt - function that update the value in the node
 * @newElement: the new value that will be replace it in the node
 * @index: the index the node
 * Return: no return value
*/
template<typename T>
void c_linked_list<T>::replaceAt(T newElement, int index)
{
	//@it: itretor
	node *it = Head;
	if(index < 0)
	{
		std:: cout << "Out of the range\n";
		return;
	}
	while(it && index)
	{
		it = it->next;
		index--;
	}
	if (it)
	{
		it->data = newElement;
	}

}
/**
 * swap - function that swap tow node
 * @firstItemIdx: the first node 
 * @secondItemIdx: the secand node 
 * @Return: no return value
 */
template <typename T>
void c_linked_list<T>::swap(int firstItemIdx, int secondItemIdx)
{
    if (firstItemIdx < 0 || secondItemIdx < 0 || firstItemIdx >= this->Size || secondItemIdx >= this->Size)
    {
        std::cout << "Out of the range\n";
        return;
    }

    if (firstItemIdx == secondItemIdx)
        return;

    node *it1 = Head;
    node *it2 = Head;
    node *prev1 = NULL;
    node *prev2 = NULL;

    // Find the nodes to be swapped and their previous nodes
    for (int i = 0; i < firstItemIdx; ++i)
    {
        prev1 = it1;
        it1 = it1->next;
    }

    for (int i = 0; i < secondItemIdx; ++i)
    {
        prev2 = it2;
        it2 = it2->next;
    }

    // Update the pointers
    if (prev1)
        prev1->next = it2;
    else
	{
        this->Head = it2;
		this->Tail->next = this->Head;
	}

    if (prev2)
        prev2->next = it1;
    else
	{
        this->Head = it1;
		this->Tail->next = this->Head;
	}

    node *temp = it1->next;
    it1->next = it2->next;
    it2->next = temp;

    // Update the Tail pointer if necessary
    if (firstItemIdx == this->Size - 1)
	{
        this->Tail = it2;
		this->Tail->next = this->Head;
	}
    else if (secondItemIdx == this->Size - 1)
	{
		this->Tail = it1;
		this->Tail->next = this->Head;
	}
        
}

