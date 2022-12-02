/* http://csloj.ddns.net/problem/423 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n+1, vector<int> (n+1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    
    vector<vector<int>> s(n+1, vector<int> (n+1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            s[i][j] = s[i][j-1] + s[i-1][j] - s[i-1][j-1] + a[i][j];

    int res = 0;
    for (int i = k; i <= n; ++i)
        for (int j = k; j <= n; ++j)
            res = max(res, s[i][j] - s[i-k][j] - s[i][j-k] + s[i-k][j-k]);

    cout << res;
    return 0;
}