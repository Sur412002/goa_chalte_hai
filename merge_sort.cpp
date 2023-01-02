#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void mergeSort(int* arr, int s, int e) {
    if(s >= e) {
        return;
    }
    int m = s + ((e - s) / 2);
    mergeSort(arr, s, m);
    mergeSort(arr, m+1, e);
    int temp[e-s+1];
    int idx = 0;
    int i = s;
    int j = m + 1;
    while(i <=m && j <= e) {
        if(arr[i] <= arr[j]) {
            temp[idx++] = arr[i++];
        }
        else {
            temp[idx++] = arr[j++];
        }   
    }
    while(i <= m) {
        temp[idx++] = arr[i++];
    }
    while(j <= e) {
        temp[idx++] = arr[j++];
    }
    for(int i = s; i <= e; i++) {
        //cout << temp[i] << " ";
        arr[i] = temp[i-s];
    }
    //cout << endl;
    return;
}

int main() {
    cout << "\n-------------PROGRAM FOR MERGE SORT-----------------\n\n";
    cout << "ENTER NO. OF ELEMENTS: ";
    int n;
    cin >> n;
    int arr[100];
    cout << endl;
    cout << "ENTER ARRAY: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    mergeSort(arr,0,n-1);
    cout << "\n--------------------SORTED ARRAY :--------------------------\n";
    cout << "           ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "\n-----------------------------------------------------\n";
}

