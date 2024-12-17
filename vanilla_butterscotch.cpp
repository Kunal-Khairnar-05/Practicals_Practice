#include <iostream>
#include <set>
#include <string>
using namespace std;

struct Node
{
    int rollnumber;
    string name;
    string icecream;
    Node *next = nullptr;
};

class StudentList
{
    Node *head;

public:
    StudentList()
    {
        head = nullptr;
    }

    void addStudent(string n, int r, string flav)
    {
        Node *newNode = new Node{r, n, flav};
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

    set<int> getIcecreamLikers(string flav)
    {
        set<int> Likers;
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->icecream == flav)
            {
                Likers.insert(temp->rollnumber);
            }
            temp=temp->next;
        }
        return Likers;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "\nNo student present!";
            return;
        }
        else
        {
            Node *temp = head;
            while (temp != nullptr)
            {
                cout << "\nName :" << temp->name << " Roll no: " << temp->rollnumber << " Fav Icecream : " << temp->icecream;
                temp = temp->next;
            }
        }
    }
};
void printSet(set<int> &s, string flav)
{
    cout << "\nStudents who like " << flav << " :" << endl;
    for (int i : s)
    {
        cout << i << "\t";
    }
    cout << endl;
}

int main()
{
    StudentList sectionA, sectionB;

    sectionA.addStudent("Kunal", 99, "ButterScotch");
    sectionA.addStudent("Rahul", 90, "Vanilla");
    sectionA.addStudent("Rohan", 89, "ButterScotch");
    sectionA.addStudent("Bhargav", 29, "ButterScotch");

    sectionB.addStudent("Chandu", 88, "Vanilla");
    sectionB.addStudent("Sanyog", 80, "ButterScotch");
    sectionB.addStudent("Vedant", 73, "Vanilla");
    sectionB.addStudent("Yash", 77, "ButterScotch");

    cout << "\nStudents in Section A : ";
    sectionA.display();
    cout << "\n\nStudents in Section B : ";
    sectionB.display();

    set<int> vanA = sectionA.getIcecreamLikers("Vanilla");
    set<int> butA = sectionA.getIcecreamLikers("ButterScotch");
    set<int> vanB = sectionB.getIcecreamLikers("Vanilla");
    set<int> butB = sectionB.getIcecreamLikers("ButterScotch");

    cout<<"\nButterScotch Likers : ";
    printSet(butA,"ButterScotch (A)");
    printSet(butB,"ButterScotch (B)"); 

    cout<<"\nVanilla Likers : ";
    printSet(vanA,"Vanilla (A)");
    printSet(vanB,"Vanilla (B)");

    return 0;
}