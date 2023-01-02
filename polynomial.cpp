#include<bits/stdc++.h>
using namespace std;

struct p{
    int e;
    int c;
};

void displayS(p* p3, int idx) {
    bool c = 1;
    for(int i = 0; i < idx; i++) {
        if(p3[i].c > 0) {
            if(!c) {
                cout << " + ";
            }
            if(p3[i].c > 1) {
                cout << p3[i].c;
            }
            if(p3[i].c == 1 and p3[i].e == 0) {
                cout << 1;
            }
            if(p3[i].e > 0) {
                cout << "X";
            }
            if(p3[i].e > 1) {
                cout << "^" << p3[i].e;
            }
            c = 0;
        }
    }
    cout << endl;
}

void display(int* p3, int n3) {
    bool c = 1;
    for(int i = n3-1; i >= 0; i--) {
        if(p3[i] > 0) {
            if(!c) {
                cout << " + ";
            }
            if(p3[i] > 1)
                cout << p3[i];
            if(i > 0) {
                cout << "X";
            }
            if(i > 1) {
                cout << "^" << i;
            }
            c = 0;
        }
    }
    cout << endl;
}

void multiply(p* p1, int n1, p* p2, int n2, int* p3) {
    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < n2; j++) {
            p3[p1[i].e + p2[j].e] += p1[i].c * p2[j].c;
        }
    }
}

p* add(p* p1, int n1, p* p2, int n2, p* p3, int &n3) {
    int idx = 0;
    int i = 0;
    int j = 0;
    for(int i = 0; i < n1+n2; i++) {
        p3[i].e = -1;
    }
    while(i < n1 && j < n2) {
        if(p1[i].e > p2[j].e) {
            if(idx == 0) {
                p3[idx].e = p1[i].e;
                p3[idx++].c = p1[i++].c;
                continue;
            }
            if(p1[i].e == p3[idx-1].e) {
                p3[idx-1].c += p1[i++].c;
            }
            else {
                p3[idx].e = p1[i].e;
                p3[idx++].c = p1[i++].c;
            }
        }
        else {
            if(idx == 0) {
                p3[idx].e = p2[j].e;
                p3[idx++].c = p2[j++].c;
                continue;
            }
            if(p2[j].e == p3[idx-1].e) {
                p3[idx-1].c += p2[j++].c;
            }
            else {
                p3[idx].e = p2[j].e;
                p3[idx++].c = p2[j++].c;
            } 
        }
        n3 = idx;
    }
    if(i == n1) {
        while(j < n2) {
            if(p2[j].e == p3[idx-1].e) {
                p3[idx-1].c += p2[j++].c;
            }
            else {
                p3[idx].e = p2[j].e;
                p3[idx++].c = p2[j++].c;
            }             
        }
    }
    else {
        while(i < n1) {
            if(p1[i].e == p3[idx-1].e) {
                p3[idx-1].c += p1[i++].c;
            }
            else {
                p3[idx].e = p1[i].e;
                p3[idx++].c = p1[i++].c;
            }           
        }
    }
    return p3;
}

int evaluate(p *arr, int n, int x) {
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += arr[i].c * pow(x,arr[i].e);
    }
    return ans;
}

int main() {
    cout << "\n-----------------PROGRAM FOR POLYNOMIAL OPERATIONS USING ARRAY OF STRUCTURES-------------------\n";
    cout << "MENU: \n1. EVALUATE\n2. ADDITON\n3. MULTIPLICATION\n";
    do {
        cout << "\nENTER CHOICE: ";
        int n;
        cin >> n;
        switch(n) {
            case 1: {
                cout << "\n-----------------------------EVALUATION----------------------------\n";
                cout << "ENTER NO. OF TERMS: ";
                int n;
                cin >> n;
                p arr[100] = {};
                for(int i = 0; i < n; i++) {
                    cout << "ENTER EXPONENT: ";
                    cin >> arr[i].e;
                    cout << "ENTER COEFFICIENT: ";
                    cin >> arr[i].c;
                }
                cout << "\nPOLYNOMIAL: ";
                displayS(arr,n);
                cout << "\nENTER VALUE OF X: ";
                int x;
                cin >> x;
                cout << "\nVALUE OF POLYNOMIAL: " << evaluate(arr,n,x) << endl;
                cout << "\n---------------------------------------------------------------------\n";
                break;
            }
            case 2: {
                cout << "\n-----------------------------ADDITION----------------------------\n";
                cout << "\n----------------------INPUT FIRST POLYNOMIAL-----------------------\n";
                cout << "ENTER NO. OF TERMS: ";
                int n1;
                cin >> n1;
                p arr1[100] = {};
                for(int i = 0; i < n1; i++) {
                    cout << "ENTER EXPONENT: ";
                    cin >> arr1[i].e;
                    cout << "ENTER COEFFICIENT: ";
                    cin >> arr1[i].c;
                }
                cout << "\n----------------------INPUT SECOND POLYNOMIAL-----------------------\n";
                cout << "ENTER NO. OF TERMS: ";
                int n2;
                cin >> n2;
                p arr2[100] = {};
                for(int i = 0; i < n2; i++) {
                    cout << "ENTER EXPONENT: ";
                    cin >> arr2[i].e;
                    cout << "ENTER COEFFICIENT: ";
                    cin >> arr2[i].c;
                }
                p arr3[300] = {};
                int n3;
                add(arr1,n1,arr2,n2,arr3,n3);
                cout << "\nFIRST POLYNOMIAL: ";
                displayS(arr1,n1);
                cout << "\nSECOND POLYNOMIAL: ";
                displayS(arr2,n2);
                cout << "\n-------------------------SUM-----------------------------\n";
                displayS(arr3,n3);
                cout << "\n---------------------------------------------------------------------\n";
                break;               
            }
            case 3: {
                cout << "\n----------------------------MULTIPLICATION----------------------------\n";
                cout << "\n----------------------INPUT FIRST POLYNOMIAL-----------------------\n";
                cout << "ENTER NO. OF TERMS: ";
                int n1;
                cin >> n1;
                p arr1[100] = {};
                for(int i = 0; i < n1; i++) {
                    cout << "ENTER EXPONENT: ";
                    cin >> arr1[i].e;
                    cout << "ENTER COEFFICIENT: ";
                    cin >> arr1[i].c;
                }
                cout << "\n----------------------INPUT SECOND POLYNOMIAL-----------------------\n";
                cout << "ENTER NO. OF TERMS: ";
                int n2;
                cin >> n2;
                p arr2[100] = {};
                for(int i = 0; i < n2; i++) {
                    cout << "ENTER EXPONENT: ";
                    cin >> arr2[i].e;
                    cout << "ENTER COEFFICIENT: ";
                    cin >> arr2[i].c;
                }
                int arr3[300]={};
                multiply(arr1,n1,arr2,n2,arr3);
                cout << "\nFIRST POLYNOMIAL: ";
                displayS(arr1,n1);
                cout << "\nSECOND POLYNOMIAL: ";
                displayS(arr2,n2);
                cout << "\n----------------------------PRODUCT---------------------------------\n";
                display(arr3,300);
                cout << "\n---------------------------------------------------------------------\n";
                break;
            }
            case 4:
                cout << "\n---------------------------EXITING---------------------------------\n";
                exit(0);
        }
    }
    while(true);
}

