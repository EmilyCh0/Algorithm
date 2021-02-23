package baekjoon_s;
import java.util.*;
public class BOJ_1411 {
	static class Node {
		char[] ch;
		int cnt;
		Node(String str){
			this.ch=str.toCharArray();
			this.cnt=0;
			
		}
	}
	public static void main(String args[]) {
		Scanner scan=new Scanner(System.in);
		int N=scan.nextInt();
		int ans=0;
		
		Node[] arr = new Node[N];
		for(int i=0;i<N;i++) {
			String tmp=scan.next();
			arr[i]=new Node(tmp);
			for(int j=0;j<arr[i].ch.length;j++) {
				boolean check=false;
				for(int k=0;k<j;k++) {
					if(arr[i].ch[k]==arr[i].ch[j])
						check=true;
				}
				if(!check)
					arr[i].cnt++;
			}
		}
		for(int i=0;i<N;i++) {
			for(int j=i+1;j<N;j++) {
				boolean check=true;
				if(arr[i].cnt==arr[j].cnt) {
					for(int k=0;k<arr[i].ch.length;k++) {
						char a=arr[i].ch[k];
						char b=arr[j].ch[k];
						int idx;
						for(int l=k+1;l<arr[i].ch.length;l++) {
							if(arr[i].ch[l]==a) {
								idx=l;
								if(arr[j].ch[idx]!=b){
									check=false;
									break;
								}
							}
						}
						if(!check)
							break;
					}
					if(check)
						ans++;
				}
			}
		}
		System.out.print(ans);
	}
}
