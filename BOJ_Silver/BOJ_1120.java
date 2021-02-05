package baekjoon_s;
import java.util.*;
public class BOJ_1120 {
	static int count(String a,String b) {
		int cnt=0;
		for(int i=0;i<a.length();i++) {
			if(a.charAt(i)!=b.charAt(i)) {
				cnt++;
			}
		}
		return cnt;
	}
	public static void main(String args[]) {
		Scanner scan=new Scanner(System.in);
		String lg=scan.next();
		String st=scan.next();
		if(lg.length()<st.length()) {
			String tmp=st;
			st=lg;
			lg=tmp;
		}
		
		int ans=lg.length();
		for(int i=0;i<lg.length()-st.length()+1;i++) {
			int j=i+st.length();
			String tmp=null;
			if(i==0) {
				tmp=st+lg.substring(j);
			}
			else if(i>=1&&j<lg.length()) {
				tmp=lg.substring(0, i)+st+lg.substring(j, lg.length());
			}
			else if(j==lg.length()) {
				tmp=lg.substring(0, i)+st;
			}
			if(count(tmp,lg)<ans)
				ans=count(tmp,lg);
		}
		System.out.print(ans);
	}
}
