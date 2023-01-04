#include<bits/stdc++.h>
using namespace std;

struct Friend {
    string name;
    long long phone;
};

int compare(string a, string b) {
    if(a[0] > b[0]) {
        return 1;
    }
    if(a[0] < b[0]) {
        return -1;
    }
    int l1 = a.length();
    int l2 = b.length();
    int l = min(l1,l2);
    for(int i = 0; i < l; i++) {
        //cout << a[i] << "  " << b[i] << endl;
        if(a[i] > b[i]) {
            return 1;
        }
        if(a[i] < b[i]) {
            return -1;
        }
    }
    if(l1 == l2) {
        return 0;
    }
    return 0;
}

int binarySearchI(Friend* arr, int t, string key) {
    int low = 0;
    int high = t - 1;
    while(low <= high) {
        int mid = (low + high)/2;
        if(arr[mid].name == key) {
            return mid;
        }
        else  if(compare(key,arr[mid].name)==1) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

int binarySearchR(Friend* arr, int low, int high, string key) {
    if(low > high) {
        return -1;
    }
    int mid = (low + high)/2;
    int ans;
    if(arr[mid].name == key) {
        ans =  mid;
    }
    else if(compare(key,arr[mid].name)==1) {
        ans =  binarySearchR(arr,mid+1,high,key);
    }
    else {
        ans = binarySearchR(arr,low,mid-1,key);
    }
    return ans;
}

int fibonacciSearch(Friend* arr, int t, string key) {
    int a = 1, b = 0, f = 1;
    while(f <= t) {
        b = a;
        a = f;
        f = a + b;
    }
    int offset = -1;
    while(f > 1) {
        int i = min(offset + b, t-1);
        if(compare(key,arr[i].name)==1) {
            f = a;
            a = b;
            b = f - a;
            offset = i;
        }
        else if(compare(key,arr[i].name) == -1) {
            f = b;
            a = a - b;
            b = f - a;
        }
        else {
            return i;
        }
    } 
    return -1;
}

void display(Friend* arr, int t) {
    cout << "Displaying List: \n";
    cout << "------------------------------------------------------\n";
    cout << "       NAME" << "                          " << "MOBILE NO." << endl;
    for(int i = 0; i < t; i++) {
        cout << i+1 << ". ";
        cout << setw(10) << arr[i].name;
        cout << "                       ";
        cout << arr[i].phone << endl;
    }
    cout << "------------------------------------------------------\n";
}

void addFriend(Friend* arr, int &t, string key, long long m) {
    int ind = t;
    for(int i = 0; i < t; i++) {
        if(compare(arr[i].name, key)==1) {
            ind = i;
            break;
        }
    }
    for(int i = t-1; i >= ind; i--) {
        arr[i+1] = arr[i];
    }
    arr[ind].name = key;
    arr[ind].phone = m;
    t ++;
    cout << "Entry added successfully\n";
}

int main() {
    Friend arr[100];
    cout << "Enter total friends to enter: \n";
    int t;
    cin >> t;
    cout << "Enter the friends in sorted order: \n";
    for(int i = 0; i < t; i++) {
        cout << "Enter name: ";
        cin >> arr[i].name;
        cout << "Enter mobile no.: ";
        cin >> arr[i].phone;
    }
    cout << "Menu:\nSearch your friend from list using:\n1. Binary Search iterative\n2. Binary search recursive\n3. Fibonacci Search\n4. Display List\n5. Exit\n\n";
    int i; string key;
    do {
        cout << "Enter choice: ";
        int n;
        cin >> n;
        cin.ignore();
        switch(n) {
            case 1:
                cout << "Enter name of friend to search: ";
                getline(cin, key);
                i = binarySearchI(arr, t, key);
                if(i != -1) {
                    cout << "Found using Iterative Binary Search at serial no. " << i+1 << ": " << endl;
                    cout << i+1 << ". ";
                    cout << setw(13) << "Name : " ;
                    cout << arr[i].name << endl;
                    cout << setw(16) << "Mobile No : ";
                    cout << arr[i].phone << endl;
                }
                else {
                    cout << "This friend is not in the list\nPlease enter his mobile no : ";
                    long long m;
                    cin >> m;
                    addFriend(arr,t,key,m);
                }
                cout << endl;
                break;
            case 2:
                cout << "Enter name of friend to search: ";
                getline(cin, key);
                i = binarySearchR(arr, 0, t-1, key);
                if(i != -1) {
                    cout << "Found using Recursive Binary Search at serial no. " << i+1 << ": " << endl;
                    cout << i+1 << ". ";
                    cout << setw(13) << "Name : " ;
                    cout << arr[i].name << endl;
                    cout << setw(16) << "Mobile No : ";
                    cout << arr[i].phone << endl;
                }
                else {
                    cout << "This friend is not in the list\nPlease enter his mobile no : ";
                    long long m;
                    cin >> m;
                    addFriend(arr,t,key,m);
                }
                cout << endl;
                break;
            case 3:
                cout << "Enter name of friend to search: ";
                getline(cin, key);
                i = fibonacciSearch(arr, t, key);
                if(i != -1) {
                    cout << "Found using Fibonacci Search at serial no. " << i+1 << ": " << endl;
                    cout << i+1 << ". ";
                    cout << setw(13) << "Name : " ;
                    cout << arr[i].name << endl;
                    cout << setw(16) << "Mobile No : ";
                    cout << arr[i].phone << endl;
                }
                else {
                    cout << "This friend is not in the list\nPlease enter his mobile no : ";
                    long long m;
                    cin >> m;
                    addFriend(arr,t,key,m);
                }
                cout << endl;
                break;
            case 4:
                display(arr,t);
                cout << endl;
                break;
            case 5:
                cout << "--------------EXITING-----------------\n";
                exit(0);
        }
    }while(true);
}		


