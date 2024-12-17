#include<iostream>
using namespace std;

#define MAX 4

class JobQueue{
    string jobs[MAX];
    int front;
    int rear;
    int count;
    public:
        JobQueue(){
            front = 0;
            rear = -1;
            count = 0;
        }

        void AddJob(const string job){
            if(count==MAX){
                cout<<"Queue is full";
                return;
            }
            else{
                rear = (rear+1)%MAX;
                jobs[rear]=job;
                count++;
                cout<<"Job Added!";
            }
        }

        void deleteJob(){
            if(count==0){
                cout<<"No any jon in the queue";
                return;
            }
            else{
                cout<<"Job deleted : "<<jobs[front]<<endl;
                front = (front+1)%MAX;
                count--;
            }
        }

        void display(){
            if(count==0){
                cout<<"Queue is empty";
                return;
            }
            else{
                cout<<"\nCurrent jobs in the queue :";
                for(int i=0; i<count;i++){
                    cout<<jobs[(front+i)%MAX]<<" ";
                }
            }
        }
};

int main(){
   JobQueue jq;

   jq.AddJob("Job 1");
   jq.AddJob("Job 2");
   jq.AddJob("Job 3");
   jq.AddJob("Job 4");
   jq.AddJob("Job 5");

   jq.deleteJob();
   jq.deleteJob();
   jq.deleteJob();

   jq.AddJob("Job 6");
   jq.AddJob("Job 7");
   jq.AddJob("Job 8");
   jq.AddJob("Job 9");

   jq.display();
   return 0;
}