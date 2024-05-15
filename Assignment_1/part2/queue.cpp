#include<iostream>
#include <cassert>
using namespace std;
class arrayQueue{
    int front;
    int rear;
    int length;
    int maxzise;
    int *arr;
public:    
    arrayQueue(int size){
        if(size<=0) maxzise = 200;
        else maxzise = size;
        length = 0;
        front = 0;
        arr = new int[maxzise];
        rear = maxzise - 1;
    }
    bool isFull(){
        return length == maxzise;
    }
    void enqueue(int element){
      if (isFull())cout<<"sorry,queue is full";
      else{
        rear = (rear+1)%maxzise;
        arr[rear] = element;
        length++;
      }
    }
    int isEmpty(){
        return length == 0;
    }
    int firstQueue(){
      assert(!isEmpty());
      return arr[front];
    }
    int size(){
        return length;
    }

   void clear(){
    front = 0;
    rear = maxzise - 1;
    length = 0;
    delete [] arr;
    arr = new int [maxzise];
   }
    void printQueue(){
        if(!isEmpty()){
            for(int i = front;i!=rear;i = (i+1)%maxzise){
                cout << arr[i];
            }
            cout << arr[rear] << endl;
        } else{
          cout << "queue is empty!!" << endl;
        }
     }
    void dequeue(){
		if (isEmpty()){
			cout << " Can't Dequeue ...!";
		}
		else
		{
			front = (front + 1) % maxzise;
			--length;

		}
	}
};

int main(){
  arrayQueue he(5);
  he.enqueue(2);
  he.enqueue(3);
  he.enqueue(4);
  he.enqueue(5);
  he.printQueue();
  he.dequeue();
  he.dequeue();
  he.dequeue();
  he.dequeue();
  he.printQueue();
}