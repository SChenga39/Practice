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

// x, y 为坐标，z 为到达当前坐标所需要的步数
struct Item {
    int x, y, z;
    Item(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}
};

int n, m, x, y;
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {1, -1, -2, 2, -2, 2, 1, -1};
int ar[405][405];
int res;
int vis[405][405];
queue<Item> q;

void solve() {
    scanf("%lld%lld%lld%lld", &n, &m, &x, &y);

    q.push({x - 1, y - 1, 0});
    vis[x - 1][y - 1] = 1;
    while (!q.empty()) {
        auto [tx, ty, s] = q.front();
        q.pop();
        for (int i = 0; i < 8; ++i) {
            int nx = tx + dx[i], ny = ty + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && !vis[nx][ny]) {
                q.push({nx, ny, s + 1});
                vis[nx][ny] = 1;
                ar[nx][ny] = s + 1;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (vis[i][j])
                printf("%-5lld", ar[i][j]);
            else
                printf("%-5d", -1);
        }
        puts("");
    }
}

