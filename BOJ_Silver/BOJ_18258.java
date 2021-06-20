package baekjoon_s;
import java.util.*;
import java.io.*;
public class BOJ_18258 {
	public static void main(String args[]) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int N=Integer.parseInt(br.readLine());
		int[] arr=new int[N];
		int rear=0;
		int front=0;
		for(int i=0;i<N;i++) {
			String[] st=br.readLine().split(" ");
			String str=st[0];
			if(str.contentEquals("push")) {
				arr[rear]=Integer.parseInt(st[1]);
				rear++;
			}
			else if(str.contentEquals("pop")) {
				if(rear<=front)
					System.out.println(-1);
				else {
					System.out.println(arr[front]);
					front++;
				}
			}
			else if(str.contentEquals("size")) {
				System.out.println(rear-front);
			}
			else if(str.contentEquals("empty")) {
				if(rear<=front)
					System.out.println(1);
				else
					System.out.println(0);
			}
			else if(str.contentEquals("front")) {
				if(rear<=front)
					System.out.println(-1);
				else
					System.out.println(arr[front]);
			}
			else if(str.contentEquals("back")) {
				if(rear<=front)
					System.out.println(-1);
				else {
					System.out.println(arr[rear-1]);
				}
			}
		}
	}
}

/*
package baekjoon_s;
import java.util.*;
public class BOJ_18258 {
	public static void main(String args[]) {
		Scanner scan=new Scanner(System.in);
		Queue<Integer> q=new LinkedList<Integer>();
		int N=scan.nextInt();
		int[] arr=new int[N];
		int idx=-1;
		for(int i=0;i<N;i++) {
			String str=scan.next();
			if(str.contentEquals("push")) {
				int tmp=scan.nextInt();
				q.add(tmp);
				idx++;
				arr[idx]=tmp;
			}
			else if(str.contentEquals("pop")) {
				if(q.isEmpty())
					System.out.println(-1);
				else {
					System.out.println(q.poll());
					idx--;
				}
			}
			else if(str.contentEquals("size")) {
				System.out.println(q.size());
			}
			else if(str.contentEquals("empty")) {
				if(q.isEmpty())
					System.out.println(1);
				else
					System.out.println(0);
			}
			else if(str.contentEquals("front")) {
				if(q.isEmpty())
					System.out.println(-1);
				else
					System.out.println(q.peek());
			}
			else if(str.contentEquals("back")) {
				if(q.isEmpty())
					System.out.println(-1);
				else {
					System.out.println(arr[idx]);
				}
			}
		}
	}
}
*/