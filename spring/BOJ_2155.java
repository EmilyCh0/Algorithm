
package spring06;

import java.util.*;
public class BOJ_2155 {
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		int a = scan.nextInt();
		int b = scan.nextInt();
		int idx=1;	// 1 3 5 7 9 tmp의 간격
		int tmp=1;	// 1 2 5 10 17
		int cnta=0; // 대각선 개수
		int cntb=0;
		int x_a=0;	
		int y_a=0;
		int x_b=0;
		int y_b=0;
		boolean right=true;
		int ans=0;
		
		while(true) {
			if(a>=tmp&&a<=tmp+x_a) {
				break;
			}
			tmp+=idx;
			idx+=2;
			x_a+=2;
			y_a--;
			cnta++;
		}		
		while(tmp!=a) {
			if(right) {
				tmp++;
				x_a--;
				y_a++;
				right=false;
			}
			else {
				tmp++;
				x_a++;
				y_a++;
				right=true;
			}
		}
		if(!right) {
			cnta--;
		}
		idx=1;
		tmp=1;
		right=true;		
		while(true) {
			if(b>=tmp&&b<=tmp+x_b) {
				break;
			}
			tmp+=idx;
			idx+=2;
			x_b+=2;
			y_b--;
			cntb++;
		}
		while(tmp!=b) {
			if(right) {
				tmp++;
				x_b--;
				y_b++;
				right=false;
			}
			else {
				tmp++;
				x_b++;
				y_b++;
				right=true;
			}
		}
		if(!right) {
			cntb--;
		}
		/* 예시 
		2 에서 14
		2  --> (x,y)=(2,-1), cnt=1
		14 --> (x,y)=(6,1), cnt=3
		ans = x차이+y차이-cnt차이 = 4+2-2 = 4
		3 에서 12
		3  --> (x,y)=(1,0), cnt=0
		12 --> (x,y)=(6,1), cnt=3
		ans = 5+1-3 = 3 (틀림! 정답은 5)
		cnt차이 > y차이일 때 문제 발생!
		이 경우 상쇄되는 대각선을 별도로 계산 (상쇄되는대각선 = 올라갔다 내려오는 경우)
		*/
		int diffx=Math.abs(x_a-x_b);
		int diffy=Math.abs(y_a-y_b);
		int diffcnt = Math.abs(cnta-cntb);
		
		int tmpcnt = diffcnt<=diffy?0:(diffcnt-diffy)/2;
	
		ans=diffx+diffy-diffcnt+tmpcnt*2;
		System.out.print(ans);
	}
}
