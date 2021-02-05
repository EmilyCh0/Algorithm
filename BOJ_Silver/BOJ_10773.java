package baekjoon_s;
import java.util.*;
public class BOJ_10773 {
	public static void main(String args[]) {
		Scanner scan=new Scanner(System.in);
		Stack<Integer> stack=new Stack<Integer>();
		int N=scan.nextInt();
		int tmp;
		int total=0;
		for(int i=0;i<N;i++) {
			tmp=scan.nextInt();
			if(tmp==0) {
				total-=stack.pop();
			}
			else {
				stack.push(tmp);
				total+=tmp;
			}
		}
		System.out.print(total);
	}
}
