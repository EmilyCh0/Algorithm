package spring04;

// boj 18870 !!!

import java.io.*;
import java.util.*;
public class BOJ_16401 {
	static ArrayList<Integer> arr = new ArrayList<>();
	static StringBuilder sb = new StringBuilder();
	static void search(int s, int e, int k) {
		int mid=(s+e)/2;
		if(arr.get(mid)==k) {
			sb.append(mid+" ");
			return;
		}
		if(mid<0||mid>arr.size()||s==e) {
			return;
		}
		else if(arr.get(mid)<k) {
			search(mid+1,e,k);
		}
		else {
			search(s,mid,k);
		}
	}
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		st=new StringTokenizer(br.readLine());
		int[] num = new int[N];
		HashSet<Integer> hs = new HashSet<Integer>();
		for(int i=0;i<N;i++) {
			int t=Integer.parseInt(st.nextToken());
			num[i]=t;
			hs.add(t);
		}
		arr.addAll(hs);
		Collections.sort(arr);
		
		for(int i=0;i<N;i++) {
			search(0,arr.size()-1,num[i]);
		}
		System.out.print(sb.toString());
	}
}


