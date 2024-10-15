#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

class cll{
    node *head;
    node *tail;

    public:
    int len;

    cll(){
        head = NULL;
        tail= NULL;
        len = 0;

    }

    void addBeg(int d){
        node *nn = new node;
       
        if(!nn){
            
            return;
        }
        nn->data = d;
        len++;

        if(head == NULL){
            head = nn;
            nn->next = head;
            cout<<2<<"\n";
            tail = nn;
            
            return;
        }

        nn->next = head;
        tail->next = nn;
        head = nn;
        return;
    }

    void addEnd(int d){
        node *nn = new node;
       
        if(!nn){
            
            return;
        }
        nn->data = d;
        len++;
        if(head == NULL){
            head = nn;
            nn->next = head;
            cout<<2<<"\n";
            tail = nn;
            
            return;
        }

        nn->next = head;
        tail->next = nn;
        tail = nn;
        return;
    }

    void display(int n){
        if(len<n || n<=0){
            cout<<"Wrong: Idiot";
            return;
        }

        node *temp = head;
        for(int i=1;i<=n;i++){
            cout<<"Data"<<i<<": "<<temp->data<<"\n";
            temp = temp->next;
        }
    }

    void deleteBeg(){
        if(head = NULL){
            cout<<"Cant delete anything: idiot";
            return;
        }
        cout<<tail->next->data;
        tail->next=tail->next->next;
        free(head);
        head = tail->next; 
        len--;  
    }
    void deleteEnd(){
        node *temp = head;

        while(!(temp->next == tail)){
            temp = temp->next;
        }

        temp->next=head;
        free(tail);
        tail = temp;
        len--;
    }

    void delt(int n){
        node *temp = head;
        node *temp2 = head;

        while(!(temp->data == n)){
            temp2 =temp;
            temp = temp->next;
        }
    }

    void delti(int n){
        node *temp = head;
        node *temp2 = head;
        if(n>len){
            cout<<"Baka";
            return;
        }

        for(int i=0;i<n;i++){
            temp2 =temp;
            temp = temp->next;
        }
    }
};

int main()
{
    cll list;
    int choice;

    do{
        cout<<"Chouce?: ";
        cin>>choice;
        int data  = 0;

        switch(choice){
            case 1:
                cout<<"data?";
                cin>>data;
                list.addEnd(data);
                break;

            case 2:
                list.deleteBeg();
                break;

            case 3:
                list.deleteEnd();
                break;

            case 4:
                cout<<"data?";
                cin>>data;
                list.delt(data);
                break;

            case 5:
                list.display(list.len);
                break;

            case 6:
                cout<<"index?";
                cin>>data;
                list.delti(data);
                break;
            case 7:
                cout<<"data?";
                cin>>data;
                list.addBeg(data);
                break;
        }
        
    }while(choice!=-1);

    return(0);
}