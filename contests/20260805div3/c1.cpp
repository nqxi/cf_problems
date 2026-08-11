// a and b, of same length n, both binary eg 1010
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long t; cin >> t;
    while (t--) {
        long n; cin >> n;
        string a, b; cin >> a >> b;
        // Preliminary cases
        if (a == b) { cout << "YES" << '\n'; continue; }
        else if (n < 3) { cout << "NO" << '\n'; continue; }
        
        long ca[2]={}, cb[2]={};
        // For each lone 1, they can swap within their parity.
        for (int i = 0; i < n; i++) {
            if(a[i]=='1') ca[i%2]++;
            if(b[i]=='1') cb[i%2]++;
        }

        if (ca[0]==cb[0] && ca[1]==cb[1]) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }


    return 0;
}