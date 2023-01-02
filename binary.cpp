#include<bits/stdc++.h>
using namespace std;

class binary{
    struct node{
        char d;
        node *next;
        node *prev;
    };
    int t;
    node *head;
    public:
    binary() {
        t = 0;
        head = NULL;
    }
    node *getlast() {
        node *tmp = head;
        while(tmp -> next != NULL) {
            tmp = tmp -> next;
        }
        return tmp;
    }
    node *getHead() {
        return head;
    }
    int len() {
        return t;
    }
    void input() {
        string s;
        cin >> s;
        for(auto i:s) {
            node *ptr = new node;
            ptr -> d = i;
            ptr -> next = NULL;
            ptr -> prev = NULL;
            if(head == NULL) {
                head = ptr;
                t ++;
                continue;
            }
            node *tmp = head;
            while(tmp -> next != NULL) {
                tmp = tmp -> next;
            }
            tmp -> next = ptr; ptr -> prev = tmp;
            t ++;
        }
    }
    string onesComplement() {
        string t = "";
        node *tmp = head;
        while(tmp != NULL) {
            if(tmp -> d == '0') {
                tmp -> d = '1';
            }
            else {
                tmp -> d = '0';
            }
            t += tmp -> d;
            tmp = tmp -> next;
        }
        return t;
    }
    string twosComplement() {
        string t = "";
        node *tmp = head;
        while(tmp -> next != NULL) {
            if(tmp -> d == '0') {
                tmp -> d = '1';
            }
            else {
                tmp -> d = '0';
            }
            tmp = tmp -> next;
        }
        bool c = 0;
        if(tmp -> d == '0') {
            t += '0';
            c = 1;
        }
        if(tmp -> d == '1') {
            t += '1';
        }
        tmp = tmp -> prev;
        while(tmp != NULL) {
            if(c and tmp -> d == '0') {
                tmp -> d = '1';
                c = 0;
            } 
            else if(c and tmp -> d == '1') {
                tmp -> d = '0';
            }
            t += tmp -> d;
            tmp = tmp -> prev;
        }
        if(c) {
            t += '1';
        }
        reverse(t.begin(),t.end());
        return t;
    }
    string add(binary b) {
        string t = "";
        int n1 = this -> len();
        int n2 = b.len();
        if(n1 > n2) {
            for(int i = 0; i < n1 - n2; i++) {
                node *ptr = new node;
                ptr -> d = '0';
                ptr -> next = NULL;
                ptr -> prev = NULL;
                if(head == NULL) {
                    head = ptr;
                    continue;
                }
                ptr -> next = head;
            }
        }
        if(n2 > n1) {
            for(int i = 0; i < n2 - n1; i++) {
                node *ptr = new node;
                ptr -> d = '0';
                ptr -> next = NULL;
                ptr -> prev = NULL;
                if(b.getHead() == NULL) {
                    head = ptr;
                    continue;
                }
                ptr -> next = b.getHead();
            }
        }
        bool c = 0;
        node *l1 = this -> getlast();
        node *l2 = b.getlast();
        while(l1 != NULL) {
            if(l1 -> d == '0' and l2 -> d == '0') {
                if(!c) {
                    t += '0';
                }
                else {
                    t += '1';
                    c = 0;
                }
            }
            else if(l1 -> d == '1' and l2 -> d == '0' or l1 -> d == '0' and l2 -> d == '1') {
                if(c) {
                    t += '0';
                }
                else {
                    t += '1';
                }
            }
            else {
                if(c) {
                    t += '1';
                }
                else {
                    t += '0';
                    c = 1;
                }
            }
            l1 = l1 -> prev;
            l2 = l2 -> prev;
        }
        if(c) {
            t += '1';
        }
        reverse(t.begin(),t.end());
        return t;
    }
};

int main() {
    cout << "\n------------PROGRAM FOR OPERATION ON BINARY NUMBERS USING DOUBLY LINKED LIST-------------\n";
    cout << "MENU: \n1. 1's Complement\n2. 2's Complement\n3. Addition of two binary numbers\n4. Exit\n";
    do {
        cout << "\nEnter choice: ";
        int n;
        cin >> n;
        switch(n) {
            case 1: {
                cout << "Enter the binary number: ";
                binary b;
                b.input();
                cout << "1's COMPLEMENT: ";
                cout << b.onesComplement();
                cout << endl;
                break;
            }
            case 2: {
                cout << "Enter the binary number: ";
                binary b;
                b.input();
                cout << "2's COMPLEMENT: ";
                cout << b.twosComplement();
                cout << endl;
                break;    
            }
            case 3: {
                binary b1, b2;
                cout << "Enter first binary number: ";
                b1.input();
                cout << "Enter second binary number: ";
                b2.input();
                cout << "SUM: ";
                cout << b1.add(b2) << endl;   
                break;
            }
            case 4:
                cout << "\n---------EXITING---------\n";
                exit(0);
        }
    }
    while(true);
}

