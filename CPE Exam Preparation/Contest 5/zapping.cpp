#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    while(cin >> a >> b && (a != -1 || b != -1)) {
        int up = (b - a + 100) % 100;
        int down = (a - b + 100) % 100;
        cout << min(up, down) << "\n";
    }
}