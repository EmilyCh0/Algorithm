package baekjoon_s;
import java.util.*;

public class BOJ_2447 {
	public static void main(String args[]) {
		Scanner scan=new Scanner(System.in);
		int N=scan.nextInt();
		StringBuilder sb=new StringBuilder();
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				int a=i;int b=j;
				while(true) {
					if(a==0) break;
					if(a%3==1&&b%3==1) {
						sb.append(" ");
						break;
					}
					a/=3;
					b/=3;
				}
				if(a%3==1&&b%3==1) {
					
				}
				else {
					sb.append("*");
				}
			}
			sb.append("\n");
		}
		System.out.print(sb.toString());
		scan.close();
	}
}
