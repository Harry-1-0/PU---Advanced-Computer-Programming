#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        vector<pair<string, int>> sites(10);
        int mx = 0;

        for (int i = 0; i < 10; i++) {
            cin >> sites[i].first >> sites[i].second;
            mx = max(mx, sites[i].second);
        }

        cout << "Case #" << tc << ":\n";

        for (int i = 0; i < 10; i++) {
            if (sites[i].second == mx) {
                cout << sites[i].first << "\n";
            }
        }
    }

    return 0;
}