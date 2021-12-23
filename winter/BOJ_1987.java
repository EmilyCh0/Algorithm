package week5_GraphTree;
// ¹Ì¿Ï..
import java.io.*;
import java.util.*;
public class BOJ_1987 {
	static int[][] arr;
	static int R;
	static int C;
	static int[] dr= {-1,1,0,0};
	static int[] dc= {0,0,-1,1};
	static int ans=1;
	
	public static void func(int r, int c, boolean[] isUsed, int cnt) {
		for(int i=0;i<4;i++) {
			int nextR=r+dr[i];
			int nextC=c+dc[i];
			if(nextR>=0&&nextC>=0&&nextR<R&&nextC<C) {
				if(!isUsed[arr[nextR][nextC]]) {
					isUsed[arr[nextR][nextC]]=true;
					cnt++;
					func(nextR,nextC,isUsed, cnt);
					isUsed[arr[nextR][nextC]]=false;
					cnt--;
				}
			}
			
		}
		if(cnt>ans) {
			ans=cnt;
		}
	}
	public static void main(String args[]) throws IOException {
		Scanner scan = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());	
		arr = new int[R][C];
		for(int i=0;i<R;i++) {
			String str=br.readLine();
			for(int j=0;j<C;j++) {
				arr[i][j]=str.charAt(j)-'A';
			}
		}
		boolean[] isUsed = new boolean[26];
		isUsed[arr[0][0]]=true;
		func(0,0,isUsed,1);
		System.out.print(ans);
	}
}

/*
20 20
YACDEFBXZJKVAXZXBSVA
BCDEFGHIJKLMNSVUTBSV
CDEFGHIJKLMNORTXUTBS
DEFGHIJKLMNOPQWZXUTW
AFGHIJKLMNOPQRSVZXWT
XGHIJKLMNOPQRSTBXZVU
WHIJKLMNOPQRSTUVWXZZ
HIJKLMNOPQRSTUVZXWZA
IJKLMNOPQRSTUVWXZZAB
JKLMNOPQRSTUVZXWZABC
TLMNOPQRSTUVWXWZABCD
QZNOPQRSTUVZXZZABCDE
ZRSPQRSTUVZXWZABCDEF
AVUXTSTUVZXWZABCDEFG
ZBWUAWXVWXWZABCDEFGH
ZRVWVUWAXZZABCDEFGHI
SRZVZVAXZZABCDEFGHIJ
TSRZSBUZZABCDEFGHIJK
QTSRTXZZABCDEFGHIJKL
CQTQQZZABCDEFGHIJKLM

ans=26

*/