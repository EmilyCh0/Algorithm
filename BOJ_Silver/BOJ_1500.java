package baekjoon_s;
import java.util.*;
public class BOJ_1500 {
	public static void main(String args[]) {
		Scanner scan=new Scanner(System.in);
		int S=scan.nextInt();
		int K=scan.nextInt();
		long ans=1;
		int[] arr=new int[K];
		for(int i=0;i<K;i++) {
			arr[i]=S/K;
		}
		int tmp=S%K;
		for(int i=0;i<tmp;i++) {
			arr[i]++;
		}
		for(int i=0;i<K;i++) {
			ans*=arr[i];
		}
		System.out.print(ans);
	}
}
