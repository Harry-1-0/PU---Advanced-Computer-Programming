#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x, y;
};

bool blocked[7][7][4]; 
// 0=N, 1=E, 2=S, 3=W

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
char dir[] = {'N', 'E', 'S', 'W'};

bool valid(int x, int y) {
    return x >= 0 && x < 6 && y >= 0 && y < 6;
}

int main() {

    while (true) {

        int sx, sy;
        cin >> sx >> sy;

        if (sx == 0 && sy == 0)
            break;

        int ex, ey;
        cin >> ex >> ey;

        memset(blocked, false, sizeof(blocked));

        // walls
        for (int w = 0; w < 3; w++) {

            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            // horizontal wall
            if (y1 == y2) {

                for (int x = min(x1, x2); x < max(x1, x2); x++) {

                    if (y1 > 0) {
                        blocked[y1 - 1][x][2] = true;
                    }

                    if (y1 < 6) {
                        blocked[y1][x][0] = true;
                    }
                }
            }

            // vertical wall
            else {

                for (int y = min(y1, y2); y < max(y1, y2); y++) {

                    if (x1 > 0) {
                        blocked[y][x1 - 1][1] = true;
                    }

                    if (x1 < 6) {
                        blocked[y][x1][3] = true;
                    }
                }
            }
        }

        queue<Node> q;

        bool vis[6][6] = {};
        string path[6][6];

        q.push({sy - 1, sx - 1});
        vis[sy - 1][sx - 1] = true;

        while (!q.empty()) {

            Node cur = q.front();
            q.pop();

            if (cur.x == ey - 1 && cur.y == ex - 1)
                break;

            for (int d = 0; d < 4; d++) {

                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];

                if (!valid(nx, ny))
                    continue;

                if (blocked[cur.x][cur.y][d])
                    continue;

                if (!vis[nx][ny]) {

                    vis[nx][ny] = true;
                    path[nx][ny] = path[cur.x][cur.y] + dir[d];

                    q.push({nx, ny});
                }
            }
        }

        cout << path[ey - 1][ex - 1] << "\n";
    }

    return 0;
}