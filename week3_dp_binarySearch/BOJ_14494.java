package week3_dp_binarySearch;

import java.util.*;
public class BOJ_14494 {
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		int M = scan.nextInt();
		int[][] arr = new int[N][M];
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(i!=0&&j!=0) {
					long tmp = (arr[i-1][j]+arr[i][j-1])%1000000007;
					tmp = (tmp+arr[i-1][j-1])%1000000007;
					arr[i][j]=(int) tmp;
					continue;
				}
				else if(i==0&&j==0) {
					arr[i][j]=1;
					continue;
				}
				else if(i==0) {
					arr[i][j]=arr[i][j-1];
					continue;
				}
				else if(j==0) {
					arr[i][j]=arr[i-1][j];
					continue;
				}				
			}
		}
		System.out.print(arr[N-1][M-1]);
	}
}

/*
// biginteger 이용하기 -> 너무 오래걸림
import java.math.BigInteger;
import java.util.*;
public class BOJ_14494 {
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		int M = scan.nextInt();
		int[][] arr = new int[N][M];
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(i!=0&&j!=0) {
					BigInteger sum = new BigInteger(String.valueOf(arr[i-1][j]));
					BigInteger tmp = new BigInteger(String.valueOf(arr[i][j-1]));
					sum = sum.add(tmp);
					tmp = new BigInteger(String.valueOf(arr[i-1][j-1]));
					sum = sum.add(tmp);
					tmp = new BigInteger("1000000007");
					sum = sum.remainder(tmp);
					arr[i][j]=sum.intValue();
					continue;
				}
				else if(i==0&&j==0) {
					arr[i][j]=1;
					continue;
				}
				else if(i==0) {
					arr[i][j]=arr[i][j-1];
					continue;
				}
				else if(j==0) {
					arr[i][j]=arr[i-1][j];
					continue;
				}				
			}
		}
		System.out.print(arr[N-1][M-1]);
	}
}
*/