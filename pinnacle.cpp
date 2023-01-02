#include<bits/stdc++.h>
using namespace std;

struct Node {
    string PRN;
    int roll;
    string name;
    Node *next;
};

class LinkedList {
    int t;
    Node *pr;
    Node *sr;
    public:
    LinkedList() {
        pr = new Node;
        sr = new Node;
        pr -> PRN = "-";
        pr -> next = sr;
        sr -> PRN = "-";
        sr -> next = NULL;
        t = 0;
    }
    void addP() {
        string PRN; string name;
        cout << "Enter PRN: ";
        cin.ignore();
        getline(cin, PRN);
        cout << "Enter name: ";
        getline(cin, name);
        pr -> PRN = PRN;
        pr -> name = name;
        t ++;
    }
    void addS() {
        string PRN; string name;
        cout << "Enter PRN: ";
        cin.ignore();
        getline(cin, PRN);
        cout << "Enter Name: ";
        getline(cin, name);
        sr -> PRN = PRN;
        sr -> name = name;
        t ++;
    }
    void addM() {
        string PRN; string name;
        cout << "Enter PRN: ";
        cin.ignore();
        getline(cin, PRN);
        cout << "Enter Name: ";
        getline(cin, name);
        Node *ptr = new Node;
        ptr -> PRN = PRN;
        ptr -> name = name;
        Node *tmp = pr;
        while(tmp -> next != sr) {
            tmp = tmp -> next;
        }
        tmp -> next = ptr;
        ptr -> next = sr;
        t ++;
    }
    void deleteM() {
        cout << "Enter PRN of member to remove: ";
        string PRN;
        cin.ignore();
        getline(cin, PRN);
        Node *tmp = pr;
        while(tmp -> next != sr) {
            if(tmp -> next ->PRN == PRN) {
                break;
            }
            tmp = tmp -> next;
        }
        cout << "MEMBER " << tmp -> next -> name << " REMOVED\n";
        tmp -> next = tmp -> next -> next;
        t --;
    }
    void deleteP() {
        pr -> PRN = -1;
        t --;
    }
    void deleteS() {
        sr -> PRN = -1;
        t --;
    }
    void display() {
        int cnt = 1;
        cout << "\n------------------DISPLAYING PINNACLE CLUB----------------\n";
        cout << "--------------PRESIDENT----------------\n";
        if(pr -> PRN == "-") {
            cout << "NOT APPOINTED\n";
        }
        else {
            cout << cnt << ". " << "PRN: " << pr -> PRN << endl;
            cout << "   " "NAME: " << pr -> name << endl;
            cnt ++;
        }
        cout << "---------------------------------------\n";
        Node *tmp = pr -> next;
        while(tmp != sr) {
            cout << cnt << ". " << "PRN: " << tmp -> PRN << endl;
            cout << "   " << "NAME: " << tmp -> name << endl;
            cout << "-----------------------------------------\n";
            tmp = tmp -> next;
            cnt ++;
        }    
        cout << "--------------SECRETARY----------------\n";
        if(sr -> PRN == "-") {
            cout << "NOT APPOINTED\n";
        }
        else {
            cout << cnt << ". " << "PRN: " << sr -> PRN << endl;
            cout << "   " "NAME: " << sr -> name << endl;
            cnt ++;
        }
        cout << "---------------------------------------\n";
        cout << "TOTAL MEMBERS: " << t << endl;
        cout << "---------------------------------------\n";
    }
    bool isEmpty() {
        if(pr -> next == sr) {
            return 1;
        }
        return 0;
    }
    void displayReverse() {
        cout << "\n--------------DISPLAYING LIST IN REVERSE ORDER USING RECURSION--------------\n";
        int cnt = 1;
        rec(pr,cnt);
        cout << "\n";
    }
    int rec(Node *ptr, int cnt) {
        if(ptr == sr) {
            cout << "--------------SECRETARY----------------\n";
            if(sr -> PRN == "-") {
                cout << "NOT APPOINTED\n";
            }
            else {
                cout << cnt << ". " << "PRN: " << sr -> PRN << endl;
                cout << "   " "NAME: " << sr -> name << endl;
                cnt ++;
            }
            cout << "---------------------------------------\n";
            return cnt;
        }
        int c = rec(ptr -> next,cnt);
        if(ptr != pr) {
            cout << c << ". " << "PRN: " << ptr -> PRN << endl;
            cout << "   " << "NAME: " << ptr -> name << endl;
            cout << "-----------------------------------------\n";
            ptr = ptr -> next;
            c ++;
        }
        else {
            cout << "--------------PRESIDENT----------------\n";
            if(pr -> PRN == "-") {
                cout << "NOT APPOINTED\n";
            }
            else {
                cout << c << ". " << "PRN: " << pr -> PRN << endl;
                cout << "   " "NAME: " << pr -> name << endl;
                c ++;
            }
            cout << "---------------------------------------\n";
            cout << "TOTAL MEMBERS: " << t << endl;
            cout << "---------------------------------------\n";          
        }
        return c;
    }
    int total() {
        return t;
    }
};

