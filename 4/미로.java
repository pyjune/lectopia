package maze;
import java.util.*;
import java.io.FileInputStream;

public class Maze {

	static int [][] maze;
	static char [][]map;
	static int N;
	public static void main(String[] args)throws Exception {
		// TODO Auto-generated method stub
		int str = 0, stc = 0;
		System.setIn(new FileInputStream("Text.txt"));
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int tcase=1;tcase<=T;tcase++)
		{
			N = sc.nextInt();
			maze = new int[N][N];
			map =new char[N][N];
			for(int i=0;i<N;i++)
			{
				String line = sc.next();
				map[i] = line.toCharArray();// 참고
				for(int j=0;j<N;j++)
				{
					maze[i][j] = line.charAt(j) - '0';
					if(map[i][j] == '2') // 참고
					{
						str = i;
						stc = j;
					}
					if(maze[i][j] == 2)
					{
						str = i;
						stc = j;
					}
					
				}
			}
			int r = dfs(str, stc);
			System.out.println("#"+tcase+" "+r);
		}
		
	}
	public static int dfs(int r, int c)
	{
		int dr[] = {0, 1, 0, -1};
		int dc[] = {1, 0, -1, 0};
		
		if(maze[r][c]==3)
		{
			return 1;
		}
		else
		{
			maze[r][c] = 1;
			for(int i=0;i<4;i++)
			{
				int nr = r+dr[i];
				int nc = c+dc[i];
				if(nr>=0&&nr<N&&nc>=0&&nc<N)
				{
					if(maze[nr][nc]!=1)
					{
						if(dfs(nr, nc)==1)
							return 1;
					}
				}
			}
			return 0;
		}
	}

}
