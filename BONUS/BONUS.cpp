/* http://csloj.ddns.net/problem/1509 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k, r, p;
vector<vector<ll>> a;

ll calc(int state, vector<pair<int, int>> &squares)
{
    int xTop = 0, yTop = 0;
    int xBot = n+1, yBot = n+1;
    int i = 0;
    int cnt = 0;
    while (state > 0) {
        if (state & 1) {
            int xTopCurr = squares[i].first;
            int yTopCurr = squares[i].second;

            xTop = max(xTop, xTopCurr);
            yTop = max(yTop, yTopCurr);
            xBot = min(xBot, xTopCurr+r-1);
            yBot = min(yBot, yTopCurr+r-1);

            cnt++;
        }

        i++;
        state >>= 1;
    }

    ll sum = 0LL;
    if (xBot >= xTop && yBot >= yTop)
        sum = a[xBot][yBot] - a[xBot][yTop-1] - a[xTop-1][yBot] + a[xTop-1][yTop-1];
        
    return (cnt&1 ? sum : -sum);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k >> r >> p;
    a.resize(n+1);
    a[0].resize(n+1);
    for (int i = 1; i <= n; ++i) {
        a[i].resize(n+1);
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + a[i][j];
        }
    }

    ll res = 0LL;
    while (k--) {
        vector<pair<int, int>> squares(p);
        for (int i = 0; i < p; ++i)
            cin >> squares[i].first >> squares[i].second;

        ll sum = 0LL;
        for (int state = 1; state < (1 << p); ++state)
            sum += calc(state, squares);

        res = max(res, sum);
    }

    cout << res;
    return 0;
}