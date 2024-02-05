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
* 思路：归并排序
手动模拟归并排序，在排序的过程中记录
*/
int n, a[500005], tmp[500005];
long long sum = 0;
void merge(int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1;

    merge(l, mid);
    merge(mid + 1, r);

    int left = l, right = mid + 1, count = l;
    while (left <= mid && right <= r) {
        if (a[left] <= a[right]) {
            tmp[count++] = a[left++];
        } else {
            tmp[count++] = a[right++];
            sum += mid - left + 1;
        }
    }
    while (left <= mid)
        tmp[count++] = a[left++];
    while (right <= r)
        tmp[count++] = a[right++];
    for (int i = l; i <= r; i++)
        a[i] = tmp[i];
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    merge(0, n - 1);
    cout << sum << endl;
}
