/* http://csloj.ddns.net/problem/402 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, S;
    cin >> n >> S;
    vector<pair<int, int>> a(n+1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i].first;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].second;

    vector<vector<int>> dp(n+1, vector<int> (S+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= S; ++j) {
            if (j < a[i].first) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i].first] + a[i].second);
        }
    }

    cout << dp[n][S];
    return 0;
}