#include <bits/stdc++.h>
#include <format>
using namespace std;

int cycle(long long n) {
    int len = 1;
    while (n != 1) {
        if (n % 2)
            n = 3 * n + 1;
        else
            n /= 2;
        len++;
    }
    return len;
}

int main() {
    int i, j;
    while (cin >> i >> j) {
        int l = min(i, j), r = max(i, j);
        int ans = 0;

        for (int x = l; x <= r; x++) {
            ans = max(ans, cycle(x));
        }

        cout << format("{} {} {}\n", i, j, ans);
    }
    return 0;
}