int main() {
    cout << "----------WELCOME TO PINNACLE CLUB---------------\n";
    LinkedList l;
    cout << "MENU: \n";
    cout << "1. Add President\n2. Add Secretary\n3. Add member\n4. Delete President / Secretary / member\n5. Compute total no. of members\n6. Display members\n7. Display List in reverse order\n8. Concatenate two LL\n9. Exit\n";
    do {
        cout << "Enter no. of operation: ";
        int n;
        cin >> n;
        switch(n) {
            case 1:
                l.addP();
                break;
            case 2:
                l.addS();
                break;
            case 3:
                l.addM();
                break;
            case 4:
                cout << "1. President\n2. Secretary\n3. Member\n";
                cout << "Who you want to delete: ";
                int ch;
                cin >> ch;
                switch(ch) {
                    case 1:
                        l.deleteP();
                        break;
                    case 2:
                        l.deleteS();
                        break;
                    case 3:
                        l.deleteM();
                        break;
                    default: break;
                }
                break;
            case 5:
                cout << "TOTAL MEMBERS: " << l.total() << endl;
                break;
            case 6:
                l.display();
                break;
            case 7:
                l.displayReverse();
                break;
            case 8: {
                cout << "\n--------------------------CONCATENATING TWO LINKED LISTS---------------------------\n";
                cout << "\nWe will take input of list Roll No.s of students of Divison A and Divsion B and then concatenate the two lists\n\n";
                cout << "Enter Roll No.s of Div. A students:(Enter -1 to terminate) \n";
                int x = 0;
                Node *head1 = NULL, *head2 = NULL;
                Node *temp;
                while(x != -1) {
                    cin >> x;
                    if(x == -1) {
                        break;
                    }
                    temp = head1;
                    Node *ptr = new Node;
                    ptr -> roll = x;
                    ptr -> next = NULL;
                    if(head1 == NULL) {
                        head1 = ptr;
                    }
                    else {
                        while(temp -> next != NULL) {
                            temp = temp -> next;
                        }
                        temp -> next = ptr;
                    }
                }
                cout << "\nEnter Roll No.s of Div. B students:(Enter -1 to terminate) \n";
                x = 0;
                while(x != -1) {
                    cin >> x;
                    if(x == -1) {
                        break;
                    }
                    temp = head2;
                    Node *ptr = new Node;
                    ptr -> roll = x;
                    ptr -> next = NULL;
                    if(head2 == NULL) {
                        head2 = ptr;
                    }
                    else {
                        while(temp -> next != NULL) {
                            temp = temp -> next;
                        }
                        temp -> next = ptr;
                    }
                    
                }
                Node *tmp = head1;
                cout << "\nDIVISION A: ";
                while(tmp -> next != NULL) {
                    cout << tmp -> roll << " -> ";
                    tmp = tmp -> next;
                }
                cout << tmp -> roll << endl;
                tmp = head2;
                cout << "DIVISION B: ";
                while(tmp -> next != NULL) {
                    cout << tmp -> roll << " -> ";
                    tmp = tmp -> next;
                }
                cout << tmp -> roll << endl;
                tmp = head1;
                while(tmp -> next != NULL) {
                    tmp = tmp -> next;
                }
                tmp -> next = head2;
                cout << "\nCONCATENATED: ";
                tmp = head1;
                while(tmp -> next != NULL) {
                    cout << tmp -> roll << " -> ";
                    tmp = tmp -> next;
                }
                cout << tmp -> roll << endl;
                cout << "------------------------------------------------------------------------\n";
                break;
            }
            case 9:
                cout << "-------------EXITING--------------\n";
                exit(0);
                
        }
    }
    while(true);
} 

