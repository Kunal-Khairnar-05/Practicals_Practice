#include<iostream>
#include<vector>
using namespace std;

class Item{
    public:
        int data;
        int priority;
        Item(int d, int p): data(d), priority(p){}

        bool operator<=(const Item& item){
            return priority < item.priority;
        }

};

class Priority_Queue{
    private:
        vector<Item> pqueue;
    public:
        void enqueue(int data, int prior){
            Item newItem(data, prior);

            if(pqueue.empty() || pqueue[0].priority < prior){
                pqueue.insert(pqueue.begin(), newItem);
                return;
            }
            else{
                for(int i=0; i<pqueue.size(); i++){
                    if(pqueue[i].priority<prior){
                        pqueue.insert(pqueue.begin()+i, newItem);
                        return;
                    }
                }
            }

            pqueue.push_back(newItem);
        }


        void dequeue(){
            if(pqueue.empty()){
                cout<<"Queue is already empty!";
            }
            else{
                cout<<"Deleting eliment "<<pqueue.front().data<<" with priority "<<pqueue.front().priority<<endl;
                pqueue.erase(pqueue.begin());
            }
        }

        void display(){
            if(pqueue.empty()){
                cout<<"\nQueue is empty!";
            }
            else{
                for(const auto i:pqueue){
                    cout<<i.data<<"->"<<i.priority<<endl;
                }
            }
        }
};

int main(){
   Priority_Queue pq;
   pq.enqueue(10,3);
   pq.enqueue(4,6);
   pq.enqueue(1,9);
   pq.enqueue(23,2);
   pq.enqueue(11,3);

   pq.display();

   pq.dequeue();
   pq.dequeue();
   pq.dequeue();
   pq.dequeue();
   pq.dequeue();
   pq.dequeue();

   pq.display();
   return 0;
}