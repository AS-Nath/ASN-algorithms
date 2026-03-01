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
    // The first element is deemed the Khan. The successive elements must be the successor of the previous, 
    // regardless of what the original element there was. 
    for (int i = 1; i < n; i++) {
        arr[i] = arr[i - 1] + 1;
    }
    cout << "Sorted : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0; 
}