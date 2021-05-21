package baekjoon_s;
import java.util.*;
public class BOJ_1476 {
	public static void main(String args[]) {
		Scanner scan=new Scanner(System.in);
		int E=scan.nextInt();
		int S=scan.nextInt();
		int M=scan.nextInt();
		int ans=1;
		int e=1;
		int s=1;
		int m=1;
		while(true) {
			if(e==E&&s==S&&m==M)
				break;
			e++;
			s++;
			m++;
			ans++;
			if(e==16)
				e=1;
			if(s==29)
				s=1;
			if(m==20)
				m=1;
		}
		System.out.print(ans);
	}
}
