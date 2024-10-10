/*
    题目描述：
    给定n * (n+1)矩阵，代表系数/常数
    求解未知数
*/
#include <iostream>
#include <cmath>
using namespace std;
const int MAXN = 110;
const double ESP = 1e-9;

int n;
double matrix[MAXN][MAXN], ans[MAXN];

// 大小 n * n，最右边的第 m+1 列为常数
// 无解/多解 返回 0，有解返回 1
int gauss(int n, double matrix[][MAXN], double ans[])
{
    // 化成最简形，注意对角线的性质
    // i -> 行; j -> 列;
    for(int j = 1; j <= n; ++j)
    {
        int r = j;  // 当前列系数最大的行数
        for(int i = j+1; i <= n; ++i)
        {
            if(fabs(matrix[i][j]) > fabs(matrix[r][j]))
                r = i;
        }
        if(fabs(matrix[r][j]) < ESP)
            return 0;  // 某一列出现全0，无解 / 多解
        if(j != r)
            swap(matrix[r], matrix[j]);  // 对角线 i==j，将系数最大行交换至当前处理行
        for(int j2 = n+1; j2 >= j; --j2)
            matrix[j][j2] /= matrix[j][j];
        for(int i = j+1; i <= n; ++i)
            for(int j2 = n+1; j2 >= j; --j2)
                matrix[i][j2] -= matrix[j][j2] * matrix[i][j];
    }
    // 回带操作
    ans[n] = matrix[n][n+1];
    for(int i = n-1; i >= 1; --i)
    {
        ans[i] = matrix[i][n+1];
        for(int i2 = i+1; i2 <= n; ++i2)
            ans[i] -= ans[i2] * matrix[i][i2];
    }
    return 1;
}

/* 求解异或方程组

#include <bitset>
#include <vector>

bitset<1010> matrix[2010];  // matrix[1~n+1]：n+1 位置为常数

// n 为未知数个数(列)，m 为方程个数()，返回方程组的解
// 无解 / 多解返回空vector<bool>
// 无解: 方程化为最简式后，某一行除常数外均为0
// 多解: 方程化为最简式后，某一行均为0
vector<bool> gauss(int n, int m)
{
    if(n > m)  // ?
        return vector<bool>(0);
    for(int j = 1; j <= n; ++j)
    {
        int cur = j;
        // 寻找当前列中为 1 的行
        while(cur <= m && !matrix[cur][j])
            ++cur;
        if(cur > m)  // 当前列均为0，出现无解 / 多解
            return vector<bool>(0);
            // continue;
        if(cur != j)
            swap(matrix[cur], matrix[j]);
        for(int i = 1; i <= m; ++i)
            if(i != j && matrix[i][j])
                matrix[i] ^= matrix[j];
    }
    vector<bool> ans(n+1, 0);
    for(int i = 1; i <= n; ++i)
        ans[i] = matrix[i][n+1];
    return ans;
}
*/

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n+1; ++j)
            scanf("%lf", &matrix[i][j]);
    if(gauss(n, matrix, ans))
    {
        for(int i = 1; i <= n; ++i)
            printf("%.2lf\n", ans[i]);
    }
    else
    {
        printf("No Solution\n");
    }
    return 0;
}