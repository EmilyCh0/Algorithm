
package baekjoon_s;
import java.util.*;
public class BOJ_1158 {
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		StringBuilder sb=new StringBuilder("<");
		int N=scan.nextInt();
		int cnt=scan.nextInt();
		int idx=cnt-1;
		int[] arr=new int[N];
		for(int i=0;i<N;i++) {
			arr[i]=i+1;
		}
		sb.append(arr[idx]+", ");
		arr[idx]=0;
		for(int i=1;i<N;i++) {
			int tmp=cnt;
			while(tmp>0) {
				if(arr[idx]==0) {
					idx=(idx+1)%N;
				}
				else {
					tmp--;
					if(tmp==0&&arr[idx]!=0) {
						sb.append(arr[idx]+", ");
						arr[idx]=0;
						break;
					}
					else if(tmp==0&&arr[idx]==0) {
						tmp++;
					}
					idx=(idx+1)%N;
				}
			}
			
		}
		sb.replace(sb.length()-2, sb.length(), ">");
		System.out.print(sb.toString());
	}
}
