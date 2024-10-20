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
            top->next = NULL;
            cout<<nn->data<<"\n";
            return;
        }

        cout<<nn->data<<"\n";
        nn->next = top;
        top = nn;
        cout<<top<<"\n";
    }

    B pop(){
        if (isEmpty())
            throw('e');
        return (top->data);
        cout<<top->data<<"\n";
        node <B> *temp = top;
        top = top->next;
        free(temp);


    }

    B seek(){
        if (isEmpty())
            throw('e');
        return (top->data);
    }
};

int main(){
    stk <int> s;
    cout<<s.isEmpty();
    s.push(1);
    s.push(2);
    s.pop();
    cout<<s.isEmpty();
    s.pop();
    cout<<s.isEmpty();
    return 0;
}
