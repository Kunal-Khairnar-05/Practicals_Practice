#include<iostream>
using namespace std;

#define size 5

class Deque{
    private:
        int rear;
        int front;
        int Que[size];
    public:
        Deque(){
            rear = -1;
            front= -1;
        }

        bool isfull(){
            if((front == 0 && rear== size-1) || (front == rear+1)){
                return true;
            }
            return false;
        }
        void insertBeg(int value){
            if(front == rear == -1){
                front = rear = 0;
            }
            
            if(front==0){
                front = size-1;
            }
        }
};
int main(){
   
   return 0;
}