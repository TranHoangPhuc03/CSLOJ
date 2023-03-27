/* http://csloj.ddns.net/problem/390 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<char> res;

bool check()
{
    int cnt = 0;
    for (auto i : res) {
        if (i == '(') cnt++;
        else  cnt--;
        if (cnt < 0) return false;
    }

    return (cnt == 0);
}

void solve(int i)
{
    if (i == 2*n) {
        if (check()) {
            for (auto i : res)
                cout << i;
            cout << '\n';
        }
        return;
    }

    res[i] = '(';
    solve(i+1);
    res[i] = ')';
    solve(i+1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    res.resize(2*n);

    solve(0);
    return 0;
}