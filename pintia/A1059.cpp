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

#define N 100005
int prime[N], ptr = 0;
int n, num = 0;
struct Factor {
    int x, cnt;
} fac[10];
bool isPrime(int num) {
    if (num == 2)
        return true;
    else if (num < 2 || (num & 1) == 0)
        return false;
    for (int i = 3, end = (int) sqrt(num) + 1; i < end; i += 2)
        if (num % i == 0) return false;
    return true;
}
// 打表
void findPrime() {
    for (int i = 1; i < N; ++i)
        if (isPrime(i)) prime[ptr++] = i;
}
void solve() {
    findPrime();
    cin >> n;
    if (n == 1)
        puts("1=1");
    else {
        cout << n << '=';
        for (int i = 0, sqr = (int) sqrt(1.0 * n); i < ptr && prime[i] <= sqr; ++i) {
            if (!(n % prime[i])) {
                fac[num].x = prime[i];
                fac[num].cnt = 0;
                while (!(n % prime[i])) {
                    ++(fac[num].cnt);
                    n /= prime[i];
                }
                // 不同质因子个数加一
                ++num;
            }
            if (n == 1) break;
        }
        // 无法被根号 n 以内的数除尽
        if (n != 1) {
            // 将 n 单独作为一个质因子加入答案中
            fac[num].x = n;
            fac[num++].cnt = 1;
        }
        for (int i = 0; i < num; ++i) {
            if (i > 0) putchar('*');
            cout << fac[i].x;
            if (fac[i].cnt > 1) cout << '^' << fac[i].cnt;
        }
    }
}
