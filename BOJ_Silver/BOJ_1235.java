package baekjoon_s;
import java.util.*;
public class BOJ_1235 {
	public static void main(String args[]) {
		Scanner scan=new Scanner(System.in);
		StringBuilder sb=new StringBuilder();
		
		int N=scan.nextInt();
		int k=1;
		
		String[] arr=new String[N];
		
		for(int i=0;i<N;i++) {
			arr[i]=scan.next();
		}
		int len=arr[0].length();
		for(int i=len;i>0;i--) {
			sb=new StringBuilder();
			boolean check=false;
			for(int j=0;j<N;j++) {
				if(!sb.toString().contains(arr[j].subSequence(len-k, len)+"/")) {
					sb.append(arr[j].subSequence(len-k, len)+"/");
				}
				else {
					break;
				}
				if(j==N-1) {
					System.out.print(k);
					check=true;
					break;
				}
			}
			if(check)
				break;
			k++;
		}
	}
}
