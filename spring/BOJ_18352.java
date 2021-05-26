package spring06;
import java.util.*;
import java.io.*;

public class BOJ_18352 {
	public static class edge implements Comparable<edge>{
		int v;
		int c;
		public edge(int v, int c) {
			this.v=v;
			this.c=c;
		}
		public int compareTo(edge e) {	//오름차순 정렬
			return c-e.c;
		}
	}

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		int X = Integer.parseInt(st.nextToken());
		
		ArrayList<edge>[] list = new ArrayList[N+1];
		for(int i=1;i<N+1;i++) {
			list[i] = new ArrayList<>();
		}
		
		int[] dist = new int[N+1];
		Arrays.fill(dist, Integer.MAX_VALUE);
		dist[X]=0;
		
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			list[a].add(new edge(b,1));
		}
				
		PriorityQueue<edge> que = new PriorityQueue<>();
		que.add(new edge(X,0));
		
		while(!que.isEmpty()) {
			edge e = que.poll();
			if(dist[e.v]<e.c) {
				continue;
			}
			for(int i=0;i<list[e.v].size();i++) {
				int tmpv=list[e.v].get(i).v;
				int tmpc=list[e.v].get(i).c + e.c;
				// 최단거리 갱신
				if(dist[tmpv]>tmpc) {
					dist[tmpv]=tmpc;
					que.add(new edge(tmpv, tmpc));
				}
			}			
		}	
		int ansCnt=0;
		for(int i=1;i<N+1;i++) {
			if(dist[i]==K) {
				System.out.println(i);
				ansCnt++;
			}
		}
		if(ansCnt==0) {
			System.out.print(-1);
		}
	}
}

/*
// 메모리초과
import java.util.*;
import java.io.*;

public class BOJ_18352 {
	static boolean arr[][];
	static int ans[];
	static int K, N;
	
	public static void func(int idx, int cnt) {
		if(cnt==K) {
			return;
		}
		for(int i=1;i<N+1;i++) {
			if(arr[idx][i]==true) {
				if(ans[i]==0||(ans[i]!=0&&ans[i]>cnt)) {
					ans[i]=cnt+1;
				}
				func(i, cnt+1);
			}
		}
	}
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());	//거리
		int X = Integer.parseInt(st.nextToken());	//출발도시
		
		arr = new boolean[N+1][N+1];
		ans = new int[N+1];
		
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			arr[a][b] = true;
		}
		for(int i=1;i<N+1;i++) {
			if(arr[X][i]==true) {
				if(ans[i]==0||(ans[i]!=0&&ans[i]>1))
					ans[i]=1;		
				func(i,1);
			}
		}
	
		int ansCnt=0;
		for(int i=1;i<N+1;i++) {
			if(ans[i]==K) {
				System.out.println(i);
				ansCnt++;
			}
		}
		if(ansCnt==0) {
			System.out.print(-1);
		}

	}
}

import java.util.*;
import java.io.*;

public class BOJ_18352 {
	public static class edge implements Comparable<edge>{
		int v;
		int c;
		public edge(int v, int c) {
			this.v=v;
			this.c=c;
		}
		public int compareTo(edge e) {	//오름차순 정렬
			return c-e.c;
		}
	}

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());	//거리
		int X = Integer.parseInt(st.nextToken());	//출발도시
		
		ArrayList<edge>[] list = new ArrayList[N+1];
		for(int i=1;i<N+1;i++) {
			list[i] = new ArrayList<>();
		}
		
		int[] dist = new int[N+1];
		
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			list[a].add(new edge(b,1));
		}
		PriorityQueue<edge> que = new PriorityQueue<>();
		que.add(new edge(X,0));
		
		while(!que.isEmpty()) {
			edge e = que.poll();
			if(dist[e.v]<e.c) {
				continue;
			}
			for(int i=0;i<list[e.v].size();i++) {
				int tmpv=list[e.v].get(i).v;
				int tmpc=list[e.v].get(i).c + e.c;
				if(dist[tmpv]>tmpc) {
					dist[tmpv]=tmpc;
					que.add(new edge(tmpv, tmpc));
				}
			}
			
		}
	
		int ansCnt=0;
		for(int i=1;i<N+1;i++) {
			if(dist[i]==K) {
				System.out.println(i);
				ansCnt++;
			}
		}
		if(ansCnt==0) {
			System.out.print(-1);
		}

	}
}
 */
