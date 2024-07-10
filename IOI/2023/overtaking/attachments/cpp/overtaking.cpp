#include "overtaking.h"
#include <algorithm>
#include <iostream>

using namespace std;

long long int q, y, n, m, l, x;
long long int t[1005][1005], T[1005], w[1005];
long long int s[1005];

class Time
{
public:
    long long int ti, speed, id;
    bool operator<(const Time &Ti)
    {
        if (ti != Ti.ti)
            return ti < Ti.ti;
        return speed < Ti.speed;
    }
} prevtime[1005], sorted_time[1005][1005];
long long int pre_max_time[1005][1005];
void init(int L, int N, std::vector<long long> _T, std::vector<int> W, int X, int M, std::vector<int> S)
{
    n = N;
    x = X;
    m = M;
    for (int i = 0; i < n; i++)
    {
        T[i] = _T[i];
        w[i] = W[i];
        t[0][i] = T[i];
        prevtime[i].ti = T[i];
        prevtime[i].speed = W[i];
        prevtime[i].id = i;
    }
    for (int i = 0; i < m; i++)
        s[i] = S[i];
    for (int i = 1; i < m; i++)
    {
        sort(prevtime, prevtime + n);
        long long int premax = 0;
        for (int j = 0; j < n; j++)
        {
            long long int nxttime = prevtime[j].ti + (S[i] - S[i - 1]) * prevtime[j].speed;
            t[i][prevtime[j].id] = max(premax, nxttime);
            premax = max(premax, t[i][prevtime[j].id]);
        }

        for (int j = 0; j < n; j++)
        {
            prevtime[j].ti = t[i][j];
            prevtime[j].speed = W[j];
            prevtime[j].id = j;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sorted_time[i][j].ti = t[i][j];
            sorted_time[i][j].speed = W[j];
            sorted_time[i][j].id = j;
        }
        sort(sorted_time[i], sorted_time[i] + n);
        for (int j = 0; j < n; j++)
        {
            pre_max_time[i][j] = t[i + 1][sorted_time[i][j].id];

            if (j != 0)
                pre_max_time[i][j] = max(pre_max_time[i][j], pre_max_time[i][j - 1]);
            // cout << i << " " << j << " " << pre_max_time[i][j] << " " << sorted_time[i][j].id << endl;
        }
    }
    return;
}

long long arrival_time(long long Y)
{
    for (int i = 0; i < m - 1; i++)
    {
        Time now;
        now.ti = Y;
        now.speed = x;
        int l = 0, r = n - 1, tar = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (now < sorted_time[i][mid])
            {
                r = mid - 1;
            }
            else
            {
                tar = mid;
                l = mid + 1;
            }
        }
        Y += (s[i + 1] - s[i]) * x;
        if (tar != -1)
        {
            Y = max(Y, pre_max_time[i][tar]);
        }
    }
    return Y;
}