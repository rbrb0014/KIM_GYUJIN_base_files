#include <iostream>
#include <cstring>
using namespace std;
//DP table
int dp[4][4];

int main()
{
    int input[32],output[32];

    int i,j, tmp;
    for(i = 0; i < 32; i++){
        for(j = 0; j < 32 - i - 1; j++){
            if(output[j] > output[j+1]){    // swap
                tmp = output[j];
                output[j] = output[j+1];
                output[j+1] = tmp;
            }
        }
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