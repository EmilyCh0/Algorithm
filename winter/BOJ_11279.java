package week6;

import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;

public class BOJ_11279 {

	public static void main(String args[]) {
		Scanner scan=new Scanner(System.in);	
		int N = scan.nextInt();
		PriorityQueue<Integer> queue = new PriorityQueue<Integer>(Collections.reverseOrder());
		for(int i=0;i<N;i++) {
			int val = scan.nextInt();
			if(val==0) {
				if(queue.isEmpty()) {
					System.out.println("0");
				}
				else {
					System.out.println(queue.poll());
				}
			}
			else {
				queue.add(val);
			}
		}
	}
}
