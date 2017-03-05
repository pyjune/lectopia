import java.util.Scanner;
import java.io.FileInputStream;

public class Solution {

	public static void main(String[] args) throws Exception{
		
		//System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		int [][] arr;

		for(int tc = 1; tc<=T;tc++)
		{
			int N = sc.nextInt();
			arr = new int[N][N];
			
			for( int i = 0; i<N; i++ )
			{
				for(int j =0; j<N; j++)
				{
					arr[i][j] = sc.nextInt();
				}
			}
			int max = 0;
			for(int i=0; i<N; i++)
			{
				for(int j=0; j<N; j++)
				{
					if(arr[i][j]==1)
					{
						int w = 0;
						while(arr[i][j+w]==1)
							w++;
						int h = 0;
						while(arr[i+h][j]==1)
							h++;
						if(max<h*w)
							max = h*w;
						for(int k=0; k<h;k++)
						{
							for(int l=0;l<w;l++)
							{
								arr[i+k][j+l] = 0;
							}
								
						}
					}
				}
			}
			
			System.out.printf("#%d %d\n", tc, max);
		}
	}

}

