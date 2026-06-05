#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    while (cin >> n && n != 0) {
        int x = 1, y = 1;
        int num = 1;
        int step = 1;

        while (num < n) {

            // move up
            for (int i = 0; i < step && num < n; i++) {
                y++;
                num++;
            }

            // move right
            for (int i = 0; i < step && num < n; i++) {
                x++;
                num++;
            }

            step++;
        }

        cout << x << " " << y << "\n";
    }

    return 0;
}