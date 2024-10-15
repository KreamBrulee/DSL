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
        node *temp2 = tail;

        while(!(temp->data == n)){
            if(temp == tail){
                cout<<"Dosent Exist";
                return;
            }
            temp2 =temp;
            temp = temp->next;
        }

        if(temp==head){
            deleteBeg();
            return;
        }

        if(temp==tail){
            deleteEnd();
            return;
        }
        temp2->next = temp->next;
        free(temp);
        len--;
    }

    void delti(int n){
        node *temp = head;
        node *temp2 = tail;
        if(n>len){
            cout<<"Baka";
            return;
        }
        if(n==0){
            deleteBeg();
            return;
        }

        if(n==len-1){
            deleteEnd();
            return;
        }
        
        for(int i=0;i<n;i++){
            temp2 =temp;
            temp = temp->next;
        }
        temp2->next = temp->next;
        free(temp);
        len--;
    }
};

int main()
{
    cll list;
    int choice;
    cout<<"1)Add at end\n2)Delete from begining\n3)Delete from end\n4)Delete an element\n5)Display all\n6)Delete an index\n7)Add at Begining\n-1)Exit";
    do{
        cout<<"\nWhat is your choice?: ";
        cin>>choice;
        int data  = 0;

        switch(choice){
            case 1:
                cout<<"data to add at end?";
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
                cout<<"data to delete?";
                cin>>data;
                list.delt(data);
                break;

            case 5:
                list.display(list.len);
                break;

            case 6:
                cout<<"index to delete?";
                cin>>data;
                list.delti(data);
                break;
            case 7:
                cout<<"data to add at begining?";
                cin>>data;
                list.addBeg(data);
                break;
        }
        
    }while(choice!=-1);

    return(0);
}