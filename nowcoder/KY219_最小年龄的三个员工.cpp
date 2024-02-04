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
* 描述
- 输入职工号、姓名、年龄，找出 3 个年龄最小的职工，打印出来
- 关键字顺序：年龄 > 工号 > 姓名
*/
struct Employee {
    long long id;
    string name;
    int age;
};
int n;
Employee ar[35];
void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ar[i].id >> ar[i].name >> ar[i].age;
    }
    sort(ar, ar + n, [](const auto& a, const auto& b) {
        if (a.age != b.age) return a.age < b.age;
        if (a.id != b.age) return a.id < b.id;
        return a.name < b.name;
    });
    if (n > 3) n = 3;
    for (int i = 0; i < n; ++i) {
        cout << ar[i].id << ' ' << ar[i].name << ' ' << ar[i].age << endl;
    }
}
