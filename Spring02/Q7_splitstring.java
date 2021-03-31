package spring02;
import java.util.*;
import java.io.*;
public class Q7_splitstring {
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		String str=scan.next();
		String arr[]=new String[str.length()];
		int idx=0;
		char ch=str.charAt(0);
		int len=str.length();
		int s=0,e=0;
		for(int i=1;i<len;i++) {
			if(i<s) {
				continue;
			}
			if(str.charAt(i)==ch) {
				int tmp=i;
				e=i-1;
				while(str.charAt(tmp)==ch) {
					tmp++;
					if(tmp==len)
						break;
				}
				arr[idx]=str.substring(s, e);
				idx++;
				s=tmp;
			}
			else {
				ch=str.charAt(i);
			}
			
		}
		if(str.charAt(len-1)==str.charAt(len-2)) {
			arr[idx]="";
			idx++;
		}
		else {
			arr[idx]=str.substring(s,len);
			idx++;
		}
		String[] ans=new String[idx];
		for(int i=0;i<idx;i++) {
			ans[i]=arr[i];
			// 실제 문제에서는 아래 출력부분 없이 마지막에 ans[]를 리턴
			System.out.print("\""+ans[i]+"\" ");
		}
	}
}
