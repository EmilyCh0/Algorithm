package week5_GraphTree;

import java.util.*;
public class BOJ_2606 {
	static boolean arr[][];
	static int N;
	static int cnt;
	static boolean[] isUsed;
	static Queue<Integer> que = new LinkedList<>();
	public static void func(int k) {
		for(int i=1;i<N+1;i++) {
			if(arr[k][i]&&!isUsed[i]) {
				isUsed[i]=true;
				cnt++;
				que.add(i);
			}
		}
	}
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		N = scan.nextInt();
		arr = new boolean[N+1][N+1];
		isUsed = new boolean[N+1];
		int M = scan.nextInt();
		for(int i=0;i<M;i++) {
			int tmp1=scan.nextInt();
			int tmp2=scan.nextInt();
			arr[tmp1][tmp2]=arr[tmp2][tmp1]=true;
		}
		cnt=0;
		func(1);
		isUsed[1]=true;
		while(!que.isEmpty()) {
			int next=que.poll();
			func(next);
		}
		System.out.print(cnt);
	}
}
