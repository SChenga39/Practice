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
https://ac.nowcoder.com/acm/problem/14572

* 思路
使用 bfs 进行搜索，一旦搜索到终点即为搜索成功，直接将 ans 设为 1 并返回

* 注意
由于该题有多组样例，每组样例前应该重置 vis 数组、 ans 变量和 q 队列
*/
#define N 505
char gameMap[N][N];
int n, m;
// 分别表示起点和终点
pair<int, int> start, ending;
// vis 数组表示当前位置是否访问过, ans 记录是否可以到达终点
int vis[N][N], ans;
queue<pair<int, int>> q;
// dx 和 dy 方便向四个方向移动
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void bfs() {
    q.push(start);
    vis[start.first][start.second] = 1;
    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();
        // 到达终点
        if (now == ending) {
            ans = 1;
            break;
        }
        // 遍历四个方向
        for (int i = 0; i < 4; ++i) {
            int x = now.first + dx[i];
            int y = now.second + dy[i];
            if (0 <= x && x < n && 0 <= y && y < m && !vis[x][y] && gameMap[x][y] != '#') {
                vis[x][y] = 1;
                q.push({x, y});
            }
        }
    }
}
void solve() {
    while (cin >> n >> m) {
        ans = 0;
        memset(vis, 0, sizeof(vis));
        q = queue<pair<int, int>>();
        for (int i = 0; i < n; ++i) {
            cin >> gameMap[i];
            for (int j = 0; j < m; ++j) {
                if (gameMap[i][j] == 'S')
                    start = {i, j};
                else if (gameMap[i][j] == 'E')
                    ending = {i, j};
            }
        }
        bfs();
        cout << (ans ? "Yes" : "No") << endl;
    }
}
