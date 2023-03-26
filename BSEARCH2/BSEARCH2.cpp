/* http://csloj.ddns.net/problem/408 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];

    for (auto &val : b) {
        int l = 0, r = n-1;
        int res = -1;
        while (l <= r) {
            int mid = (l+r)/2;
            if (a[mid] == val)
                res = mid, r = mid - 1;
            else if (a[mid] < val)
                l = mid+1;
            else r = mid - 1;
        }

        cout << res+1 << ' ';
    }
    return 0;
}