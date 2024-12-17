#include<iostream>
#include<string.h>

using namespace std;

class Stack{
    int top;
    int capacity;
    char *stackArray;

    public:
        Stack(int capacity){
            this->capacity=capacity;
            stackArray = new char[capacity];
            top= -1;
        }

        void push(char c){
            if(top<capacity){
                stackArray[++top] = c;
            }
            else{
                cout<<"Stack Overflowed";
            }
        }

        char pop(){
            if(top>=0){
                return stackArray[top--];
            }
            else{
                cout<<"Stack Underflowed";
            }
        }

};

bool isPalindrome(string str){
    int len = str.length();
            
    Stack stack(len);

    for(int i=0; i<len; i++){
        stack.push(str[i]);
    }

    for(int i=0; i<len; i++){
        if(str[i] != stack.pop()){
            return false;
        }
    }
    return true;
}


int main(){
    string str;
    cout<<"Enter the string : ";
    cin >> str;

    if(isPalindrome(str)){
        cout<<"Yesss! Palindrome";
    }
    else{
        cout<<"Not Palindrome";
    }
    
   return 0;
}