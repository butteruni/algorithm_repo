#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, L[1 << 19], R[1 << 19];
int M, A[1 << 19], B[1 << 19];
int Imos1[1 << 19];
int Imos2[1 << 19];
long double Average[1 << 19];
long double Sum[1 << 19];
long double Cnt[1 << 19];
long double Diff[1 << 19];
vector<pair<int, int>> Zahyou;

int main()
{
    // Step 0. Input
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> L[i] >> R[i];
    }
    for (int i = 1; i <= M; i++)
    {
        cin >> A[i] >> B[i];
    }

    // Step 2. Compression
    for (int i = 1; i <= N; i++)
        Zahyou.push_back(make_pair(L[i], 1));
    for (int i = 1; i <= N; i++)
        Zahyou.push_back(make_pair(R[i], 2));
    for (int i = 1; i <= M; i++)
        Zahyou.push_back(make_pair(A[i], 1));
    for (int i = 1; i <= M; i++)
        Zahyou.push_back(make_pair(B[i], 2));
    sort(Zahyou.begin(), Zahyou.end());
    Zahyou.erase(unique(Zahyou.begin(), Zahyou.end()), Zahyou.end());
    for (int i = 0; i < Zahyou.size() - 1; i++)
    {
        if (Zahyou[i].first == Zahyou[i + 1].first)
            Diff[i] = 1.0e-18L;
        else
            Diff[i] = 1.0L * (Zahyou[i + 1].first - Zahyou[i].first);
    }

    // Step 3. Binary Search
    for (int i = 1; i <= N; i++)
        L[i] = lower_bound(Zahyou.begin(), Zahyou.end(), make_pair(L[i], 1)) - Zahyou.begin();
    for (int i = 1; i <= N; i++)
        R[i] = lower_bound(Zahyou.begin(), Zahyou.end(), make_pair(R[i], 2)) - Zahyou.begin();
    for (int i = 1; i <= M; i++)
        A[i] = lower_bound(Zahyou.begin(), Zahyou.end(), make_pair(A[i], 1)) - Zahyou.begin();
    for (int i = 1; i <= M; i++)
        B[i] = lower_bound(Zahyou.begin(), Zahyou.end(), make_pair(B[i], 2)) - Zahyou.begin();
    for (int i = 1; i <= N; i++)
    {
        Imos1[L[i]] += 1;
        Imos1[R[i]] -= 1;
    }
    for (int i = 1; i <= M; i++)
    {
        Imos2[A[i]] += 1;
        Imos2[B[i]] -= 1;
    }
    for (int i = 1; i <= Zahyou.size(); i++)
        Imos1[i] += Imos1[i - 1];
    for (int i = 1; i <= Zahyou.size(); i++)
        Imos2[i] += Imos2[i - 1];

    // Step 4. Cumulative Sum
    for (int i = 0; i < Zahyou.size() - 1; i++)
        Average[i] = 0.5L * (Zahyou[i].first + Zahyou[i + 1].first);
    for (int i = 0; i < Zahyou.size() - 1; i++)
    {
        Sum[i + 1] = Sum[i];
        Cnt[i + 1] = Cnt[i];
        if (Imos1[i] == 0)
            continue;
        Sum[i + 1] += 1.0L * Diff[i] * Average[i];
        Cnt[i + 1] += 1.0L * Diff[i];
    }

    // Step 5. Brute Force
    long double Answer = 0.0L;
    for (int i = 0; i < Zahyou.size() - 1; i++)
    {
        if (Imos2[i] == 0)
            continue;
        if (Imos1[i] >= 1)
        {
            long double v1 = Diff[i];
            long double v2 = Diff[i];
            long double v3 = 1.0L * Diff[i] / 3.0L;
            Answer += v1 * v2 * v3;
        }

        // Left
        if (Cnt[i] != Cnt[0])
        {
            long double v1 = Diff[i];
            long double v2 = (Cnt[i] - Cnt[0]);
            long double v3 = Average[i] - (Sum[i] - Sum[0]) / (Cnt[i] - Cnt[0]);
            Answer += v1 * v2 * v3;
        }

        // Rigt
        if (Cnt[Zahyou.size() - 1] != Cnt[i + 1])
        {
            long double v1 = Diff[i];
            long double v2 = (Cnt[Zahyou.size() - 1] - Cnt[i + 1]);
            long double v3 = (Sum[Zahyou.size() - 1] - Sum[i + 1]) / (Cnt[Zahyou.size() - 1] - Cnt[i + 1]) - Average[i];
            Answer += v1 * v2 * v3;
        }
    }

    // Step 6. Output
    long double R1 = 0.0L;
    long double R2 = 0.0L;
    for (int i = 0; i < Zahyou.size(); i++)
    {
        if (Imos1[i] >= 1)
            R1 += Diff[i];
        if (Imos2[i] >= 1)
            R2 += Diff[i];
    }
    printf("%.12Lf\n", Answer / (R1 * R2));
    return 0;
}