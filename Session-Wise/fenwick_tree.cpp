#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
    vector<int> bit;
    int n;

public:
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }

    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx)
            sum += bit[idx];
        return sum;
    }

    int rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    int n = arr.size();

    FenwickTree ft(n);

    for (int i = 0; i < n; i++)
        ft.update(i + 1, arr[i]);

    cout << ft.rangeQuery(2, 4) << endl;

    ft.update(2, 7);

    cout << ft.rangeQuery(2, 4) << endl;

    return 0;
}