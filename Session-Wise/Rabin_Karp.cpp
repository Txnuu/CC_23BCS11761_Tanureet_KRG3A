#include <bits/stdc++.h>
using namespace std;

void rabinKarp(string txt, string pattern) {
    int n = txt.size();
    int m = pattern.size();
    
    int d = 26;           
    int mod = 1e9 + 7;    
    
    long long pHash = 0, tHash = 0;
    long long h = 1;

    for(int i = 0; i < m - 1; i++)
        h = (h * d) % mod;

    for(int i = 0; i < m; i++) {
        pHash = (d * pHash + (pattern[i] - 'a' + 1)) % mod;
        tHash = (d * tHash + (txt[i] - 'a' + 1)) % mod;
    }

    for(int i = 0; i <= n - m; i++) {
        if(pHash == tHash) {
            if(txt.substr(i, m) == pattern)
                cout << "Pattern found at index " << i << endl;
        }
        if(i < n - m) {
            tHash = (d * (tHash - (txt[i] - 'a' + 1) * h) 
                     + (txt[i + m] - 'a' + 1)) % mod;

            if(tHash < 0)
                tHash += mod;
        }
    }
}

int main() {
    string txt = "abcabcbad";
    string pattern = "cba";
    rabinKarp(txt, pattern);
    return 0;
}