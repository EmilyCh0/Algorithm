package spring04;
import java.util.*;
public class BOJ_16401_ {
	static int arr[];
	static int N;
	static int M;
	static int max=0;
	static void binary(int s, int e) {
		int mid=(s+e)/2;
		if(s>=e) {
			return;
		}
		int cnt=0;
		for(int i=N-1;i>=0;i--) {
			cnt+=arr[i]/mid;
			if(cnt>=M) {
				break;
			}
			else if(arr[i]<mid) {
				break;
			}
		}
		if(cnt>=M) {
			if(mid>max) {
				max=mid;
			}
			binary(mid+1,e);
		}
		else {
			binary(s,mid);
		}
	}
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		M = scan.nextInt();
		N= scan.nextInt();
		arr=new int[N];
		for(int i=0;i<N;i++) {
			arr[i]=scan.nextInt();
		}
		Arrays.sort(arr);
		binary(1, arr[N-1]);
		System.out.print(max);
	}
}
