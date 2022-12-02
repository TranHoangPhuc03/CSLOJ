/* http://csloj.ddns.net/problem/425 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] %= k;
    }

    vector<vector<int>> dp(2, vector<int> (k, -1));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < k; ++j) {
            int ii = i%2;
            dp[ii][j] = max(dp[1-ii][j], dp[1-ii][(j-a[i]+k)%k] + 1);
        }
    }

    cout << dp[n%2][0];
    return 0;
}