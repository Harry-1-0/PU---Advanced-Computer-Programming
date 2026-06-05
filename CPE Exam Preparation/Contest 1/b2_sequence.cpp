#include <bits/stdc++.h>
#include <format>
using namespace std;

int main() {
    int n;
    int tc = 1;

    while (cin >> n) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        bool ok = true;
        set<int> sums;

        // Check if sequence is positive and strictly increasing
        for (int i = 0; i < n; i++) {
            if (arr[i] <= 0 || (i > 0 && arr[i] <= arr[i - 1])) {
                ok = false;
                break;
            }
        }

        // Check unique pair sums (including i == j)
        for (int i = 0; i < n && ok; i++) {
            for (int j = i; j < n; j++) {
                int sum = arr[i] + arr[j];

                if (sums.contains(sum)) {
                    ok = false;
                    break;
                }

                sums.insert(sum);
            }
        }

        cout << format(
            "Case #{}: It is {}a B2-Sequence.\n\n",
            tc++,
            ok ? "" : "not "
        );
    }

    return 0;
}