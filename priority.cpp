#include<iostream>
#include<string>
#include<set>
using namespace std;

template<typename T>
class PriorityQueue{
    T data;
    int priority;
    public:
        PriorityQueue(T d, int p){
            data = d;
            priority = p;
        }

        bool operator <(const PriorityQueue& p) const{
            return this->priority < p.priority;
        }

        bool operator <=(const PriorityQueue& p) const {
            return this->priority <= p.priority;
        }

        void display(){
            cout<<"\nData : "<<data<<" Priority : "<<priority;
        }
};


int main(){
   set<PriorityQueue<string>> itemlist;

   itemlist.insert(PriorityQueue<string>("Myjob1",4));
   itemlist.insert(PriorityQueue<string>("Myjob2",1));
   itemlist.insert(PriorityQueue<string>("Myjob3",2));
   itemlist.insert(PriorityQueue<string>("Myjob4",6));
   itemlist.insert(PriorityQueue<string>("Myjob5",8));
   itemlist.insert(PriorityQueue<string>("Myjob0",3));
   itemlist.insert(PriorityQueue<string>("Myjob6",9));

   for(auto i:itemlist){
    i.display();
   }
   return 0;
}