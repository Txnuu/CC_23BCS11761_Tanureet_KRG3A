#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<long long,long long>> tasks(n);

    for(int i = 0; i < n; i++)
        cin >> tasks[i].first >> tasks[i].second;

    sort(tasks.begin(), tasks.end());

    long long time = 0;
    long long ans = 0;

    for(auto t : tasks){
        time += t.first;
        ans += t.second - time;
    }

    cout << ans;
}