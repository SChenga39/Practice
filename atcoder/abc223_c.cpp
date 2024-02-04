#include <bits/stdc++.h>
#include <iomanip>
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
 * 在读入数据时顺便计算出总耗时，除以二之后再次遍历数组找到燃烧一半所到达的长度即为答案
 */
int n;
double t, len, curr;
double a[100005], b[100005];
void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        t += a[i] / b[i];
    }
    t /= 2;
    for (int i = 0; i < n; ++i) {
        curr = a[i] / b[i];
        if (t > curr)
            len += a[i], t -= curr;
        else {
            len += t * b[i];
            break;
        }
    }
    cout << setiosflags(ios::fixed) << setprecision(15) << len << endl;
}
