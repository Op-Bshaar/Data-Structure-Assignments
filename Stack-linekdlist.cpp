#include<iostream>
using namespace std;

template<class t>
class Stack {
private:
    struct Node {
        t item;
        Node* next;
    };
    Node* top;
public:
    Stack() {
        top = NULL; 
    }
    void push(const t& element) {
        Node* newNode = new Node;
        newNode->item = element;
        newNode->next = top;
        top = newNode; 
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty.";
            return;
        }
        Node* temp = new Node;
        temp = top;
        top = top->next;
        delete temp;
    }


    bool isEmpty() {
        return top == NULL;
    }

  
    
    t getTop() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
           
        }
        return top->item;
    }
    void clear(){
        while (!isEmpty())
        {
                pop();
        }
        
    }
    void print() {
        Node* current = top;
        while (current != nullptr) {
            cout << current->item << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack<int> s;
    s.push(20);
    s.push(30);
    s.print();
    s.clear();
    s.print();
    return 0;
}
