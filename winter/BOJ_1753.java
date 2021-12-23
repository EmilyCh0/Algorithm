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
	static int[] dist;   //start ���� ������ ��� ������ ����ġ ���� 
	static PriorityQueue<Node> queue=new PriorityQueue<>(new Comparator<Node>() { //�켱���� ť
		// weight�� ������ ���� poll
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
		Arrays.fill(dist, 999999999);  //�Ʒ� di() �Լ��� �񱳹� ������ �׳� ū �� ����
		dist[start]=0;  //start ��忡�� start ������ �Ÿ� 0
		// ť�� �������� �ֱ�
		queue.add(new Node(start,0));
		for (int i=1;i<=V;i++) {
			map[i]=new ArrayList<>();  
		}
		for (int i=0;i<E;i++) {
			st = new StringTokenizer(br.readLine()," ");
			int a=Integer.parseInt(st.nextToken());  //source
			int b=Integer.parseInt(st.nextToken());  //dest
			int c=Integer.parseInt(st.nextToken());  //weight
			map[a].add(new Node(b,c));  // A ���� B�� ���ٰ�  �� �� map[A]�� (B,����ġ) ����			
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