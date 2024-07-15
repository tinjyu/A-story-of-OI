#include "soccer.h"
#include <iostream>
long long int dp[505][2][505];
long long int dp_left[505][2][505], dp_right[505][2][505];
long long int left_bound[505][505], right_bound[505][505];

using namespace std;

int biggest_stadium(int N, std::vector<std::vector<int>> F)
{

    long long int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int lf = -1;
        for (int j = 0; j < N; j++)
        {
            if (F[i][j] == 1)
            {
                lf = j;
            }
            left_bound[i][j] = lf;
        }
        int rf = N;
        for (int j = N - 1; j >= 0; j--)
        {
            if (F[i][j] == 1)
            {
                rf = j;
            }
            right_bound[i][j] = rf;
        }
    }
    int now = 1, pre = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (F[i][j] == 1)
            {
                dp[i][0][j] = -1;
            }
            else
            {
                dp[i][0][j] = right_bound[i][j] - left_bound[i][j] - 1;
                dp_left[i][0][j] = left_bound[i][j];
                dp_right[i][0][j] = right_bound[i][j];
            }
            ans = max(ans, dp[i][0][j]);
        }
    }

    for (int len = 2; len <= N; len++)
    {
        for (int i = 0; i + len - 1 < N; i++)
        {
            for (int col = 0; col < N; col++)
            {

                int up = i, down = i + len - 1;
                // cout << dp[up][down][col] << " " << up << " " << down << " " << col << endl;

                if (F[up][col] == 0)
                {
                    int lf = max(dp_left[up + 1][pre][col], left_bound[up][col]);
                    int ri = min(dp_right[up + 1][pre][col], right_bound[up][col]);
                    dp[up][now][col] = dp[up + 1][pre][col] + ri - lf - 1;
                    dp_left[up][now][col] = lf;
                    dp_right[up][now][col] = ri;
                }
                if (F[down][col] == 0)
                {
                    int lf = max(dp_left[up][pre][col], left_bound[down][col]);
                    int ri = min(dp_right[up][pre][col], right_bound[down][col]);
                    if (dp[up][pre][col] + ri - lf - 1 > dp[up][now][col])
                    {

                        dp[up][now][col] = max(dp[up][pre][col] + ri - lf - 1, dp[up][now][col]);
                        dp_left[up][now][col] = lf;
                        dp_right[up][now][col] = ri;
                    }
                }
                // cout << dp[up][down][col] << " " << up << " " << down << " " << col << endl;
                ans = max(ans, dp[up][now][col]);
            }
        }
        swap(now, pre);
    }
    return ans;
}
