#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<stdlib.h>

#define MAXN 10000
#define mk make_pair
using namespace std;

bool chk[MAXN + 1];
int D[MAXN + 1];
vector< pair<int, int> > edge[MAXN + 1];
priority_queue< pair<int, int> > que;

int main() {
	int n, m, i, j, a, b, d, s, v, u;
	//d 가중치(길이)
	scanf("%d %d", &n, &m);//엣지수,간선수
	scanf("%d", &s);//시작점 받기
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &d);
		edge[a].push_back(mk(b, d));
	}
	for (int i = 1; i <= n; i++)
		D[i] = 200000;
	
	que.push(mk(0, s));
	while (!que.empty()) {
		v = que.top().second;
		d = que.top().first;
		que.pop();

		if (chk[v]) continue;
		chk[v] = true;
		D[v] = d;

		for (i = 0; i < edge[v].size(); i++) {
			u = edge[v][i].first;
			d = edge[v][i].second;

			que.push(mk(D[v] - d, u));
		}
	}

	for (i = 1; i <= n; i++)
		if (D[i] != 200000)
			printf("%d\n", -D[i]);
		else
			printf("INF\n");


	return 0;
}