/* http://csloj.ddns.net/problem/636 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int res = INT_MIN;
    for (int i = 1; i < n; ++i)
        res = max(res, a[i]-a[i-1]);

    for (int i = 1; i < n-1; ++i) {
        res = max(res, a[i+1]-a[i-1]);
    }

    cout << res;
    return 0;
}