package week2_backtracking;

import java.io.*;
import java.util.*;
public class BOJ_2580 {
	static int[][] arr = new int[9][9];
	static boolean[][] row = new boolean[9][9];
	static boolean[][] col = new boolean[9][9];
	static boolean[][] squ = new boolean[9][9];
	static int cnt=0;
	static int[] emptyR = new int[82];
	static int[] emptyC = new int[82];
	static boolean check;
	
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	static void backtrack(int k) throws IOException {
		if(k==cnt) {
			for(int i=0;i<cnt;i++) {
				if(arr[emptyR[i]][emptyC[i]]==0) {
					return;
				}
			}
			if(check) {
				for(int i=0;i<9;i++) {
					for(int j=0;j<9;j++) {
						bw.write(arr[i][j]+" ");
					}
					bw.newLine();
				}
				check=false;
				return;
			}
		}
		else {
			int r=emptyR[k];
			int c=emptyC[k];
			if(check) {
				for(int i=0;i<9;i++) {
					if(row[r][i]==false&&col[c][i]==false&&squ[(r/3)*3+c/3][i]==false) {	// 가로, 세로, 사각형 모두 i를 사용 안했으면
						// 사용했다고 표시
						row[r][i]=true;
						col[c][i]=true;
						squ[(r/3)*3+c/3][i]=true;
						arr[r][c]=i+1;
						backtrack(k+1);
						// 사용안한 경우로 다시 올라가기
						row[r][i]=false;
						col[c][i]=false;
						squ[(r/3)*3+c/3][i]=false;
						arr[r][c]=0;
					}
				}
			}
		}
	}
	
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		for(int i=0;i<9;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine()," ");
			for(int j=0;j<9;j++) {
				arr[i][j]=Integer.parseInt(st.nextToken());
				if(arr[i][j]==0) {
					emptyR[cnt]=i;
					emptyC[cnt]=j;
					cnt++;
					continue;
				}
				else {
					row[i][arr[i][j]-1]=true;
					col[j][arr[i][j]-1]=true;
					squ[(i/3)*3+j/3][arr[i][j]-1]=true;
				}
			}
		}
		check=true;
		backtrack(0);
		bw.flush();
		
	}
}

/*
package week2_backtracking;

import java.io.*;
import java.util.*;
public class BOJ_2580 {
	static int[][] arr = new int[9][9];
	static class Node {
		int i,j;
		Node(int i,int j) {
			this.i=i;
			this.j=j;
		}
	}
	static ArrayList<Node> list = new ArrayList<Node>();
	
	static void checkR(int i) {
		
	}
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		for(int i=0;i<9;i++) {
			for(int j=0;j<9;j++) {
				arr[i][j]=Integer.parseInt(st.nextToken());
				if(arr[i][j]==0) {
					list.add(new Node(i,j));
				}
			}
			st = new StringTokenizer(br.readLine()," ");
		}
		
		
	}
}
*/
