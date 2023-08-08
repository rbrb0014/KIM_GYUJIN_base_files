import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < 10; i++) {
            int N = sc.nextInt();
            int[] building = new int[1000];
            int[] jomang = new int[1000];

            for (int j = 0; j < N; j++)
                building[j] = sc.nextInt();

            for (int j = 2; j < N - 2; j++) {
                // 각 건물마다 양쪽 옆을 비교함
                int L2 = building[j] - building[j - 2];
                int L1 = building[j] - building[j - 1];
                int R1 = building[j] - building[j + 1];
                int R2 = building[j] - building[j + 2];

                // 0이 되면 바로 끝내고 넘어감
                if (L2 <= 0 || L1 <= 0 || R1 <= 0 || R2 <= 0) {
                    jomang[j] = 0;
                    continue;
                }

                // 왼쪽끝부터 봐서 위에서 몇개 층이 조망 가능한지 적어둠
                jomang[j] = Math.min(Math.min(L2, L1), Math.min(R1, R2));
                // 비교하면서 점점 줄어들면 그만큼 빼줌
            }

            int sum = Arrays.stream(jomang).sum();
            System.out.print("#" + (i + 1) + " ");
            System.out.println(sum);
        }
        sc.close();
    }
}