#include <bits/stdc++.h>
using namespace std;
int ans[5000][5000];
int main() {
    int n;
    cin >> n;

    // ans[i][j]是0，代表(i,j)是'.'
    // ans[i][j]是1，代表(i,j)是'*'

    // 一级好豆子
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 6; ++j) {
            ans[i][j] = 1;
        }
    }
    for (int i = 4; i <= 6; ++i) {
        for (int j = 1; j <= 3; ++j) {
            ans[i][j] = 1;
        }
    }

    int m = 6;
    for (int i = 2; i <= n; ++i) {
        // 计算i级好豆子
        // 将复制到右下角
        for (int j = 1; j <= m; ++j) {
            for (int k = 1; k <= m; ++k) {
                ans[j + m][k + m] = ans[j][k];
            }
        }
        for (int j = m + 1; j <= m * 2; ++j) {
            for (int k = m + 1; k <= m * 2; ++k) {
                // 取反，并复制到左上、右上、左下
                ans[j - m][k] = !ans[j][k];
                ans[j][k - m] = !ans[j][k];
                ans[j - m][k - m] = !ans[j][k];
            }
        }
        // i+1级好豆子对比i级好豆子，长和宽都是2倍
        m *= 2;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (ans[i][j]) {
                cout << "*";
            } else {
                cout << '.';
            }
        }
        cout << endl;
    }
    return 0;
}