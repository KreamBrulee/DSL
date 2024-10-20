
#include<iostream>
#include<climits>
using namespace std;

template <class T>  
struct node{
    T data;
    node* next;
};

template<class T>
class Stack{
    node<T> *top;

    public:

    Stack() {
        top = nullptr;
    }

    bool empty() {
        if(top == nullptr) 
            return true;
        return false;
    }

    void push(T data) {
        node<T> *nn = new node<T>;
        nn->data = data;

        nn->next = top;
        top = nn; 
    }

    void pop() {
        if(top == nullptr){
            cout<<"Empty"<<endl;
            return ;
        }

        node<T> *todelete = top;
        top = top->next;
        delete todelete;
    }

    T Top() {
        if(top == nullptr){
            cout<<"Empty"<<endl;
            return T(214719);
        }

        return top->data;
    }



};


int priority(char ch) {
    if(ch == '^')
        return 3;
    if(ch == '*' || ch == '/')
        return 2;
    if(ch == '+' || ch == '-')
        return 1;
    return -1;
}


string infix_to_postfix(string s){
    int n = s.length();
    string ans;
    Stack<char> st;
    for(int i=0 ; i<n; i++) {
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
            ans += s[i];
        } else{
            if(s[i] == '('){
                st.push('(');
            } 
            else if(s[i] == ')'){
                while(!st.empty() && st.Top() != '('){
                    ans += st.Top();
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();
                }
            } else{
                while(!st.empty() && priority(s[i]) < priority(st.Top())){
                    ans += st.Top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
    }

    while(!st.empty()){
        ans += st.Top();
        st.pop();
    }

    return ans;
}


int main() {

    string s;
    getline(cin,s);
    cout<<s<<endl;
    string ans = infix_to_postfix(s);
    cout<<ans<<endl;

   

    return 0;
}