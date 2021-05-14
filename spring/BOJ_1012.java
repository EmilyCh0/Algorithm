package spring05;
import java.util.*;
import java.io.*;

public class BOJ_1012 {
	static int arr[][];
	static int n,m;
	static class coor {
		int i, j;
		coor(int i, int j){
			this.i=i;
			this.j=j;
		}
	}
	public static void func(int i, int j) {
		if(i<0||j<0||i>=n||j>=m) {
			return;
		}
		if(arr[i][j]==1) {
			arr[i][j]=-1;
			func(i-1,j);
			func(i,j-1);
			func(i+1,j);
			func(i,j+1);
		}
		return;
	}
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		
		for(int t=0;t<T;t++) {
			StringTokenizer st = new StringTokenizer(br.readLine()," ");
			n=Integer.parseInt(st.nextToken());
			m=Integer.parseInt(st.nextToken());
			int num=Integer.parseInt(st.nextToken());
			int cnt=0;
			arr = new int[n][m];
			
			Stack<coor> stack = new Stack<>();
			
			for(int i=0;i<num;i++) {
				st = new StringTokenizer(br.readLine()," ");
				int tmpi=Integer.parseInt(st.nextToken());
				int tmpj=Integer.parseInt(st.nextToken());
				arr[tmpi][tmpj]=1;
				stack.push(new coor(tmpi, tmpj));
			}
		
			while(!stack.isEmpty()) {
				coor c = stack.pop();
				if(arr[c.i][c.j]==-1) {
					continue;
				}
				cnt++;
				func(c.i, c.j);
			}
			System.out.println(cnt);
		}	
	}
}
