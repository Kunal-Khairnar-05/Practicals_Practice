#include<iostream>
#include<string.h>

using namespace std;

struct Node{
    int prn;
    string name;
    Node* next;
} *head;

class Club{
    public:
        Club(){
            head=nullptr;
        }
        void addMember(int prn, string name, bool isPresident, bool isSecretary){
            Node * newNode = new Node{prn, name, nullptr};

            if(isPresident){
                newNode->next = head;
                head = newNode;
            }
            else{
                if(head==nullptr){
                    head=newNode;
                }
                else{
                Node * temp = head;
                while(temp->next!=nullptr){
                    temp=temp->next;
                }
                temp->next=newNode;
                }
            }
        }

        void Display(){
            if(head==nullptr){
                cout<<"Club is Empty";
            }
            else{
                Node *temp = head;
                while(temp!=nullptr){
                    cout<<"\nPRN : "<<temp->prn;
                    cout<<"\nName : "<<temp->name;

                    temp = temp->next;
                }
            }
        }

        void deleteNode(int prn){
            if(head==nullptr){
                cout<<"Club is empty";
            }
            else{
                Node *temp = head;
                Node *prev;

                while(temp->next != nullptr && temp->prn != prn){
                    prev = temp;
                    temp = temp->next;
                }
                prev->next = temp->next;
                cout<<"Deleted : "<<temp->prn;
                delete temp;
            }
        }

};

int main(){
    Club mem1;
    mem1.addMember(832,"Rajesh",true,false);
    mem1.addMember(214, "Rohan",false,true);
    mem1.addMember(992,"Ram",false,false);
    mem1.Display();
    mem1.deleteNode(214);
    mem1.Display();
   return 0;
}