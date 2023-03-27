/* http://csloj.ddns.net/problem/380 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, s, res;
vector<int> t, d;

void backtracking(int i, int sumTime, int sumPoint)
{
    if (sumTime > s)
        return;

    if (i == n) {
        res = max(res, sumPoint);
        return;
    }

    backtracking(i+1, sumTime + t[i], sumPoint + d[i]);
    backtracking(i+1, sumTime, sumPoint);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> s;
    t.resize(n);
    d.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> t[i];
    for (int i = 0; i < n; ++i)
        cin >> d[i];

    backtracking(0, 0, 0);
    cout << res;
    return 0;
}