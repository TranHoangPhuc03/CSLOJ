/* http://csloj.ddns.net/problem/392 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int SZ = 12;

int n;
int res;
bool chess[SZ][SZ];
int ans[SZ];

bool check(int row, int col)
{
    for (int k = 1; k <= n; ++k) {
        if (row-k >= 0 && col-k >= 0 && chess[row-k][col-k])
            return false;
        if (row+k < n && col+k < n && chess[row+k][col+k])
            return false;
        if (row-k >= 0 && col+k < n && chess[row-k][col+k])
            return false;
        if (row+k < n && col-k >= 0 && chess[row+k][col-k])
            return false;
        if (row-k >= 0 && chess[row-k][col])
            return false;
        if (row+k < n && chess[row+k][col])
            return false;
        if (col-k >= 0 && chess[row][col-k])
            return false;
        if (col+k < n && chess[row][col+k])
            return false;
    }

    return true;
}

void backtracking(int row)
{
    if (row == n) {
        res++;
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < n; ++i) {
                if (chess[i][j])
                    ans[j] = i+1;
            }
        }
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (check(row, col)) {
            chess[row][col] = true;
            backtracking(row+1);
            chess[row][col] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    backtracking(0);

    cout << res << '\n';
    if (res != 0) {
        for (int j = 0; j < n; ++j)
            cout << ans[j] << ' ';
    }
    return 0;
}