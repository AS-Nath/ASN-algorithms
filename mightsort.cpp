#include <bits/stdc++.h>
using namespace std; 

bool issorted(vector<int> &arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true; 
}

void permute(vector<int> arr, int l, int r) {
    if (l == r) {
        if (issorted(arr)) {
            cout << "Sorted : ";
            for (int i = 0; i < arr.size(); i++) {
                cout << arr[i] << " "; 
            }
            cout << endl; 
        }
        return; 
    }
    for (int i = l; i <= r; i++) {
        int t = arr[i];
        arr[i] = arr[l];
        arr[l] = t;
        permute(arr, l+1, r); 
        t = arr[i];
        arr[i] = arr[l];
        arr[l] = t;
    }
}

int main(void) {
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        arr.push_back(t); 
    }
    // We'll generate permutations until the array is sorted. 
    permute(arr, 0, arr.size()-1); 
    return 0; 
}