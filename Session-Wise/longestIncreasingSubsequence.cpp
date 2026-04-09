#include <bits/stdc++.h>
using namespace std;

int findPosition(vector<int>& temp, int x) {
    int left = 0, right = temp.size() - 1;
    int ans = temp.size();  

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (temp[mid] >= x) {
            ans = mid;      
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}

int longestIncreasingSubsequence(vector<int>& arr) {
    vector<int> temp;

    for (int x : arr) {
        int pos = findPosition(temp, x);

        if (pos == temp.size()) {
            temp.push_back(x);   
        } else {
            temp[pos] = x;       
        }
    }

    return temp.size();
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr) << endl;

    return 0;
}