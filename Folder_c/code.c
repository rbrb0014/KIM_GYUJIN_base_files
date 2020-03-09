#include <stdio.h>
#define MAX 503

int map[MAX][MAX];
int n, m;

int bfs(int s1, int s2)
{
    if (s1 == n && s2 == m)
        return 1;
    
    int cnt = 0;
    if (0 < map[s1 - 1][s2] && map[s1 - 1][s2] < map[s1][s2])
        cnt += bfs(s1 - 1, s2);
    if (0 < map[s1 + 1][s2] && map[s1 + 1][s2] < map[s1][s2])
        cnt += bfs(s1 + 1, s2);
    if (0 < map[s1][s2 - 1] && map[s1][s2 - 1] < map[s1][s2])
        cnt += bfs(s1, s2 - 1);
    if (0 < map[s1][s2 + 1] && map[s1][s2 + 1] < map[s1][s2])
        cnt += bfs(s1, s2 + 1);
    return cnt;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    printf("%d", bfs(1, 1));

    return 0;
}

//ctrl+shift+B  gcc_compile     build
//ctrl+P    task execute_c      execute