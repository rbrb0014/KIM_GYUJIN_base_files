import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Solution {
  public static void main(String args[]) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int T = Integer.parseInt(br.readLine());
    for (int test_case = 1; test_case <= T; test_case++) {
      String[] buffer = br.readLine().split(" ");
      int N = Integer.parseInt(buffer[0]); // 행
      int M = Integer.parseInt(buffer[1]); // 열
      int Q = Integer.parseInt(buffer[2]); // 업데이트 수

      List<Integer> rowmax = new ArrayList<>();
      List<Integer> colmax = new ArrayList<>(Collections.nCopies(M, 0));
      List<Integer> dupRC = new ArrayList<>(Collections.nCopies(N, 0));
      for (int i = 0; i < N; i++) {
        int max = 0;
        buffer = br.readLine().split(" ");
        for (int j = 0; j < M; j++) {
          int x = Integer.parseInt(buffer[j]);
          if (max < x)
            max = x;
          if (colmax.get(j) < x)
            colmax.set(j, x);
        }
        rowmax.add(max);
        dupRC.add(max);
      }
      dupRC.retainAll(colmax);
      Collections.sort(dupRC);

      int sum = 0;
      for (int q = 0; q < Q; q++) {
        buffer = br.readLine().split(" ");
        int r = Integer.parseInt(buffer[0]) - 1;
        int c = Integer.parseInt(buffer[1]) - 1;
        int x = Integer.parseInt(buffer[2]);

        boolean flagR = false, flagC = false;

        int row = rowmax.get(r);
        if (row < x) {
          flagR = true;
          rowmax.set(r, x);
          int idx = Collections.binarySearch(dupRC, row);
          if (idx > -1)
            dupRC.remove(idx);
        }

        int col = colmax.get(c);
        if (col < x) {
          flagC = true;
          colmax.set(c, x);
          int idx = Collections.binarySearch(dupRC, col);
          if (idx > -1)
            dupRC.remove(idx);
        }

        if (flagR && flagC) {
          int idx = Collections.binarySearch(dupRC, x);
          if (idx < 0)
            dupRC.add(-idx - 1, x);
        }

        sum += dupRC.size();
      }

      System.out.print("#" + test_case + " " + sum + '\n');
    }
  }
}