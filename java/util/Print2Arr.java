package util;
public class Print2Arr {
    /**
     * @param arr 2차원배열
     * @param x 출력범위 1
     * @param y 출력법위 2
     */
    static void print2Arr(int[][] arr, int x, int y) {
        for (int i = 1; i <= x; i++) {
            int[] inArr = arr[i];
            for (int j = 1; j <= y; j++) {
                System.out.print(inArr[j] + " ");
            }
            System.out.println();
        }
    }
}