package week7;
import java.util.*;
public class BOJ_18766 {
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		for(int i=0;i<T;i++) {
			int N = scan.nextInt();
			String[] str1 = new String[N];
			String[] str2 = new String[N];
			for(int j=0;j<N;j++) {
				str1[j]=scan.next();
			}
			for(int j=0;j<N;j++) {
				str2[j]=scan.next();
			}
			Arrays.sort(str1);
			Arrays.sort(str2);
			boolean flag=true;
			for(int j=0;j<N;j++) {
				if(!str1[j].contentEquals(str2[j])) {
					flag=false;
					break;
				}
			}
			if(flag) {
				System.out.println("NOT CHEATER");
			}
			else {
				System.out.println("CHEATER");
			}
		}
	
	}
}
