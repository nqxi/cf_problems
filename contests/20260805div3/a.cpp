#include <bits/stdc++.h>
using namespace std;
long play_game(long a, long b, long c);

int main() {
    ios_abase::sync_with_stdio(false);
    cin.tie(NULL);

    long t, a, b, c;
    cin >> t;
    
    for (long i = 0; i < t; i++) {
        cin >> a >> b >> c;
        cout << play_game(a,b,c) << '\n';
    }

    return 0;
}

long play_game(long a, long b, long c) { // max gives one to min each time
    if (a == b || b == c || a == c ) {
        return 0;
    }
    // find player with max
    if (a > b && a > c) { // A is max
        a--;
        if (b < c) b++; // B is min
        else c++; // C is min
    }
    else if (b > a && b > c) { // B is max 
        b--;
        if (a < c) a++; // A is min
        else c++; // C is min
    }

    else if (c > a && c > b) { // C is max
        c--;
        if (a < b) a++; // A is min
        else b++; // B is min
    }

    return 1 + play_game(a,b,c);
}