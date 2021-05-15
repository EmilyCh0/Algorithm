package baekjoon_s;
import java.util.*;
public class BOJ_1439 {
	public static void main(String args[]) {
		Scanner scan=new Scanner(System.in);
		String tmp=scan.next();
		String str=tmp;
		int cnt=0;
		int cnt2=0;
		if(str.charAt(0)=='1') {
			cnt++;
		}
		for(int i=1;i<str.length();i++) {
			if(str.charAt(i)=='1'&&str.charAt(i-1)=='0') {
				cnt++;
			}
			else
				continue;
		}
		str=tmp;
		if(str.charAt(0)=='0') {
			cnt2++;
		}
		for(int i=1;i<str.length();i++) {
			if(str.charAt(i)=='0'&&str.charAt(i-1)=='1') {
				cnt2++;
			}
			else
				continue;
		}
		System.out.print(Math.min(cnt, cnt2));
	}
}
