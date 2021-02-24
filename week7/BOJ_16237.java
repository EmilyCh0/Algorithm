package week7;
import java.util.*;
public class BOJ_16237 {
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		int cnt=0;
		int A = scan.nextInt();
		int B = scan.nextInt();
		int C = scan.nextInt();
		int D = scan.nextInt();
		int E = scan.nextInt();
		cnt+=E;
		if(A>D) {
			cnt+=D;
			A-=D;
			if(B>C) {
				cnt+=C;
				B-=C;
				// A,B 만 남음
				int sum=0;
				while(A>0||B>0) {
					if(B>0&&sum<=3) {
						sum+=2;
						B--;
					}
					else if(A>0&&sum<=4){
						sum+=1;
						A--;
					}
					if((A!=0&&sum<=4)||(B!=0&&sum<=3)) {
						continue;
					}
					else {
						cnt++;
						sum=0;
					}
				}
			}
			else {
				cnt+=B;
				C-=B;
				//A,C 남음
				int sum=0;
				while(A>0||C>0) {
					if(C>0&&sum<=2) {
						sum+=3;
						C--;
					}
					else if(A>0&&sum<=4){
						sum+=1;
						A--;
					}
					if((A!=0&&sum<=4)||(C!=0&&sum<=2)) {
						continue;
					}
					else {
						cnt++;
						sum=0;
					}
				}
			}
		}
		else {
			cnt+=A;
			D-=A;
			// BCD
			if(B>C) {
				cnt+=C;
				B-=C;
				// BD 만 남음
				int sum=0;
				while(D>0||B>0) {
					if(D>0&&sum<=1) {
						sum+=4;
						D--;
					}
					else if(B>0&&sum<=3){
						sum+=2;
						B--;
					}
					if((B!=0&&sum<=3)||(D!=0&&sum<=1)) {
						continue;
					}
					else {
						cnt++;
						sum=0;
					}
				}
			}
			else {
				cnt+=B;
				C-=B;
				//CD 남음
				int sum=0;
				while(D>0||C>0) {
					if(D>0&&sum<=1) {
						sum+=4;
						D--;
					}
					else if(C>0&&sum<=2){
						sum+=3;
						C--;
					}
					if((C!=0&&sum<=2)||(D!=0&&sum<=1)) {
						continue;
					}
					else {
						cnt++;
						sum=0;
					}
				}
			}
		}
		System.out.print(cnt);
	}
}
