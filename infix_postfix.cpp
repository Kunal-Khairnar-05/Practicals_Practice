#include<iostream>
#include<string>
using namespace std;

class CharStack{
    int capacity;
    int top;
    char* stackArr;
    public:
        CharStack(int c){
            capacity = c;
            stackArr = new char[capacity];
            top = -1;
        }

        void push(char c){
            if(top< capacity-1){
                stackArr[++top]=c;
            }
        }

        char pop(){
            if(top>=0){
                return stackArr[--top];
            }
            return '\0';
        }

        char peek(){
            return stackArr[top];
        }

        bool isEmpty(){
            return top==-1;
        }
};

int precedence(char op){
    if(op=='+' || op=='-'){
        return 1;
    }
    if(op=='*' || op=='/'){
        return 2;
    }
    return 0;
}

bool isOperator(char c){
    return c=='*'||c=='-'||c=='+'||c=='/';
}

string intopost(string in){
    CharStack s(in.length());
    string postfix;

    for(char c : in){
        if(isalnum(c)){
            postfix+=c;
        }
        else if(c=='('){
            s.push(c);
        }
        else if(c==')'){
            while(!s.isEmpty() && s.peek()!='('){
                postfix+=s.pop();
            }
            s.pop();
        }
        else if(isOperator(c)){
            while(!s.isEmpty() && precedence(s.peek()) >= precedence(c)){
                postfix+=s.pop();
            }
            s.push(c);
        }
    }

    while(!s.isEmpty()){
        postfix+=s.pop();
    }

    return postfix;
}

int main(){
   string infix;
   cout<<"Enter infix operation to convert to postfix : ";
   cin>>infix;

   string postfix = intopost(infix);
    cout<<"\nPostfix Expression : ";
    cout<<postfix;
   return 0;
}