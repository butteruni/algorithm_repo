#include <bits/stdc++.h>
// #define int long long
#define ll long long
#define next nxt
#define re register
#define il inline
const int N = 1e5 + 5;
const double eps = 1e-6;
const double Pi = acos(-1.0);
using namespace std;

struct Point
{
    double x, y;
} a[N], b[N], s[N], h[N], A[N], G[N], d, st;
int n, m, q, tot;

int read()
{
    int f = 0, s = 0;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        f |= (ch == '-');
    for (; isdigit(ch); ch = getchar())
        s = (s << 1) + (s << 3) + (ch ^ 48);
    return f ? -s : s;
}

Point operator+(Point a, Point b) { return Point{a.x + b.x, a.y + b.y}; } // 加

Point operator-(Point a, Point b) { return Point{a.x - b.x, a.y - b.y}; } // 减

double operator*(Point a, Point b) { return a.x * b.y - a.y * b.x; } // 叉积

double operator&(Point a, Point b) { return a.x * b.x + a.y * b.y; } // 点积

double cross(Point a, Point b, Point c) { return (b - a) * (c - a); } // 判断c和直线ab的关系

double len(Point a) { return sqrt(a & a); }

bool cmp(Point a, Point b) { return a.x == b.x ? a.y < b.y : a.x < b.x; } // 以x为第一关键字，y为第二关键字排序

bool cmp2(Point a, Point b) { return a * b > 0 || (a * b == 0 && len(a) < len(b)); } // 按极角序排序，如果极角相同短的放前边

void ConvexHull(Point *s, Point *p, int &n) // s是凸包数组，p是原数组
{
    int cnt = 0;
    sort(p + 1, p + n + 1, cmp);
    s[++cnt] = p[1];
    for (re int i = 2; i <= n; i++) // Andrew求凸包
    {
        while (cnt > 1 && cross(s[cnt - 1], s[cnt], p[i]) <= 0)
            cnt--;
        s[++cnt] = p[i];
    }
    int t = cnt;
    for (re int i = n - 1; i >= 1; i--)
    {
        while (cnt > t && cross(s[cnt - 1], s[cnt], p[i]) <= 0)
            cnt--;
        s[++cnt] = p[i];
    }
    n = cnt - 1; // 第一个点加了两次，别忘了-1
}

void Minkovski()
{
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b); // 重复利用一下a,b数组，其实可以不memset
    for (re int i = 1; i < n; i++)
        a[i] = s[i + 1] - s[i];
    a[n] = s[1] - s[n]; // 最后一条线单独写一下
    for (re int i = 1; i < m; i++)
        b[i] = h[i + 1] - h[i];
    b[m] = h[1] - h[m];
    int p1 = 1, p2 = 1;
    tot = 1, G[tot] = s[1] + h[1]; // 以s[1]+t[1]为起点开始加
    while (p1 <= n && p2 <= m)
        tot++, G[tot] = G[tot - 1] + (a[p1] * b[p2] >= 0 ? a[p1++] : b[p2++]);
    while (p1 <= n)
        tot++, G[tot] = G[tot - 1] + a[p1++];
    while (p2 <= m)
        tot++, G[tot] = G[tot - 1] + b[p2++];
}

bool Judge(Point a)
{
    if (a * A[1] > 0 || A[tot] * a > 0)
        return 0;                                               // 绝对不可能在凸包内的情况
    int pos = lower_bound(A + 1, A + tot + 1, a, cmp2) - A - 1; // lower_bound求的是第一个极角序不小于它的，所以减个1
    return (a - A[pos]) * (A[pos % tot + 1] - A[pos]) <= 0;     // 如上文所说
}

signed main()
{
    n = read(), m = read(), q = read();
    for (re int i = 1; i <= n; i++)
        scanf("%lf%lf", &a[i].x, &a[i].y);
    for (re int i = 1; i <= m; i++)
        scanf("%lf%lf", &b[i].x, &b[i].y), b[i].x = -b[i].x, b[i].y = -b[i].y;
    ConvexHull(s, a, n);
    ConvexHull(h, b, m);
    Minkovski();
    ConvexHull(A, G, tot);
    st = A[1]; // 选定一个基准点，并且把这个基准点平移到(0,0)的位置上，这样有利于我们求极角序
    for (re int i = 1; i <= tot; i++)
        A[i] = A[i] - st; // 别的也减一下
    while (q--)
    {
        scanf("%lf%lf", &d.x, &d.y);
        printf("%d\n", Judge(d - st)); // 这个也别忘了减
    }
    return 0;
}