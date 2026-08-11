#include <bits/stdc++.h>
using namespace std;
string f(string s);
long drop(const string& s, long j);

// you cannot delete s1 or sn from s'
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long t; cin >> t;

    while (t--) { // for each test case
        long n; cin >> n; // len s
        string s; cin >> s;
        long max_val = 0;

        // we need a better approach thats not O(n^2)
        for (long j = 1; j < n - 1; j++ ) { // iterate in the string    
            long nl = drop(s, j);
            max_val = max(max_val, nl);
        }
        cout << f(s).size() - max_val << '\n';
    }

    return 0;
}


string f(string s) { //for each continguous block, compress that . 'aabbaa'->'aba'.
    string r;
    for (char c : s) {
        if (r.empty() || c != r.back()) r += c;
    }
    return r;
}

long drop(const string& s, long j) {
    if (s[j-1] == s[j+1]) { // if we have a pair
        if (s[j-1] != s[j]) { // and j is solo
            return 2;
        }
        else return 0;

    }
    else { // no pair
        // check if j is solo
        if (s[j-1] != s[j] && s[j+1] != s[j]) return 1;
        else return 0;

    }
}