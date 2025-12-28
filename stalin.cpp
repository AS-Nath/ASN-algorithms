#include <bits/stdc++.h>
using namespace std; 

int main(void) {
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        arr.push_back(t); 
    }
    // Assume the first element is sorted increasing. For the rest, if out of order, send to the gulag. 
    // If an element already exists when we try to put it in the gulag, it has clearly attempted escape.
    // So as punishment that element will be executed. 
    unordered_map<int, int> gulag;
    unordered_map<int, int> execution; 
    vector<int> sorted(1, arr[0]);
    int val_index = 0; 
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[val_index]) {
            // Gulag / Execution
            if (gulag[arr[i]] > 0) { // Found in gulag == execution
                execution[arr[i]] = 1;
                gulag.erase(gulag.find(arr[i])); 
            }
            else { // Not found in gulag == gulag 
                gulag[arr[i]] = 1; 
            }
        }
        else {
            sorted.push_back(arr[i]);
            val_index = i; 
        }
    }
    cout << "Sorted : ";
    for (int i = 0; i < sorted.size(); i++) {
        cout << sorted[i] << " ";
    }
    cout << endl; 
    if (gulag.begin() != gulag.end()) { // Only show if there are elements in the gulag
        cout << "Gulag : ";
        for (auto it = gulag.begin(); it != gulag.end(); it++) {
            cout << (it -> first) << " ";
        }
        cout << endl; 
    }
    if (execution.begin() != execution.end()) { // Only show if executions are warranted 
        cout << "Execution : ";
        for (auto it = execution.begin(); it != execution.end(); it++) {
            cout << (it -> first) << " ";
        }
        cout << endl; 
    }
}