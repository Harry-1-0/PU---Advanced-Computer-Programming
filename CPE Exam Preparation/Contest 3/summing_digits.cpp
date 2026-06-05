#include <bits/stdc++.h>
using namespace std;

int main() {
    string n;

    while (cin >> n && n != "0") {

        while (n.length() > 1) {
            int sum = 0;

            for (char c : n)
                sum += c - '0';

            n = to_string(sum);
        }

        cout << n << "\n";
    }

    return 0;
}