package spring02;
import java.util.*;
public class Q2_perfectnumber {
	public static void main(String args[]) {
		//int numbers[]= {1,4,6};
		//int numbers[]= {28,496,2};
		//int numbers[]= {3,6,8128};
		int numbers[]= {7705,9,595,10000,8839};
		String ans[] = new String[numbers.length];
		for(int i=0;i<numbers.length;i++) {
			int num=numbers[i];
			int sum=1;
			int tmp=(int)Math.pow(num, 0.5);
			for(int j=2;j<=tmp;j++) {
				if(num%j==0) {
					sum+=j;
					sum+=num/j;
				}
			}
			if(tmp*tmp==num) {
				sum-=tmp;
			}
			if(sum==num) {
				ans[i]="Yes";
			}
			else {
				ans[i]="No";
			}
			// 실제 문제에서는 아래 출력부분 없이 마지막에 ans[]를 리턴
			System.out.print(ans[i]+" ");
		}
	}
}
