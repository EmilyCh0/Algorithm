package week6;

import java.util.*;
import java.io.*;

public class BOJ_1753 {
	static class Node{
		int dest, weight;
		Node(int dest, int weight){
			this.dest=dest;
			this.weight=weight;
		}
	}
	static void di() {
		while(!queue.isEmpty()) {
			Node now=queue.poll();
			for(Node next:map[now.dest]) {
				if(dist[next.dest]>dist[now.dest]+next.weight) {
					dist[next.dest]=dist[now.dest]+next.weight;
					queue.add(new Node(next.dest,dist[next.dest]));
				}
			}
		}
	}
	static int V,E,start;
	static ArrayList<Node>[] map;
	static int[] dist;   //start 부터 나머지 노드 까지의 가중치 저장 
	static PriorityQueue<Node> queue=new PriorityQueue<>(new Comparator<Node>() { //우선순위 큐
		// weight가 작은것 부터 poll
		@Override
		public int compare(Node node1,Node node2) {
			return node1.weight-node2.weight;
		}
	});
	
	@SuppressWarnings("unchecked")
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		V=Integer.parseInt(st.nextToken());
		E=Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		start=Integer.parseInt(st.nextToken());
		map=new ArrayList[V+1];
		dist=new int[V+1];
		Arrays.fill(dist, 999999999);  //아래 di() 함수의 비교문 때문에 그냥 큰 수 넣음
		dist[start]=0;  //start 노드에서 start 까지는 거리 0
		// 큐에 시작지점 넣기
		queue.add(new Node(start,0));
		for (int i=1;i<=V;i++) {
			map[i]=new ArrayList<>();  
		}
		for (int i=0;i<E;i++) {
			st = new StringTokenizer(br.readLine()," ");
			int a=Integer.parseInt(st.nextToken());  //source
			int b=Integer.parseInt(st.nextToken());  //dest
			int c=Integer.parseInt(st.nextToken());  //weight
			map[a].add(new Node(b,c));  // A 에서 B로 간다고  할 때 map[A]에 (B,가중치) 저장			
		}
		di();
		for(int i=1;i<=V;i++) {
			if(dist[i]==999999999) {
				System.out.println("INF");
			}
			else {
				System.out.println(dist[i]);
			}
		}
	}
}