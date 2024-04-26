#include <iostream>
#include <string>
#include "circular_linked_list.h"
using namespace std;




int main(void)
{
	// test of thr class

	c_linked_list <int> list;
	cout << " <<test the circular inked_list >>\n";
	cout << "*************************************\n";
	cout << "** test <insertAtHead>\n";
	list.print();
	list.insertAtHead(3);
	list.insertAtHead(2);
	list.insertAtHead(2);
	list.insertAtHead(1);
	list.insertAtHead(4);
	list.insertAtHead(8);
	list.print();
	cout << "** test <linkedListSize>\n";
	cout << "the size = " << list.linkedListSize() << "\n";
	list.clear();
	list.print();
	cout << "test clear";
	cout << " the size = " << list.linkedListSize() << "\n"; 
	cout << "*************************************\n";
	cout << "test nsertAtTail\n";
	list.insertAtTail(10);
	list.insertAtTail(11);
	list.insertAtTail(12);
	list.insertAtTail(13);
	list.print();
	cout << " the size = " << list.linkedListSize() << "\n"; 

	cout << "_____________________________________\n";
	list.insertAt(100, 4);
	list.print();
	cout << " the size = " << list.linkedListSize() << "\n";
	list.insertAt(20,0);
	list.insertAt(40,10);
	cout <<"nsertAt(20,0)\ninsertAt(40,10)\n";
	list.print();
	cout << " the size = " << list.linkedListSize() << "\n";
	cout << "_____________________________________\n";
	cout << "test isEmpty";
	cout << "isEmpty : "<< list.isEmpty() << "\n";
	list.clear();
	cout << "list_cleard \n";
	cout << "isEmpty : "<< list.isEmpty() << "\n";
	cout << "_____________________________________\n";
	list.insertAtHead(10);
	list.insertAtHead(20);
	list.insertAtHead(30);
	list.insertAtHead(40);
	cout << "removeAtHead,removeAtTail\n";
 	cout<< "removeAt\n";
	list.print();
	cout << " the size = " << list.linkedListSize() << "\n";
	cout << "_____________________________________\n";
	list.removeAtHead();
	list.print();
	cout << " the size = " << list.linkedListSize() << "\n";
	cout << "_____________________________________\n";
	list.removeAtTail();
	list.print();
	cout << " the size = " << list.linkedListSize() << "\n";
	cout << "_____________________________________\n";
	list.insertAtHead(50);
	list.insertAtHead(60);
	list.insertAtHead(70);
	list.insertAtHead(80);
	list.print();
	cout << " the size = " << list.linkedListSize() << "\n";
	cout << "_____________________________________\n";
	list.insertAtTail(100);
	list.insertAtTail(200);
	list.print();
	cout << " the size = " << list.linkedListSize() << "\n";
	cout << "_____________________________________\n";
	
	list.removeAt(0);
	list.print();
	cout << " the size = " << list.linkedListSize() << "\n";
	cout << "_____________________________________\n";
	
	list.removeAt(6);
	list.print();
	cout << " the size = " << list.linkedListSize() << "\n";
	cout << "_____________________________________\n";
	
	list.removeAt(3);
	list.print();
	cout << " the size = " << list.linkedListSize() << "\n";
	cout << "_____________________________________\n";
	list.removeAt(10);
	list.print();
	cout << " the size = " << list.linkedListSize() << "\n";
	cout << "_____________________________________\n";
	
	list.removeAt(1);
	list.print();
	cout << " the size = " << list.linkedListSize() << "\n";
	cout << "_____________________________________\n";
	
	cout << "test replaceAt\n";

	list.insertAtHead(50);
	list.replaceAt(1, 0);
	list.replaceAt(2, 1);
	list.replaceAt(3, 2);
	list.replaceAt(4, 3);
	list.print();
	cout << " the size = " << list.linkedListSize() << "\n";
	cout << "_____________________________________\n";
	
	cout << "test isExist\n";
	cout << "is< 4 >Exist :: "<<list.isExist(4)<< '\n';
	cout << "is< 1 >Exist :: "<< list.isExist(1)<< '\n';
	cout << "is< 2 >Exist :: "<<list.isExist(2)<< '\n';
	cout << "is< 3 >Exist :: "<<list.isExist(3)<< '\n';
	cout << "is< 100 >Exist :: "<<list.isExist(100)<< '\n';
	list.print();
	cout << " the size = " << list.linkedListSize() << "\n";
	cout << "_____________________________________\n";
	cout <<"test isItemAtEqual\n";
	cout << "isItemAtEqual(0,1)"<< list.isItemAtEqual(1,0)<<"\n";
	cout << "isItemAtEqual(1,2)"<< list.isItemAtEqual(2,1)<<"\n";
	cout << "isItemAtEqual(3,1)"<< list.isItemAtEqual(3,1)<<"\n";
	list.print();
	cout << " the size = " << list.linkedListSize() << "\n";
	cout << "_____________________________________\n";
	cout <<"test retrieveAt\n";
	cout << list.retrieveAt(5)<< " \n";
	cout << list.retrieveAt(3)<< " \n";
	cout << "_____________________________________\n";
	list.print();
	cout << " the size = " << list.linkedListSize() << "\n";
	cout << "_____________________________________\n";
	cout << "_____________________________________\n";
	cout << "_____________________________________\n";
	
	list.clear();
}