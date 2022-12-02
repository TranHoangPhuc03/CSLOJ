/* http://csloj.ddns.net/problem/424 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    /*
        dp[i] la diem so lon nhat khi ket thuc tai diem i
        dp[i] = max(dp[j]) + a[i]; i-k <= j < i
    */

    int res = INT_MIN;
    vector<int> dp(n+1, INT_MIN);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int mx = INT_MIN;
        for (int j = max(0, i-k); j < i; ++j) {
            mx = max(mx, dp[j]);
        }
        dp[i] = mx + a[i];
        res = max(res, dp[i]);
    }

    cout << res;
    return 0;
}