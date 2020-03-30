#include <stdio.h>
#include <stdlib.h>
#define SECURE_NO_WARNINGS_
typedef struct
{
    long long gene;
    int num;
} baby;

baby N[1000005];
int ary[11];

int compare(const void *a, const void *b)
{
    baby num1 = *(baby *)a;
    baby num2 = *(baby *)b;

    if (num1.gene < num2.gene)
        return 1;

    if (num1.gene > num2.gene)
        return -1;

    return 0;
}

int main()
{
    int n, k, p; //아기수,유전자개수,발현수최대치
    scanf("%d %d %d", &n, &k, &p);
    ary[0] = 1;
    for (int i = 0; i < 10; i++)
        ary[i + 1] = ary[i] * (p + 1); //진수설정
    for(int i=0;i<n;i++)
        N[i].num = i + 1;

    for (int i = 0; i < k; i++)//유전자 수에 맞게
    {
        for (int j = 0; j < n; j++)//사람 수에 맞게
        {
            long long tmp;
            scanf("%d", &tmp);
            N[j].gene = tmp * ary[i];
        }
    }
    
    qsort(N, n, sizeof(baby), compare);

    for(int i=0;i<n;i++)
        printf("%d ",N[i].num);
}

//ctrl+shift+B  gcc_compile     build
//ctrl+P    task execute_c      execute