#include <iostream>
#include <cstring>
using namespace std;
//최댓값 설정
const int MAX = 20 + 1;
//DP table
int dp[MAX][MAX][MAX];

int w(int, int, int);

int main()
{
    int a, b, c;
    while (1)
    {
        //입력받아 실행조건인지 탈출조건인지 구분
        scanf("%d %d %d", &a, &b, &c);
        if (a == -1 && b == -1 && c == -1)
            break;

        //출력부분
        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    }
    return 0;
}

int w(int a, int b, int c)
{
    //루프의 종결에 가까워짐
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if (a >= MAX || b >= MAX || c >= MAX)
        return w(20, 20, 20);

    //실 w함수
    int &result = dp[a][b][c];
    if (result != 0)
        return result;
    //w(a,b,c) 값이 없을 경우 채우고 반환
    if (a < b && b < c)
        result = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    else
        result = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);

    return result;
}