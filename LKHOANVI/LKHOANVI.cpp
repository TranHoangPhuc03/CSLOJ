/* http://csloj.ddns.net/problem/389 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<int> a;
vector<bool> mark;

void solve(int ind)
{
    if (ind == n) {
        for (int i = 0; i < n; ++i)
            cout << a[i] << ' ';
        cout << '\n';
        return;
    }

    for (int digit = 1; digit <= n; ++digit) {
        if (!mark[digit]) {
            mark[digit] = true;
            a[ind] = digit;
            solve(ind+1);
            mark[digit] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    a.resize(n);
    mark.resize(n+1);

    solve(0);
    return 0;
}