/* http://csloj.ddns.net/problem/25 */
#include <bits/stdc++.h>
#define LEFT id << 1
#define RIGHT id << 1 | 1

using namespace std;

typedef long long ll;

struct RECTANGLE {
    int x1, y1;
    int x2, y2;
};

const int MAXSZ = 205;
int n;
vector<RECTANGLE> a;
vector<int> cnt(MAXSZ * 4), sum(MAXSZ * 4);

bool comp(const pair<int, int> &A, const pair<int, int> &B) { return abs(A.first) < abs(B.first); }

void update(int id, int l, int r, int u, int v, int val) {
    if (r < u || l > v)
        return;
    if (u <= l && r <= v) {
        cnt[id] += val;
        if (cnt[id] != 0)
            sum[id] = r - l + 1;
        else if (l != r)
            sum[id] = sum[LEFT] + sum[RIGHT];
        else
            sum[id] = 0;
        return;
    }

    int mid = (l + r) >> 1;
    update(LEFT, l, mid, u, v, val);
    update(RIGHT, mid + 1, r, u, v, val);

    if (cnt[id] != 0)
        sum[id] = r - l + 1;
    else
        sum[id] = sum[LEFT] + sum[RIGHT];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
        a[i].x1 += 101;
        a[i].y1 += 101;
        a[i].x2 += 101;
        a[i].y2 += 101;
    }

    vector<pair<int, int>> onlyX;
    for (int i = 0; i < n; ++i) {
        onlyX.push_back({ a[i].x1, i });
        onlyX.push_back({ -a[i].x2, i });
    }

    sort(onlyX.begin(), onlyX.end(), comp);
    a.push_back(a.back());

    int xLine = onlyX[0].first, xLinePrev = xLine;
    int res = 0;
    for (int i = 0; i < 2 * n; ++i) {
        int ind = onlyX[i].second;
        if (onlyX[i].first > 0) {
            update(1, 1, MAXSZ, a[ind].y1 + 1, a[ind].y2, 1);
        } else {
            update(1, 1, MAXSZ, a[ind].y1 + 1, a[ind].y2, -1);
        }

        xLinePrev = xLine;
        xLine = abs(onlyX[i + 1].first);

        res += sum[1] * (xLine - xLinePrev);
    }

    cout << res;
    return 0;
}