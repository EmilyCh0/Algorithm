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
			// �ݴ� ��ȣ�ε� �տ� ���� ��ȣ�� ���� ��� ex. ]()
			else if(stack.isEmpty()) {
				System.out.print(0);
				return;
			}
			else if(str.charAt(i)==')') {
				// �ٷ����� '('�� ������ �� ()�϶� sum�� ���ϱ� 
				if(str.charAt(i-1)=='(') {
					sum+=tmp;
				}
				// stack.peek()==3 �̸� '['�� ������ ���� ���·� ')'�� ������ �� �̹Ƿ� 0��� ex. [)
				else if(stack.peek()!=2){
					System.out.print(0);
					return;
				}
				tmp/=2;
				// stack�� �ִ� '(' 2�� pop
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
