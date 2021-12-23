package week4_TwopointerStackQueueDeck;
import java.util.*;
public class BOJ_10025 {
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		int K = scan.nextInt();
		int[] arr = new int[1000001];
		int start = 1000001;
		int end = 0;
		for(int i=0;i<N;i++) {
			int ice = scan.nextInt();
			int idx = scan.nextInt();
			if(idx<start)
				start = idx;
			if(idx>end)
				end = idx;
			arr[idx]=ice;
		}
		long ans=0;
		for(int i=start;i<=start+2*K;i++) {
			if(i>1000000)
				break;
			ans+=arr[i];
		}
		long tmp = ans;
		for(int i=start; i<=end;i++) {
			tmp-=arr[i];
			if(i+2*K+1>1000000)
				break;
			tmp+=arr[i+2*K+1];
			ans=Math.max(tmp, ans);
		}
		System.out.print(ans);
	}
}
