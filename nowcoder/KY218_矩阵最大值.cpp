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

int m, n;
int max_index;
int row_sum;
int ar[105];
void solve() {
    while (cin >> m >> n) {
        for (int i = 0; i < m; ++i) {
            max_index = 0;
            row_sum = 0;
            for (int j = 0; j < n; ++j) {
                cin >> ar[j];
                row_sum += ar[j];
                if (ar[j] > ar[max_index]) { max_index = j; }
            }
            ar[max_index] = row_sum;
            for (int j = 0; j < n; ++j) {
                cout << ar[j] << ' ';
            }
            cout << endl;
        }
    }
}
