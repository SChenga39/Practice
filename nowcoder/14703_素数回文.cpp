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
https://ac.nowcoder.com/acm/problem/14703
*/
int n, tmp;
int ge;
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2 || num == 3) return true;
    if (num % 6 != 1 && num % 6 != 5) return false;
    for (int i = 5; i * i <= num; i += 6)
        if (num % i == 0 || num % (i + 2) == 0) return false;
    return true;
}
void solve() {
    cin >> n;
    tmp = n / 10;
    while (tmp) {
        ge = tmp % 10;
        tmp /= 10;
        n = n * 10 + ge;
    }
    cout << (isPrime(n) ? "prime" : "noprime") << endl;
}
