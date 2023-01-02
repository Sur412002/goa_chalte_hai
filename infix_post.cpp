#include<bits/stdc++.h>
using namespace std;

#define size 100
template<class T>
class Stack{
    T arr[size];
    public:
    int t;
    Stack() {
        t = -1;
    }
    T top() {
        return arr[t];
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
    T pop() {
        if(t < 0) {
            cout << "Stack Underflow\n";
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

bool op(char x) {
    if(x == '+' or x == '-' or x == '*' or x == '/') {
        return 1;
    }
    return 0;
}

void infixToPostfix(string s, vector<char> &ans) {
    map<char, int> map1;
    map1['+'] = 1;
    map1['-'] = 1;
    map1['*'] = 2;
    map1['/'] = 2; 
    Stack<char> stk;
    bool f = 0;
    for(auto i:s) {
        if(!op(i)) {
            if(i == '(') {
                stk.push(i);
            }
            else if(i == ')') {
                while(!stk.isEmpty()) {
                    if(stk.top() != '(') {
                        ans.push_back(stk.top());
                    }
                    stk.pop();
                }
            }
            else {
                ans.push_back(i);
            }
        }
        else {
            if(map1[stk.top()] > map1[i]) {
                ans.push_back(stk.pop());
            }
            stk.push(i);
        }
    }
    while(!stk.isEmpty()) {
        if(stk.top() != '(') {
            ans.push_back(stk.top());
        }
        stk.pop();
    }
}

float postfixEvaluate(string s) {
    Stack<float> stk;
    for(auto i:s) {
        if(!op(i)) {
            stk.push(i-48);
        }
        else if(op(i)) {
            float y = stk.pop();
            float x = stk.pop();
            float z;
            if(i == '+') {
                z = x + y;
            }
            else if(i == '-') {
                z = x - y;
            }
            else if(i == '*') {
                z = x * y;
            }
            else if(i == '/') {
                z = x / y;
            }
            stk.push(z);
        }
    }
    return stk.pop();
}

int main() {
    cout << "\n-----------PROGRAM FOR INFIX TO POSTFIX CONVERSION AND EVALUATION----------------\n";
    cout << "\nMENU:\n1. Infix to Postfix\n2. Postfix Evaluation\n3. Exit\n";
    do {
        cout << "\nEnter choice: ";
        int n;
        cin >> n;
        switch(n) {
            case 1: {
                cout << "\n--------------INFIX -> POSTFIX-----------------\n";
                vector<char> ans;
                string s;
                cout << "Enter the infix expression: ";
                cin >> s;
                infixToPostfix(s, ans);
                cout << "Postfix expression: ";
                for(auto i:ans) {
                    cout << i;
                }
                cout << endl;
                break;
            }
            case 2: {
                cout << "\n-----------------POSTFIX EVALUATION------------------\n";
                cout << "Enter the postfix expression: ";
                string s;
                cin >> s;
                cout << "Value of the given PostFix expression: " << fixed << setprecision(2) << postfixEvaluate(s) << endl; 
                break; 
            }
            case 3:
                cout << "\n----------------EXITING---------------------\n";
                exit(0);       
        }
    }
    while(true);
}


// OUTPUT:
// PS H:\Coding\FDS\expt>  & 'c:\Users\Dell\.vscode\extensions\ms-vscode.cpptools-1.12.4-win32-x64\debugAdapters\bin\WindowsDebugLauncher.exe' '--stdin=Microsoft-MIEngine-In-out4izh0.5oe' '--stdout=Microsoft-MIEngine-Out-r31r2we0.aqf' '--stderr=Microsoft-MIEngine-Error-k5sgs0cs.05h' '--pid=Microsoft-MIEngine-Pid-0etpztpc.32s' '--dbgExe=C:\MinGW\bin\gdb.exe' '--interpreter=mi' 

// -----------PROGRAM FOR INFIX TO POSTFIX CONVERSION AND EVALUATION----------------

// MENU:
// 1. Infix to Postfix
// 2. Postfix Evaluation
// 3. Exit

// Enter choice: 1

// --------------INFIX -> POSTFIX-----------------
// Enter the infix expression: (A+B)/(C+D)*(E-F)*G
// Postfix expression: AB+CD+/EF-*G*

// Enter choice: 2

// -----------------POSTFIX EVALUATION------------------
// Enter the postfix expression: 23+4*759+/-
// Value of the given PostFix expression: 19.50

// Enter choice: 3

// ----------------EXITING---------------------

