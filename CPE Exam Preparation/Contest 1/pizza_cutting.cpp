#include <bits/stdc++.h>
#include <format>
using namespace std;

int main() {
    int n;
    while (cin >> n && n >= 0) {
        long long pieces = 1LL * n * (n + 1) / 2 + 1;
        cout << format("{}\n", pieces);
    }
    return 0;
}