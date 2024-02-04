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

const int mod = 1e9 + 7;  // 模数
const int p = 1e7 + 19;   // 进制数
int ans[10005];
string str;
int id;
int n;
int hashstr(string str) {
    int res = 0;
    for (char i : str) {
        res = (res * p + i - 'a') % mod;
    }
    return res;
}

void solve() {
    cin >> n;
    int ptr = 0;
    while (n--) {
        cin >> str;
        id = hashstr(str);
        ans[ptr++] = id;
    }
    sort(ans, ans + ptr);
    int count = 0;
    for (int i = 0; i < ptr; ++i) {
        if (!i || ans[i] != ans[i - 1]) ++count;
    }
    cout << count << endl;
}
