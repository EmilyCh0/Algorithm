package week1_greedy;

import java.util.Scanner;

public class BOJ_4796 {
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		int L,P,V;
		L=scan.nextInt();
		P=scan.nextInt();
		V=scan.nextInt();
		int idx=1;	//case šřČŁ
		while(!(L==0&&P==0&&V==0)) {
			int cnt=0;
			cnt+=(V/P)*L;
			cnt+=Math.min(V%P, L);
			System.out.println("Case "+idx+": "+cnt);
			idx++;
			L=scan.nextInt();
			P=scan.nextInt();
			V=scan.nextInt();
		}
		scan.close();
	}
}
