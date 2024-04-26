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
			cout << "stack empty on getTop";
		else {
			cout<<"the top is" <<arr[top]<<endl;
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
        for(int i = top;i>=0;i--){
            cout<<arr[i];
        }
        
    }
};
int main(){
  Stack<int>stackee;
  stackee.push(2);
  stackee.push(3);
  stackee.push(4);
  stackee.pop();
  stackee.print();
}