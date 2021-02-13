package baekjoon_s;
import java.util.*;
public class BOJ_1198 {
	public static void main(String args[]) {
		Scanner scan=new Scanner(System.in);
		int N=scan.nextInt();
		int[][] arr=new int[N][2];
		double ans=0;
		for(int i=0;i<N;i++) {
			arr[i][0]=scan.nextInt();
			arr[i][1]=scan.nextInt();
		}
		for(int i=0;i<N-2;i++) {
			for(int j=i+1;j<N-1;j++) {
				for(int k=j+1;k<N;k++) {
					int a=arr[i][0];
					int b=arr[i][1];
					int c=arr[j][0];
					int d=arr[j][1];
					int e=arr[k][0];
					int f=arr[k][1];
					double area=((e-a)*(d-b)-(c-a)*(f-b))/2.0;
					if(ans<area) {
						ans=area;
					}
				}
			}
		}
		System.out.print(ans);
	}
}
