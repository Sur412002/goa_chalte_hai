#include<bits/stdc++.h>
using namespace std;

#define size 100
template<class T>
class Stack{
    T arr[100];
    public:
    int t;
    Stack() {
        t = -1;
    }
    void push(T x) {
        if(t == size-1) {
            cout << "Stack Overflow\n";
        }
        else {
            t ++;
            arr[t] = x;
        }
    }
    int pop() {
        if(t < 0) {
            //cout << "Stack Underflow\n";
            return -1;
        }
        T x = arr[t];
        t --;
        return x;
    }
    void display() {
        for(int i = 0; i <= t; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    bool isEmpty() {
        if(t < 0) {
            return 1;
        }
        return 0;
    }
};

bool checkParentheses(string s) {
    Stack<char> stk;
    for(auto i:s) {
        if(i == '(' or i == '[' or i == '{') {
            stk.push(i);
        }
        if(i == ')') {
            int x = stk.pop();
            if(x == -1 or x != '(') {
                return 0;
            }
        }
        else if(i == ']') {
            int x = stk.pop();
            if(x == -1 or x != '[') {
                return 0;
            }
        }
        else if(i == '}') {
            int x = stk.pop();
            if(x == -1 or x != '{') {
                return 0;
            }
        }
    }
    if(!stk.isEmpty()) {
        return 0;
    }
    return 1;
}   

int main() {
    cout << "\n--------------PROGRAM TO CHECK BALANCED PARENTHESES-----------------\n";
    cout << "MENU: \n1. Check Balanced Parentheses\n2. Exit";
    do {
        cout << "\nEnter choice: ";
        int n;
        cin >> n;
        switch(n) {
            case 1: {
                cout << "Enter the expression: ";
                string s;
                cin >> s;
                if(checkParentheses(s)) {
                    cout << "BALANCED\n";
                }
                else {
                    cout << "NOT BALANCED\n";
                }
                break;
            }
            case 2:
                cout << "\n----------------EXITING---------------\n";
                exit(0);
        }
    }
    while(true);
}
