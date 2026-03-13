#include <bits/stdc++.h>
using namespace std;

int findUnique(vector<int>& arr) {
    int result = 0;
    int n = arr.size();

    for(int i = 0; i < 32; i++) {
        int count = 0;

        for(int j = 0; j < n; j++) {
            if((arr[j] >> i) & 1) {
                count++;
            }
        }

        if(count % 3 != 0) {
            result = result | (1 << i);
        }
    }

    return result;
}

int main() {
    vector<int> arr = {2, 2, 3, 2};

    cout << "Unique element: " << findUnique(arr);

    return 0;
}