package baekjoon_s;
import java.util.*;
public class BOJ_11653 {
	public static void main(String args[]) {
		Scanner scan=new Scanner(System.in);
		int N=scan.nextInt();
		while(N>1) {
			int i=2;
			while(true) {
				if(N%i==0) {
					System.out.println(i);
					N/=i;
					break;
				}
				else {
					i++;
				}
			}
		}
		scan.close();
	}
}
