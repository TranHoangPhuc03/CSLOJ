/* http://csloj.ddns.net/problem/627 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll L, R;

ll _count(ll x)
{
    if (L%x == 0) return R/x - L/x + 1;
    return R/x - L/x;
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        cin >> L >> R;

        cout << _count(4) + _count(7) + _count(11) - _count(28) - _count(77) - _count(44) + _count(308) << '\n';
    }
    return 0;
}