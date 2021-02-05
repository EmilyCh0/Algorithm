package baekjoon_s;
import java.util.*;
public class BOJ_1138 {
	public static void main(String args[]) {
		Scanner scan=new Scanner(System.in);
		int N=scan.nextInt();
		StringBuilder sb=new StringBuilder();
		int[] arr=new int[N];
		for(int i=0;i<N;i++) {
			arr[i]=scan.nextInt();
		}
		sb.append(N+" ");
		for(int i=N-1;i>0;i--) {
			int cnt=arr[i-1];
			int idx=0;
			for(int j=0;j<sb.length();j++) {
				if(cnt==0) break;
				if(sb.toString().charAt(j)!=' ') {
					idx++;
				}
				else {
					cnt--;
					idx++;
				}
			}
			sb.insert(idx,i+" ");
		}
		sb.deleteCharAt(sb.length()-1);
		System.out.print(sb.toString());
	}
}	




/*
package baekjoon_s;
import java.util.*;
public class BOJ_1138 {
	public static void main(String args[]) {
		Scanner scan=new Scanner(System.in);
		int N=scan.nextInt();
		StringBuilder sb=new StringBuilder();
		int[] arr=new int[N];
		for(int i=0;i<N;i++) {
			arr[i]=scan.nextInt();
		}
		sb.append(N+" ");
		for(int i=N-1;i>0;i--) {
			int cnt=arr[i-1];
			int idx=0;
			while(cnt>0) {
				idx++;
				cnt--;
			}
			sb.insert(idx*2,i+" ");
		}
		sb.deleteCharAt(sb.length()-1);
		System.out.print(sb.toString());
	}
}
*/