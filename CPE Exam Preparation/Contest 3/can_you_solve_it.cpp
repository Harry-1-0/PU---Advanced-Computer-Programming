#include <bits/stdc++.h>
using namespace std;

long long pos(long long x, long long y) {
    long long d = x + y;
    return d * (d + 1) / 2 + x;
}

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        long long ans = pos(x2, y2) - pos(x1, y1);

        cout << "Case " << tc << ": " << ans << "\n";
    }

    return 0;
}