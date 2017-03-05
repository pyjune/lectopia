import java.util.Scanner;
import java.io.FileInputStream;

public class Solution {
 
	public static void main(String[] args) throws Exception{
		
		System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		int [][] m;
		int T = sc.nextInt();

		for(int tc = 1; tc<=T;tc++)
		{
			int N = sc.nextInt();
			int row = sc.nextInt();
			int col = sc.nextInt();
			m = new int[N][N];
			int v = 1;
			int r = 0;
			int c = 0;
			int l = N-1;
			while(l>0)
			{
				for(int i = 0; i<l; i++)
					m[r][c++] = v++;
				for(int i = 0; i<l; i++)
					m[r++][c] = v++;
				for(int i = 0; i<l; i++)
					m[r][c--] = v++;
				for(int i = 0; i<l; i++)
					m[r--][c] = v++;
				r++;
				c++;
				l -= 2;
			}

			m[N/2][N/2] = v;		
			System.out.println("#"+tc+" "+m[row][col]);
			
		}
	}

}

