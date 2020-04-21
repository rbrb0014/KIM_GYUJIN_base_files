#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[101][101] = {
        0,
    }; //n,m

    int n, m, cnt = 1;
    scanf("%d %d", &n, &m);

    for (int dia = 0; dia < n + m - 1; dia++){
        int i=0;
        while (dia >= i)
        {
            if (dia - i < m && i < n)
            {
                arr[i][dia - i] = cnt++;
            }
            i++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}