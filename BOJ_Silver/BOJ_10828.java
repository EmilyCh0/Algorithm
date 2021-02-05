package baekjoon_s;
import java.util.*;
public class BOJ_10828 {
	public static void main(String args[]) {
		Scanner scan=new Scanner(System.in);
		int N=scan.nextInt();
		Stack<Integer> stack=new Stack<Integer>();
		for(int i=0;i<N;i++) {
			String str=scan.next();
			int tmp;
			switch(str) {
			case "push":
				tmp=scan.nextInt();
				stack.push(tmp);
				break;
			case "pop":
				if(stack.isEmpty())
					System.out.println(-1);
				else
					System.out.println(stack.pop());
				break;
			case "size":
				System.out.println(stack.size());
				break;
			case "empty":
				if(stack.isEmpty())
					System.out.println(1);
				else
					System.out.println(0);
				break;
			case "top":
				if(stack.isEmpty())
					System.out.println(-1);
				else
					System.out.println(stack.peek());
				break;
			}
		}
	}
}
