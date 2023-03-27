/* http://csloj.ddns.net/problem/397 */

#include <bits/stdc++.h>
#define SZ 9

using namespace std;

typedef long long ll;

vector<pair<int, int>> pos;

bool check(char table[SZ][SZ], int row, int col, char digit);
bool checkBox(char table[SZ][SZ], int boxStartrow, int boxStartCol, char digit);
bool backtracking(char table[SZ][SZ], int ind);

bool check(char table[SZ][SZ], int row, int col, char digit) {
    for (int k = 0; k < SZ; ++k)
        if (table[row][k] == digit || table[k][col] == digit) return false;
    return true;
}

bool checkBox(char table[SZ][SZ], int boxStartrow, int boxStartCol, char digit) {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (table[row + boxStartrow][col + boxStartCol] == digit) return false;
        }
    }
    return true;
}

bool backtracking(char table[SZ][SZ], int ind) {
    if (ind == pos.size()) return true;

    int row = pos[ind].first, col = pos[ind].second;
    for (char digit = '9'; digit >= '1'; --digit) {
        if (check(table, row, col, digit) && checkBox(table, row - row % 3, col - col % 3, digit)) {
            table[row][col] = digit;
            if (backtracking(table, ind + 1)) return true;
            table[row][col] = '.';
        }
    }   

    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    char table[SZ][SZ];
    for (int i = 0; i < SZ; ++i) {
        for (int j = 0; j < SZ; ++j) {
            cin >> table[i][j];
            if (table[i][j] == '.')
                pos.push_back({ i, j });
        }
    }

    if (backtracking(table, 0)) {
        for (int i = 0; i < SZ; ++i)
            for (int j = 0; j < SZ; ++j) cout << table[i][j];
    }
    return 0;
}