package baekjoon_s;
import java.util.*;
public class BOJ_1004 {
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		int N=scan.nextInt();
				
		for(int i=0;i<N;i++) {
			int cnt=0;
			int a=scan.nextInt();
			int b=scan.nextInt();
			int c=scan.nextInt();
			int d=scan.nextInt();
			int T=scan.nextInt();
			for(int j=0;j<T;j++) {
				int x=scan.nextInt();
				int y=scan.nextInt();
				int r=scan.nextInt();
				if(Math.pow(x-a, 2)+Math.pow(y-b, 2)<Math.pow(r, 2)) {
					cnt++;
				}
				else if(Math.pow(x-c, 2)+Math.pow(y-d, 2)<Math.pow(r, 2)) {
					cnt++;
				}
				if(Math.pow(x-a, 2)+Math.pow(y-b, 2)<Math.pow(r, 2)&&Math.pow(x-c, 2)+Math.pow(y-d, 2)<Math.pow(r, 2)) {
					cnt--;
				}
			}
			System.out.println(cnt);
		}
	}
}
