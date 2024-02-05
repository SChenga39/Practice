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

int num[4], n, min_, max_;
void toArray() {
    // 不用考虑数字顺序
    for (int& i : num) {
        i = n % 10;
        n /= 10;
    }
}
int toNumber() {
    int ans = 0;
    for (int i : num)
        ans = ans * 10 + i;
    return ans;
}
void solve() {
    scanf("%d", &n);
    while (1) {
        toArray();
        sort(num, num + 4);
        min_ = toNumber();
        sort(num, num + 4, [](int a, int b) { return a > b; });
        max_ = toNumber();
        n = max_ - min_;
        printf("%04d - %04d = %04d\n", max_, min_, n);
        if (!n || n == 6174) break;
    }
}
