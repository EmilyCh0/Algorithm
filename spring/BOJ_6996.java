package spring04;
import java.util.*;
public class BOJ_6996 {
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		int T=scan.nextInt();
		for(int i=0;i<T;i++) {
			String str1=scan.next();
			String str2=scan.next();
			if(str1.length()!=str2.length()) {
				System.out.println(str1+" & "+str2+" are NOT anagrams.");
				continue;
			}
			char[] char1;
			char[] char2; 
			char1=str1.toCharArray();
			char2=str2.toCharArray();
			Arrays.sort(char1);
			Arrays.sort(char2);
			boolean flag=true;
			for(int j=0;j<str1.length();j++) {
				if(char1[j]!=char2[j]) {
					System.out.println(str1+" & "+str2+" are NOT anagrams.");
					flag=false;
					break;
				}
			}
			if(flag) {
				System.out.println(str1+" & "+str2+" are anagrams.");
			}
			
		}
	}
}
/*
import java.util.*;
public class BOJ_6996 {
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		int T=scan.nextInt();
		for(int i=0;i<T;i++) {
			String str1=scan.next();
			String str2=scan.next();
			int cnt1[]=new int[26];
			int cnt2[]=new int[26];
			if(str1.length()!=str2.length()) {
				System.out.println(str1+" & "+str2+" are NOT anagrams.");
				continue;
			}
			for(int j=0;j<str1.length();j++) {
				char tmp1=str1.charAt(j);
				char tmp2=str2.charAt(j);
				cnt1[tmp1-'a']++;
				cnt2[tmp2-'a']++;
			}
			boolean flag=true;
			for(int j=0;j<26;j++) {
				if(cnt1[j]!=cnt1[j]) {
					System.out.println(str1+" & "+str2+" are NOT anagrams.");
					flag=false;
					break;
				}
			}
			if(flag) {
				System.out.println(str1+" & "+str2+" are anagrams.");
			}
			
		}
	}
}
*/