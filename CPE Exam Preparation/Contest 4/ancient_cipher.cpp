#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;

    while (cin >> a >> b) {

        vector<int> f1(26, 0), f2(26, 0);

        for (char c : a)
            f1[c - 'A']++;

        for (char c : b)
            f2[c - 'A']++;

        sort(f1.begin(), f1.end());
        sort(f2.begin(), f2.end());

        if (f1 == f2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}