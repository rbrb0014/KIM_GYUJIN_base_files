package util;
public class FloydWarshall {
    /**
     * @param dist 2차원배열
     * 플로이드-와샬 기법으로 최단거리를 만드는 방법입니다~
     */
    static void floydWarshall(int[][] dist) {
        for (int k = 1; k <= dist.length; k++) {
            for (int i = 1; i <= dist.length; i++) {
                for (int j = 1; j <= dist.length; j++) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
}