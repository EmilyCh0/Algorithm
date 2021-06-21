// codeforces #726 A
import java.util.*;
import java.io.*;

public class div2_716_A {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for(int i=0;i<T;i++) {
			int N = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine()," ");
			int sum=0;
			for(int j=0;j<N;j++) {
				sum+=Integer.parseInt(st.nextToken());
			}
			if(sum<=0||(sum-N<0)) {
				System.out.println("1");
			}
			else {
				System.out.println(sum-N);
			}
		}

	}

}
