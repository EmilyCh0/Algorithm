package baekjoon_s;
import java.util.*;
public class BOJ_1251 {
	public static void main(String args[]) {
		Scanner scan=new Scanner(System.in);
		String str=scan.next();;
		String min=null;
		for(int i=0;i<str.length()-2;i++) {
			for(int j=i+1;j<str.length()-1;j++) {
				StringBuilder sb=new StringBuilder();
				for(int s=i;s>=0;s--) {
					sb.append(str.charAt(s));
				}
				for(int t=j;t>i;t--) {
					sb.append(str.charAt(t));
				}
				for(int r=str.length()-1;r>j;r--) {
					sb.append(str.charAt(r));
				}
				if(min==null)
					min=sb.toString();
				else if(min.compareTo(sb.toString())>0)
					min=sb.toString();
			}
		}
		System.out.print(min);
	}
}


