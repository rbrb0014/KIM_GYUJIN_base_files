
/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// double b;
// char g;
// String var;
// long AB;
// a = sc.nextInt();                           // int 변수 1개 입력받는 예제
// b = sc.nextDouble();                        // double 변수 1개 입력받는 예제
// g = sc.nextByte();                          // char 변수 1개 입력받는 예제
// var = sc.next();                            // 문자열 1개 입력받는 예제
// AB = sc.nextLong();                         // long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// double b = 1.0;               
// char g = 'b';
// String var = "ABCDEFG";
// long AB = 12345678901234567L;
//System.out.println(a);                       // int 변수 1개 출력하는 예제
//System.out.println(b); 		       						 // double 변수 1개 출력하는 예제
//System.out.println(g);		       						 // char 변수 1개 출력하는 예제
//System.out.println(var);		       				   // 문자열 1개 출력하는 예제
//System.out.println(AB);		       				     // long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
import java.util.*;

/*
   사용하는 클래스명이 Solution 이어야 하므로, 가급적 Solution.java 를 사용할 것을 권장합니다.
   이러한 상황에서도 동일하게 java Solution 명령으로 프로그램을 수행해볼 수 있습니다.
 */
class SamSolutionSub {
  public static void main(String args[]) throws Exception {
    Scanner sc = new Scanner(System.in);

    int T = sc.nextInt();
    for (int test_case = 1; test_case <= T; test_case++) {
      int N = sc.nextInt(); // 행
      int M = sc.nextInt(); // 열
      int Q = sc.nextInt(); // 업데이트 수

      // setup map
      int[] row_min = new int[N]; // 각 행에서 최소값
      int[] col_min = new int[M]; // 각 열에서 최소값
      Arrays.fill(row_min, MAX);
      Arrays.fill(col_min, MAX);

      // 최초 입력
      for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
          int val = sc.nextInt();
          if (row_min[i] > val)
            row_min[i] = val;
          if (col_min[j] > val)
            col_min[j] = val;
        }
      
      int[] row_min_copy = row_min.clone();
      // 행열의 중복된 값을 찾아 개수를 셈
      int sum = 0;

      for (int i = 0; i < Q; i++) {
        int r = sc.nextInt();
        int c = sc.nextInt();
        int x = sc.nextInt();

        if(row_min[r]>x)
          row_min[r] = x;
        if (col_min[c] > x)
          col_min[c] = x;
      }

      System.out.println("#" + test_case + " ");
    }
    sc.close();
  }

  static int MAX = 4000000;
}