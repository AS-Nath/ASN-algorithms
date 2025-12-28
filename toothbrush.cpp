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
    // The maxmimum element is deemed superior. Thus, all the array elements that aren't it must be
    // eradicated. 
    int m = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > m) {
            m = arr[i];
        }
    }
    int maxc = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == m) {
            maxc += 1;
        }
    }
    vector<int> sorted(maxc, m); 
    arr = sorted;
    cout << "Sorted : ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl; 
    return 0; 
}