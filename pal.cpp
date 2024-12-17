#include<iostream>
#include<string>
using namespace std;

class Stack{
    int top;
    int capacity;
    char* stackArr;

    public:
        Stack(int c){
            top=-1;
            capacity = c;
            stackArr = new char[capacity];
        }

        void push(int c){
            if(top!=capacity-1){
                stackArr[++top]=c;
            }
        }

        char pop(){
            if(top>=0){
                return stackArr[top--];
            }
        }
};


bool isPalindrome(const string s){
    int len = s.length();
    Stack str(len);

    for(int i=0; i<len; i++){
        str.push(s[i]);
    }

    for(int i=0; i<len; i++){
        if(str.pop()!=s[i]){
            return false;
        }
    }
    return true;
}


int main(){
   cout<<"Enter String to check if palindrome!";
   string str;
   cin>>str;

   if(isPalindrome(str)){
    cout<<endl<<str<<" is palindrome!";
   } 
   else{
    cout<<endl<<str<<" is not a palindrome!";
   }
   return 0;
}