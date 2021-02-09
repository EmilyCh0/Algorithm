package baekjoon_s;
import java.util.*;
public class BOJ_1145 {
	static int GCD(int a,int b) {
		int i=1;
		int ans=1;
		while(i<=b) {
			if(a%i==0&&b%i==0)
				ans=i;
			i++;
		}
		return ans;
	}
	public static void main(String args[]) {
		Scanner scan=new Scanner(System.in);
		int[] arr=new int[5];
		for(int i=0;i<5;i++) {
			arr[i]=scan.nextInt();
		}
		int ans=1000000;
		for(int i=0;i<3;i++) {
			for(int j=i+1;j<4;j++) {
				for(int k=j+1;k<5;k++) {
					int tmp=arr[j]*arr[k]/(GCD(arr[j],arr[k]));
					tmp=arr[i]*tmp/GCD(arr[i],tmp);
					if(tmp<ans) {
						ans=tmp;
					}
				}
			}
		}
		System.out.print(ans);
		scan.close();
	}
}


/*
def GCD(a,b):
    i=1
    ans=1
    while(i<=b):
        if(a%i==0 and b%i==0):
            ans=i
        i+=1
    return ans
 
    
#########MAIN#######
a,b=map(int,input().split())
if a<b:
    tmp=a
    a=b
    b=tmp
     
print(GCD(a,b))
lcm=a*b/GCD(a,b)
print(int(lcm))
*/