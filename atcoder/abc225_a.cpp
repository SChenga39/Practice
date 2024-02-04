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

string s;
set<string> st;
void solve() {
    cin >> s;
    sort(s.begin(), s.end());
    do
        st.insert(s);
    while (next_permutation(s.begin(), s.end()));
    cout << st.size() << endl;
}
