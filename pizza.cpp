#include<iostream>
#include<string>
using namespace std;

#define M 5

class Queue{
    public:
    int front;
    int rear;
    int count;
    string Pizzler[M];
        Queue(){
            front = 0;
            rear=-1;
            count =0;
        }

        void enqueue(string pizza){
           if(count == M){
            cout<<"\nQueue is full!";
            return;
           }
           rear = (rear+1)%M;
           Pizzler[rear]=pizza;
           count++;
           cout<<"\nPizza Added to Queue";
        }

        void dequeue(){
            if(count<=0){
                cout<<"\nQueue is empty!";
                return;
            }
            else{
                cout<<"\nOrder of "<<Pizzler[front]<<" is placed!";
                front = (front+1)%M;
                count--;
            }
        }

        void display(){
            if(count==0){
                cout<<"\nQueue is empty!";
                return;
            }
            else{
                for(int i=0;i<count;i++){
                    cout<<Pizzler[(front+i)%M]<<endl;
                }
            }
        }
};

int main(){
   Queue q;
   q.enqueue("Magaretta");
   q.enqueue("Spicy Delight");
   q.enqueue("Paparroni");
   q.enqueue("Paneer Pizza");
   q.enqueue("Magaretta");

   q.display();

   q.dequeue();
   q.dequeue();
   q.dequeue();

   q.display();
   return 0;
}