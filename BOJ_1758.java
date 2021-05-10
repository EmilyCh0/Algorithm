package spring03;
import java.util.*;
public class BOJ_1758 {
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		int N= scan.nextInt();
		int arr[]= new int[N];
		for(int i=0;i<N;i++) {
			arr[i]=scan.nextInt();
		}
		Arrays.sort(arr);
		long ans=0;
		for(int i=0;i<N;i++) {
			int tmp=N-i-1;
			if(arr[tmp]-i>0) {
				ans+=(arr[tmp]-i);
			}
		}
		System.out.print(ans);
	}
}
