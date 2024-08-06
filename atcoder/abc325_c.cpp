#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3F3F3F3F;
const long long INFLL = 0x3F3F3F3F3F3F3F3F;
#define endl '\n'
#define int long long

void solve();
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}

/*
 * BFS
 */
int h, w;
bool vis[1005][1005];
char ar[1005][1005];
queue<pair<int, int>> q;
pair<int, int> t;
int nx, ny;
int res;
int dx[] = {-1, 0, 0, 1, -1, 1, -1, 1};
int dy[] = {0, 1, -1, 0, -1, 1, 1, -1};
void solve() {
    cin >> h >> w;
    for (int i = 0; i < h; ++i) {
        cin >> ar[i];
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (ar[i][j] == '.' || vis[i][j]) continue;

            q.push({i, j});
            ++res;

            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                for (int k = 0; k < 8; ++k) {
                    nx = x + dx[k];
                    ny = y + dy[k];

                    if (0 <= nx && nx < h && 0 <= ny && ny < w && ar[nx][ny] == '#'
                        && !vis[nx][ny]) {
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    cout << res << endl;
}
