package baekjoon_s;
import java.util.*;
public class BOJ_1065 {
	public static void main(String args[]) {
		Scanner scan=new Scanner(System.in);
		int N=scan.nextInt();
		if(N<100) {
			System.out.print(N);
		}
		else if(N<1000) {
			int ans=99;
			int a=N/100;
			for(int i=1;i<=a;i++) {
				int r=0;
				while(i+r+r<10) {
					int tmp=0;
					tmp+=i;
					tmp*=10;
					tmp+=i+r;
					tmp*=10;
					tmp+=i+r+r;
					if(tmp<=N)
						ans++;
					else
						break;
					r++;
				}
				r=i/2;
				while(i-r-r>=0&&r!=0) {
					int tmp=0;
					tmp+=i;
					tmp*=10;
					tmp+=i-r;
					tmp*=10;
					tmp+=i-r-r;
					if(tmp<=N)
						ans++;
					r--;
				}
			}
			System.out.print(ans);
		}
		else {
			System.out.print(144);
		}
	}
}
