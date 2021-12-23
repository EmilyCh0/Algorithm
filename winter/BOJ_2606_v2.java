package week5_GraphTree;

import java.util.LinkedList;
import java.util.Scanner;
public class BOJ_2606_v2 {
	static LinkedList<Integer>[] list;	
	static int N;
	static int cnt;
	static boolean[] isUsed;
	public static void func(int k) {
		while(!list[k].isEmpty()) {
			int next = list[k].poll();
			if(!isUsed[next]) {
				cnt++;
				isUsed[next]=true;
				func(next);
			}
		}
	}
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		N = scan.nextInt();
		list = new LinkedList[N+1];
		for(int i=0;i<N+1;i++) {
			list[i]=new LinkedList<>();
		}
		isUsed = new boolean[N+1];		
		int M = scan.nextInt();
		for(int i=0;i<M;i++) {
			int tmp1=scan.nextInt();
			int tmp2=scan.nextInt();
			list[tmp1].add(tmp2);
			list[tmp2].add(tmp1);
		}
		cnt=0;
		isUsed[1]=true;
		func(1);
		System.out.print(cnt);
	}
}
