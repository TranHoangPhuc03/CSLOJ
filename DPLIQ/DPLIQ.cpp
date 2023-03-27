/* http://csloj.ddns.net/problem/420 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &val : a)
        cin >> val;

    vector<int> dp(n, 1);
    int res = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i])
                dp[i] = max(dp[i], dp[j]+1);
        }
        res = max(res, dp[i]);
    }
    cout << res;  
    return 0;
}