package week6;
import java.util.*;
public class BOJ_10159 {
	public static void main(String args[]) {
		Scanner scan = new Scanner (System.in);
		int N = scan.nextInt();
		int M = scan.nextInt();
		boolean arr[][] = new boolean[N+1][N+1];	
		for(int i=0;i<M;i++) {
			int a = scan.nextInt();
			int b = scan.nextInt();
			arr[a][b]=true;
		}
		for(int i=1;i<=N;i++) {
			for(int j=1;j<=N;j++) {
				for(int k=1;k<=N;k++) {
					if(arr[j][i]&&arr[i][k]) {
						// if (arr[i][j]&&arr[j][k]) arr[i][k]=true는 왜 틀림?
						arr[j][k]=true;
					}
				}
			}
		}
		for(int i=1;i<=N;i++) {
			int cnt=-1;
			for(int j=1;j<=N;j++) {
				if(!arr[i][j]&&!arr[j][i]) {
					cnt++;
				}
			}
			System.out.println(cnt);
		}
	}
}


/*
//Test Case
9
11
2 1
3 1
2 8
2 9
7 8
4 5
6 7
6 3
1 7
6 2
1 9
2
3
3
7
7
2
3
3
4
------

5
6
1 2
1 3
1 5
3 2
3 4
4 5
*/