#include <iostream>
using namespace std;

struct Node
{
    string name;
    int PRN;
    Node *next = nullptr;
};

class Club
{
    Node *head;

public:
    Club()
    {
        head = nullptr;
    }

    void addmember(string n, int p, bool isPresident = false, bool isSecretary = false)
    {
        Node *newNode = new Node{n, p};

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        if (isPresident)
        {
            newNode->next = head;
            head = newNode;
        }
        else if (isSecretary)
        {
            newNode->next = head->next;
            head->next = newNode;
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

    void deleteMember(int p)
    {
        if (head == nullptr)
        {
            cout << "No member is the club";
            return;
        }
        if (head->PRN == p)
        {
            Node *temp = head;
            head = head->next;
            cout << "Deleted Member : " << temp->name << " with PRN : " << temp->PRN;
            delete temp;
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
            cout << "Deleted Member : " << temp->name << " with PRN : " << temp->PRN;
            delete temp;
        }
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "No member is the club";
            return;
        }
        else
        {
            Node *temp = head;
            while (temp != nullptr)
            {
                cout << endl
                     << temp->PRN << " -> " << temp->name;
                temp = temp->next;
            }
        }
    }

    int count()
    {
        int countN = 0;
        if (head == nullptr)
        {
            cout << "No member is the club";
            return countN;
        }
        else
        {
            Node *temp = head;
            while (temp != nullptr)
            {
                countN++;
                temp = temp->next;
            }
            return countN;
        }
    }

    void concat(Club &other)
    {
        if (head == nullptr)
        {
            head = other.head;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = other.head;
        }
    }
};

int main()
{
    Club divA, divB;

    divA.addmember("Rakesh", 71, false, false);
    divA.addmember("Kunal", 99, true, false);
    divA.addmember("Rohan", 89, false, false);
    divA.addmember("Yash", 80, false, true);

    cout<<"\nTotal Members of Division A : "<<divA.count()<<endl;
    divA.display();

    divB.addmember("Rakesh", 71, false, false);
    divB.addmember("Kunal", 99, true, false);
    divB.addmember("Rohan", 89, false, false);
    divB.addmember("Yash", 80, false, true);

    cout<<"\nTotal Members of Division B : "<<divB.count()<<endl;
    divB.display();

    cout << "After Concatinating : " << endl;
    divA.concat(divB);
    cout<<"\nTotal Members After Concatination : "<<divA.count()<<endl;

    divA.display();
    return 0;
}