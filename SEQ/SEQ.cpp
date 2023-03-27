/* http://csloj.ddns.net/problem/257 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    map<ll, int> m;
    for (int i = 0; i < n; ++i)
        m[a[i]] = i;

    bool ok = false;
    for (int i = n-1; i >= 0; --i) {
        if (m.find(k+a[i]) != m.end() && m[k+a[i]] != i) {
            cout << m[k+a[i]]+1 << ' ' << i+1;
            ok = true;
            break;
        }
    }

    if (!ok)
        cout << "0 0\n";
    return 0;
}