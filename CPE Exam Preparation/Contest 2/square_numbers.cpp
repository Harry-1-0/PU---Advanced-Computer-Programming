#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;

    while (cin >> a >> b && !(a == 0 && b == 0)) {

        int start = ceil(sqrt(a));
        int end = floor(sqrt(b));

        cout << end - start + 1 << "\n";
    }

    return 0;
}