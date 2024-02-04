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

int n;
pair<int, int> ar[100005];
void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> ar[i].first >> ar[i].second;
    sort(ar, ar + n, [](pair<int, int>& a, pair<int, int>& b) { return a.first < b.first; });
    for (int i = 1; i < n; ++i) {
        if (ar[i - 1].second > ar[i].second) {
            cout << "Happy Alex" << endl;
            return;
        }
    }

    cout << "Poor Alex" << endl;
}
