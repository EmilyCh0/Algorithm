// codeforces #726 B - 5love song
import java.io.*;
import java.util.*;

public class div2_727_B {
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		int n = Integer.parseInt(st.nextToken());
		int q = Integer.parseInt(st.nextToken());
		String str = br.readLine();
		StringBuilder sb = new StringBuilder();
		int arr[] = new int[n+1];
		arr[0]=0;
		for(int i=1;i<=n;i++) {
			arr[i]=arr[i-1]+str.charAt(i-1)-'a'+1;
		}
		for(int i=0;i<q;i++) {
			st = new StringTokenizer(br.readLine()," ");			
			int s = Integer.parseInt(st.nextToken());
			int e = Integer.parseInt(st.nextToken());
			int ans = arr[e]-arr[s-1];
			sb.append(ans+"\n");
		}
		System.out.print(sb.toString());
		
	}
}
