package spring01;
import java.util.*;
public class BOJ_10448 {
	static int sum;
	static int tri[];
	static boolean calc(int n) {
		for(int j=1;j<45;j++) {
			for(int k=1;k<45;k++) {
				for(int l=1;l<45;l++) {
					if(n==tri[j]+tri[k]+tri[l])
						return true;
				}
			}
		}
		return false;
	}
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		int T=scan.nextInt();
		// 45*46=2070
		tri = new int[45];
		int tmp=0;
		for(int i=1;i<45;i++) {
			tmp+=i;
			tri[i]=tmp;
		}	
		for(int i=0;i<T;i++) {
			int n=scan.nextInt();
			if(calc(n))
				System.out.println(1);
			else
				System.out.println(0);
		}
	}
}
