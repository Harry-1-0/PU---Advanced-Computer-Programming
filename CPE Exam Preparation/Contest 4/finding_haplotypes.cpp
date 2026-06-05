#include <bits/stdc++.h>
using namespace std;

int N, L;

vector<string> geno;
vector<string> haplos;

unordered_map<int, int> dp;

bool validPair(const string &h1, const string &h2, const string &g) {
    for (int i = 0; i < L; i++) {
        char a = h1[i], b = h2[i];

        if (g[i] == '0') {
            if (!((a == '0' && b == '0') || (a == '0' && b == '0')))
                return false;
        }
        else if (g[i] == '1') {
            if (!((a == '1' && b == '1')))
                return false;
        }
        else { // '2'
            if (!((a == '0' && b == '1') || (a == '1' && b == '0')))
                return false;
        }
    }
    return true;
}

int solve(int mask) {
    if (mask == (1 << N) - 1)
        return 0;

    if (dp.count(mask))
        return dp[mask];

    int best = 1e9;

    int i = 0;
    while (mask & (1 << i)) i++;

    for (int h1 = 0; h1 < (int)haplos.size(); h1++) {
        for (int h2 = h1; h2 < (int)haplos.size(); h2++) {

            bool ok = true;
            int newMask = mask;

            for (int j = i; j < N; j++) {
                if (!(mask & (1 << j))) {
                    if (validPair(haplos[h1], haplos[h2], geno[j])) {
                        newMask |= (1 << j);
                    }
                }
            }

            if (newMask != mask)
                best = min(best, 2 + solve(newMask));
        }
    }

    return dp[mask] = best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> N >> L) {
        geno.resize(N);

        for (int i = 0; i < N; i++)
            cin >> geno[i];

        haplos.clear();

        for (int m = 0; m < (1 << L); m++) {
            string h = "";
            for (int i = 0; i < L; i++)
                h += ((m >> i) & 1) ? '1' : '0';
            reverse(h.begin(), h.end());
            haplos.push_back(h);
        }

        dp.clear();

        cout << solve(0) << "\n";
    }

    return 0;
}