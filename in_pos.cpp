#include<iostream>
#include<string>
using namespace std;

class Stack{
        int top;
        int capacity;
        char *stackArr;
    public:
        Stack(int len){
            top=-1;
            capacity = len;
            stackArr = new char[capacity];
        }

        void push(char c){
            if(top<capacity){
                stackArr[++top]=c;
            }
        }

        char pop(){
            if(top>=0){
                return stackArr[top--];
            }
            return '\0';
        }

        char peek(){
            if(top>=0){
                return stackArr[top];
            }
            return '\0';
        }

        bool isEmpty(){
            return top<0;
        }
};

int precedence(char c){
    if(c=='+' || c=='-')
        return 1;
    if(c=='*' || c=='/')
        return 2;
}

bool isOperator(char c){
    return c=='*'||c=='/'||c=='+'||c=='-';
}

string in_to_pos(string s){
    Stack str(s.length());

    string postfix;

    for(int i=0;i<s.length(); i++){
        if(isalnum(s[i])){
            postfix+=s[i];
        }
        if(s[i]=='('){
            str.push(s[i]);
        }
        if(s[i]==')'){
            while(str.peek()!='('){
                postfix+= str.pop();
            }
            str.pop();
        }
        if(isOperator(s[i])){
            while(str.isEmpty() && precedence(s[i]) <= precedence(str.peek())){
                postfix+=str.pop();
            }
            str.push(s[i]);
        }
    }

    while(!str.isEmpty()){
        postfix+=str.pop();
    }

    return postfix;

}

int main(){
   string infix;
   cout<<"Enter Infix : ";
   cin>>infix;

   string postfix = in_to_pos(infix);
   cout<<"\n Postfix : "<<postfix;
   return 0;
}