#include <iostream>
#include <functional>
using namespace std;
template <typename T>
class node
{
public:
	node* Right;
	node* Left;
	T Item;
		node(T thing=NULL, node* right=nullptr,node* left=nullptr)
	{
		this->Right = right;
		this->Left = left;
		this->Item = thing;
	}
}
;

template <typename T>
class BinarySearchTree
{
private:
	node<T>* Root;
	node<T>* Current;
	node<T>* Next;
public:
	int side;
	BinarySearchTree(node<T>* start)
	{
		this->Root = start;
	}BinarySearchTree()
	{
		this->Root = new node<T>();
	}
	void Push(node<T>* Node)
	{
		push(Root, Node);
	}
	void Push(node<T>* NodeLoc, node<T> Node)
	{
		
		while (Next != NULL)
		{
			Current = NodeLoc;
			Next = Current;
			if (Node.Item < Next->Item)
			{
				side = 0;
				Push(Next->Left, Node);
			}
			else if(Node.Item>Next->Item)
			{
				side = 1;
				Push(Next->Right, Node);
			}
			Current = Next;
			
			
		}
		switch (side)
		{
		case 0:
			Current->Left = Next;
			break;
		case 1:
			Current->Right = Next;
			break;
		}

	}
};
int main()
{
	node<int> Root(1);
	node<int> ne(2);
	BinarySearchTree<int> BST(&Root);
	return 0;
}