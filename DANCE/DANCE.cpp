/* http://csloj.ddns.net/problem/243 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int m, n;
    cin >> m >> n;
    vector<int> men(m), women(n);
    for (int i = 0; i < m; ++i)
        cin >> men[i];
    for (int i = 0; i < n; ++i)
        cin >> women[i];

    sort(men.begin(), men.end());
    sort(women.begin(), women.end());

    int i = 0, j = 0;
    int res = 0;
    while (i < m) {
        while (i < m && j < n && men[i] <= women[j])
            i++;
        if (i < m && j < n && men[i] > women[j])
            res++, i++, j++;
        else i++;
    }
    
    cout << res;
    return 0;
}