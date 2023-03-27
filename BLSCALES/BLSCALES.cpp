/* http://csloj.ddns.net/problem/383 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
vector<ll> a, b;
map<ll, bool> sum;

void genSum(int i, ll currSum)
{
    if (i == n) {
        sum[currSum] = true;
        return;
    }

    genSum(i+1, currSum + a[i]);
    genSum(i+1, currSum);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    a.resize(n);
    b.resize(m);

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < m; ++i)
        cin >> b[i];

    genSum(0, 0LL);
    for (int i = 0; i < m; ++i)
        if (sum.find(b[i]) != sum.end())
            cout << 1;
        else cout << 0;
    return 0;
}