package baekjoon_s;
import java.util.*;
public class BOJ_1002 {
	static double dist(int a,int b,int c,int d) {
		return (Math.pow(a-c, 2)+Math.pow(b-d, 2));
	}
	public static void main(String args[]) {
		Scanner scan=new Scanner(System.in);
		int N=scan.nextInt();
		for(int i=0;i<N;i++) {
			int a=scan.nextInt();
			int b=scan.nextInt();
			int r1=scan.nextInt();
			int c=scan.nextInt();
			int d=scan.nextInt();
			int r2=scan.nextInt();
			if(a==c&&b==d) {
				if(r1==r2) {
					System.out.println(-1);
				}
				else {
					System.out.println(0);
				}
			}
			else if(dist(a,b,c,d)>Math.pow(r1+r2, 2)||dist(a,b,c,d)<Math.pow(r1-r2, 2)) {
				System.out.println(0);
			}
			else if(dist(a,b,c,d)==Math.pow(r1+r2, 2)||Math.pow(r1-r2, 2)==dist(a,b,c,d)) {
				System.out.println(1);
			}
			else {
				System.out.println(2);
			}
			
		}
	}
}



/*

import java.util.*;
public class BOJ_1002 {
	static int dist(int a,int b,int c,int d) {
		return (int) (Math.pow(a-c, 2)+Math.pow(b-d, 2));
	}
	public static void main(String args[]) {
		Scanner scan=new Scanner(System.in);
		int N=scan.nextInt();
		for(int i=0;i<N;i++) {
			int a=scan.nextInt();
			int b=scan.nextInt();
			int r1=scan.nextInt();
			int c=scan.nextInt();
			int d=scan.nextInt();
			int r2=scan.nextInt();
			int cnt=0;
			if(r1==r2) {
				cnt=-1;
			}
			else if(r1<r2) {
				for(int x=a-r1;x<=a+r1;x++) {
					for(int y=b-r1;y<=b+r1;y++) {
						if(dist(a,b,x,y)==(int)Math.pow(r1, 2)&&dist(c,d,x,y)==(int)Math.pow(r2, 2)) {
							cnt++;
						}
					}
				}
			}
			else if(r1>r2){
				for(int x=c-r2;x<=c+r2;x++) {
					for(int y=d-r2;y<=d+r2;y++) {
						if(dist(c,d,x,y)==(int)Math.pow(r2, 2)&&dist(a,b,x,y)==(int)Math.pow(r1, 2)) {
							cnt++;
						}
					}
				}
			}
			System.out.println(cnt);
		}
	}
}

*/