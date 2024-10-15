#include <iostream>

using namespace std;


template <class T>

struct node{
    T data;
    node *next;
};

template <class B>
class stk{
    node <B> *top;
    public:
    stk(){
        top = NULL;
    }

    bool isEmpty(){
        if (top == NULL)
            return(true);
        return(false);
    }

    void push(B data){
        node <B> *nn = new node <B> ;
        if(!nn)
            return;
        
        nn->data = data;
        if(top == NULL){
            top = nn; 
            return;
        }

        nn->next = top;
        top = nn;
    }

    void pop(){
        if (isEmpty())
            return;
        if
        cout<<top->data;
        free(top);
        top = NULL;


    }
};

int main(){
    stk <int> s;
    s.push(1);
    s.pop();
}
