#include<iostream>
#include<string>
using namespace std;

#define SIZE 5

class Stack{
    int top;
    char* stackArr;
    public:
        Stack(){
            stackArr = new char[SIZE];
            top = -1;
        }

        void push(char c){
            if (top==SIZE-1){
                cout<<"Stack overflow";
                return;
            }
            else{
                stackArr[++top]=c;
            }
        }

        char pop(){
            if(top>=0){
               return stackArr[top--]; 
            }
            else{
                cout<<"Stack Underflow";
                return '\0';
            }
        }

        bool isEmpty(){
            return top == -1;
        }

        ~Stack(){
            delete []stackArr;
        }
};

bool isPalindrome(string &s){
    Stack st;

    for(int i=0; i<SIZE; i++){
        st.push(s[i]);
    }

    for(int i=0; i<SIZE; i++){
        if(s[i]!=st.pop()){
            return false;
        }
    }
    return true;
}

int main(){
   cout<<"Enter String to check if palindrome or not : ";
   string s;
   cin>>s;

   if(isPalindrome(s)){
    cout<<s<<" is palindrome";
   }
   else{
    cout<<s<<" is not palindrome";
   }
   return 0;
}