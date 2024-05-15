#include<iostream>
using namespace std;
const int maxSize = 100;
template<class t>
class Stack{
    t top;
    t arr[maxSize];
public:
    Stack(){
        top = -1;
    }
    void push(t element){
        if(top>maxSize-1){
            cout<<"the stack is full";
        }
        else{
            top++;
            arr[top] = element;
        }
    }

   void pop()
	{
		if (isEmpty())
			cout << "stack empty on pop";
		else{
			top--;
        }
	}
    void getTop(){
		
		if (isEmpty())
			cout << "Stack is Empty!!" << '\n';
		else {
			cout<<"the top is " <<arr[top] << '\n';
	}
	
	}
    
    bool isEmpty(){
    
       return top<0;
    }

    t stackSize(){
        cout<<"the size is"<<top +1<<endl;
    }

    void clear(){
     top = -1;
    }

    void print(){
        if(isEmpty()){
            cout << "Empty!!";
        } else{
            for(int i = top;i>=0;i--){
                cout<<arr[i] << " ";
            }
        }
        cout << '\n';
    }
};
int main(){
  Stack<int>stackee;
  stackee.push(2);
  stackee.push(3);
  stackee.push(4);
  stackee.print();
  stackee.getTop();
  stackee.pop();
  stackee.pop();
  stackee.pop();
  stackee.print();
}