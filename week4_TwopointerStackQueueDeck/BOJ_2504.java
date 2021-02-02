package week4_TwopointerStackQueueDeck;

import java.util.*;
import java.io.*;
public class BOJ_2504 {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		Stack<Integer> stack = new Stack<>();		
		int sum = 0;
		int tmp = 1;
		boolean flag=true;
		for(int i=0;i<str.length();i++) {
			if(str.charAt(i)=='(') {
				tmp*=2;
				stack.push(2);
			}
			else if(str.charAt(i)=='[') {
				tmp*=3;
				stack.push(3);
			}
			// 닫는 괄호인데 앞에 여는 괄호가 없는 경우 ex. ]()
			else if(stack.isEmpty()) {
				System.out.print(0);
				return;
			}
			else if(str.charAt(i)==')') {
				// 바로전에 '('가 있으면 즉 ()일때 sum에 더하기 
				if(str.charAt(i-1)=='(') {
					sum+=tmp;
				}
				// stack.peek()==3 이면 '['가 닫히지 않은 상태로 ')'가 등장한 것 이므로 0출력 ex. [)
				else if(stack.peek()!=2){
					System.out.print(0);
					return;
				}
				tmp/=2;
				// stack에 있던 '(' 2를 pop
				stack.pop();
			}
			else if(str.charAt(i)==']') {
				if(str.charAt(i-1)=='[') {
					sum+=tmp;
				}
				else if(stack.peek()!=3){
					System.out.print(0);
					return;
				}
				tmp/=3;
				stack.pop();
			}
		}
		if(!stack.isEmpty()||!flag) {
			System.out.print(0);
		}
		else if(flag) {
			System.out.print(sum);
		}		
	}
}
