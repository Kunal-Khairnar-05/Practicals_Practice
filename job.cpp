#include<iostream>
#include<string>
using namespace std;

#define capacity 5

class JobQ{
    int front;
    int rear;
    string jobs[capacity];
    int count;
    public:
        JobQ(){
            front = 0;
            rear = -1;
            count = 0;
        }

        void enqueue(string j){
            if(count == capacity){
                cout<<"\nQueue is full!";
                return;
            }
            else{
                rear = (rear+1)%capacity;
                jobs[rear]=j;
                count++;
                cout<<"\nJob Added!";
            }
        }

        void dequeue(){
            if(count==0){
                cout<<"\n Queue is already empty!";
                return;
            }
            else{
                front = (front+1)%capacity;
                count--;
                cout<<"\nJob removed!";
            }
        }

        void display(){
            if(count==0){
                cout<<"\n Queue is already empty!";
                return;
            }
            else{
                for(int i=0; i<count; i++){
                    cout<<"\nJob : "<<jobs[(front+i)%capacity];
                }
            }
        }
};

int main(){
   JobQ j;

   j.enqueue("MyJob1");
   j.enqueue("MyJob2");
   j.enqueue("MyJob3");
   j.enqueue("MyJob4");
   j.enqueue("MyJob5");
   j.enqueue("MyJob6");

   j.display();

   j.dequeue();
   j.dequeue();
   j.dequeue();
   j.dequeue();

   j.enqueue("MyJob7");
   j.enqueue("MyJob8");
   j.enqueue("MyJob9");
   j.enqueue("MyJob10");

   j.display();

   return 0;
}