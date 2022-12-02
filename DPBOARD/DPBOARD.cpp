/* http://csloj.ddns.net/problem/436 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> a(n+1, vector<int> (n+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            a[i][j] = ((i+j)%2 == 0 ? a[i][j] : -a[i][j]);
        }
    }
            
    vector<vector<int>> s(n+1, vector<int> (n+1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            s[i][j] = s[i][j-1] + s[i-1][j] - s[i-1][j-1] + a[i][j];

    int q;
    cin >> q;

    while (q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << abs(s[r2][c2] - s[r1-1][c2] - s[r2][c1-1] + s[r1-1][c1-1]) << '\n';
    }
    return 0;
}