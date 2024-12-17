#include <iostream>
#include <set>
using namespace std;

struct Node
{
    string name;
    int PRN;
    string icecream;
    Node *next = nullptr;
};

class StudentList
{
public:
    Node *head;
    StudentList()
    {
        head = nullptr;
    }

    void addStudent(string n, int p, string i)
    {
        Node *newNode = new Node{n, p, i};

        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void deleteStudent(int p)
    {
        if (head == nullptr)
        {
            cout << "\nNo student present!";
            return;
        }
        else
        {
            Node *temp = head;
            Node *prev;

            while (temp->PRN != p && temp != nullptr)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            cout << "\nDeleted " << temp->name << " : " << temp->PRN;
            delete temp;
        }
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "\nNo any student present!";
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            cout << "\nName : " << temp->name << " PRN : " << temp->PRN << " Likes : " << temp->icecream;
            temp = temp->next;
        }
    }
    set<int> getLikers(string flav)
    {
        set<int> students;
        Node *temp = head;
        while (temp->next != nullptr)
        {
            if (temp->icecream == flav)
            {
                students.insert(temp->PRN);
            }
            temp = temp->next;
        }
        return students;
    }
};


void displaySet(set<int> s, string flav){
    if(s.empty()){
        cout<<"\nNo Student in this set !";
        return;
    }
    else{
        cout<<"\nStudents who likes "<<flav<<endl;
        for(int i:s){
            cout<<"\t"<<i;
        }
    }
}


int main()
{

    StudentList sec1, sec2;

    sec1.addStudent("Kunal1", 99, "Vanilla");
    sec1.addStudent("Kunal2", 19, "ButterScotch");
    sec1.addStudent("Kunal3", 29, "ButterScotch");
    sec1.addStudent("Kunal4", 39, "ButterScotch");
    sec1.addStudent("Kunal5", 49, "Vanilla");
    sec1.addStudent("Kunal6", 59, "Vanilla");
   
    sec2.addStudent("Kunal7", 69, "Vanilla");
    sec2.addStudent("Kunal8", 79, "ButterScotch");
    sec2.addStudent("Kunal9", 89, "ButterScotch");
    sec2.addStudent("Kunal10", 99, "ButterScotch");
    sec2.addStudent("Kunal11", 109, "Vanilla");
    sec2.addStudent("Kunal12", 119, "Vanilla");

    cout<<"\n\nStudents of section A";
    sec1.display();
    cout<<"\n\nStudents of section B";
    sec2.display();


    

    set<int> van1 = sec1.getLikers("Vanilla");
    set<int> van2 = sec2.getLikers("Vanilla");
    displaySet(van1,"Vanilla");
    displaySet(van2,"Vanilla");

    set<int> but1 = sec1.getLikers("ButterScotch");
    set<int> but2 = sec2.getLikers("ButterScotch");
    displaySet(but1,"ButterScotch");
    displaySet(but2,"ButterScotch");

    return 0;
}