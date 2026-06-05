#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000007;

int n;
vector<string> board;
long long dp[105][105];

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

long long solve(int x, int y) {

    if (x == 0)
        return 1;

    if (dp[x][y] != -1)
        return dp[x][y];

    long long ways = 0;

    int dx[] = {-1, -1};
    int dy[] = {-1, 1};

    for (int d = 0; d < 2; d++) {

        int nx = x + dx[d];
        int ny = y + dy[d];

        // normal move
        if (valid(nx, ny) && board[nx][ny] == '.') {
            ways += solve(nx, ny);
        }

        // jump move
        else if (valid(nx, ny) && board[nx][ny] == 'B') {

            int jx = x + 2 * dx[d];
            int jy = y + 2 * dy[d];

            if (valid(jx, jy) && board[jx][jy] == '.') {
                ways += solve(jx, jy);
            }
        }
    }

    return dp[x][y] = ways % MOD;
}

int main() {

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {

        cin >> n;

        board.resize(n);

        int sx, sy;

        for (int i = 0; i < n; i++) {
            cin >> board[i];

            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'W') {
                    sx = i;
                    sy = j;
                }
            }
        }

        memset(dp, -1, sizeof(dp));

        cout << "Case " << tc << ": "
             << solve(sx, sy) % MOD << "\n";
    }

    return 0;
}