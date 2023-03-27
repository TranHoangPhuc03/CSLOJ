/* http://csloj.ddns.net/problem/502 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool check(int n, vector<ll> &a, ll x) {
    int i = 0, j = 0;
    while (i < n) {
        while (j < n && a[j] >= x) j++;
        if (j - i >= x)
            return true;
        j += 1;
        i = j;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<ll> b;
    for (int i = 0; i < n; ++i) b.push_back(a[i]);

    sort(b.begin(), b.end());

    ll l = 0, r = n - 1;
    ll res = 0LL;

    while (l <= r) {
        ll mid = (l + r) >> 1;

        if (check(n, a, b[mid]))
            res = b[mid] * b[mid], l = mid + 1;
        else
            r = mid - 1;
    }

    cout << res;
    return 0;
}