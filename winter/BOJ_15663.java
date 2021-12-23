package week2_backtracking;

import java.io.*;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;
public class BOJ_15663 {
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static HashMap<String,Integer> map = new HashMap();
	static int[] arr = new int[10];
	static int[] num;
	static boolean[] isUsed;
	static int N;
	static int M;
	
	static void backtrack(int k) throws IOException {
		if(k==M) {
			String tmp="";
			for(int i=0;i<M;i++) {
				tmp+=(arr[i]+" ");
			}
			if(map.get(tmp)==null) {
				map.put(tmp, 1);
				bw.write(tmp);
				bw.newLine();
			}
		}
		else {
			for(int j=0;j<N;j++) {
				if(!isUsed[j]) {
					arr[k]=num[j];
					isUsed[j]=true;
					backtrack(k+1);
					isUsed[j]=false;
				}
				
			}
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine()," ");
		num = new int[N];
		for(int i=0;i<N;i++) {
			num[i]=Integer.parseInt(st.nextToken());
		}
		Arrays.sort(num);
		isUsed = new boolean[N];
		backtrack(0);
		bw.flush();
	}
}


/*
package week2_backtracking;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;
public class BOJ_15663 {
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static int[] arr = new int[10];
	static int[] num;
	static boolean[] isUsed;
	static int N;
	static int M;
	static String before = "";
	static String after = "";
	static void backtrack(int k) throws IOException {
		if(k==M) {
			for(int i=0;i<M;i++) {
				bw.write(arr[i]+" ");
			}
			bw.newLine();
		}
		else {
			for(int j=0;j<N;j++) {
				if(!isUsed[j]) {
					arr[k]=num[j];
					isUsed[j]=true;
					backtrack(k+1);
					isUsed[j]=false;
				}
				
			}
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine()," ");
		num = new int[N];
		for(int i=0;i<N;i++) {
			num[i]=Integer.parseInt(st.nextToken());
		}
		Arrays.sort(num);
		isUsed = new boolean[N];
		backtrack(0);
		bw.flush();
	}
}

package week2_backtracking;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;
public class BOJ_15663 {
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static int[] arr = new int[10];
	static int[] num;
	static boolean[] isUsed;
	static int N;
	static int M;
	static String before = "";
	static String after = "";
	static void backtrack(int k) throws IOException {
		if(k==M) {
			after="";
			for(int i=0;i<M;i++) {
				after+=(arr[i]+" ");
			}
			if(!before.contentEquals(after)) {
				bw.write(after);
				before=after;
				bw.newLine();
			}
		}
		else {
			for(int j=0;j<N;j++) {
				if(!isUsed[j]) {
					arr[k]=num[j];
					isUsed[j]=true;
					backtrack(k+1);
					isUsed[j]=false;
				}
				
			}
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine()," ");
		num = new int[N];
		for(int i=0;i<N;i++) {
			num[i]=Integer.parseInt(st.nextToken());
		}
		Arrays.sort(num);
		isUsed = new boolean[N];
		backtrack(0);
		bw.flush();
	}
}

*/
