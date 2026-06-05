#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "PERFECTION OUTPUT\n";

    int n;

    while (cin >> n && n != 0) {

        int sum = 0;

        for (int i = 1; i <= n / 2; i++) {
            if (n % i == 0)
                sum += i;
        }

        cout << setw(5) << n << " ";

        if (sum == n)
            cout << "PERFECT\n";
        else if (sum < n)
            cout << "DEFICIENT\n";
        else
            cout << "ABUNDANT\n";
    }

    cout << "END OF OUTPUT\n";

    return 0;
}