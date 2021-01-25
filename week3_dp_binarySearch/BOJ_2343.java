package week3_dp_binarySearch;

import java.util.*;
public class BOJ_2343 {
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		int M = scan.nextInt();
		int arr[] = new int[N];
		int start=0;
		int end=0;
		int ans=0;
		for(int i=0;i<N;i++) {
			arr[i]=scan.nextInt();
			end+=arr[i];	
			if(start<arr[i])
				start=arr[i];
		}
		// start´Â °¡Àå ±ä ·¹½¼
		// end´Â ·¹½¼ ±æÀÌ ÃÑ ÇÕ
		int mid = (start+end)/2;
		while(start<=end) {
			mid=(start+end)/2;
			int sum=0;
			int cnt=1;
			for(int i=0;i<N;i++) {
				sum+=arr[i];
				if(sum>mid) {
					sum=arr[i];
					cnt++;
				}
			}
			if(cnt<=M) {
				ans=mid;
				end=mid-1;
			}
			else {
				start=mid+1;
			}
		}
		System.out.print(ans);
	}
}
