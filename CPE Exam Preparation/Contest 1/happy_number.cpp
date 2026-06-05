#include <bits/stdc++.h>
#include <format>
using namespace std;

int nextNum(int n) {
    int s = 0;
    while (n) {
        int d = n % 10;
        s += d * d;
        n /= 10;
    }
    return s;
}

bool isHappy(int n) {
    unordered_set<int> seen;
    while (n != 1 && !seen.count(n)) {
        seen.insert(n);
        n = nextNum(n);
    }
    return n == 1;
}

int main() {
    int t, n;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n;
        cout << format("Case #{}: {} is a {}Happy number.\n",
                       i, n, isHappy(n) ? "" : "Un");
    }
    return 0;
}