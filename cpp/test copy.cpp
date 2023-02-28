#include <iostream>
#include <cstring>
using namespace std;
//DP table
int dp[4][4];

int main()
{
    for (int i = 0; i < 4; i++)
        dp[0][i] = i + 1;

    for (int i = 1; i < 4; i++)
    {
    }
}

bool right(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        if (i == y)
            continue;
        if (dp[x][i] == dp[x][y])
            return false;
    }
    for (int i = 0; i < 4; i++)
    {
        if (i == x)
            continue;
        if (dp[i][y] == dp[x][y])
            return false;
    }
    return true;
}