package week1_greedy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class BOJ_1080 {
	static int[][] arrA;	// A행렬
	static int[][] arrB;	// B행렬
	static int cnt;		//최종 출력 값
	
	public static void func(int r, int c) {	// (r,c) 기준으로 3x3 뒤집기 
		if(arrA[r][c]!=arrB[r][c]) {	// (r,c)가 다를때만 뒤집기
			for(int i=r;i<r+3;i++) {
				for(int j=c;j<c+3;j++) {
					arrA[i][j]=arrA[i][j]==0?1:0;		// 0이면 1로, 아니면 0으로
				}
			}
			cnt++;	// 뒤집은 횟수 +1
		}
		else return;
	}
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
			
		arrA=new int[N][M];
		arrB=new int[N][M];
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				arrA[i][j]=br.read()-'0';	
			}
			br.readLine();
		}
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				arrB[i][j]=br.read()-'0';
			}
			br.readLine();
		}
		cnt=0;
		for(int i=0;i<N-2;i++) {
			for(int j=0;j<M-2;j++) {
				func(i,j);
			}
		}
		boolean check=true;		// A,B가 똑같은지 확인
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(arrA[i][j]!=arrB[i][j]) {
					check=false;
					break;
				}
			}
		}
		if(check) {
			System.out.print(cnt);
		}
		else {
			System.out.print(-1);
		}
		
	}
}
