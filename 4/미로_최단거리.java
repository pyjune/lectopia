package maze_bfs;

import java.util.*;
import java.awt.Point;
import java.io.FileInputStream;

public class maze_bfs {

	static int M[][] = new int[100][100];
	static int N;
	static int V[][];
	static int Q[][] = new int[10000][2];
	static int front;
	static int rear;
	public static void main(String[] args)throws Exception {
		// TODO Auto-generated method stub
		int str = 0, stc = 0;
		int edr = 0, edc = 0;
		int r;
		System.setIn(new FileInputStream("Text.txt"));
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int tcase=1;tcase<=T;tcase++)
		{
			N = sc.nextInt();
			V = new int[100][100];
			
			for(int i=0;i<N;i++)
			{
				String line = sc.next();
				for(int j=0;j<N;j++)
				{
					M[i][j] = line.charAt(j) - '0';
					if(M[i][j] == 2)
					{
						str = i;
						stc = j;
					}
					if(M[i][j] == 3)
					{
						edr = i;
						edc = j;
					}
					
				}
			}
			bfs(str, stc);
			
			if(V[edr][edc]==0)
				r = 0;
			else
				r = V[edr][edc]-V[str][stc]-1;
			System.out.println("#"+tcase+" "+r);
		}
		sc.close();
		
	}
	public static void bfs2(int r, int c)
	{
		int dr[] = {0, 1, 0, -1};
		int dc[] = {1, 0, -1, 0};
		Queue<Point> q = new LinkedList<>();
		q.add(new Point(r, c));
		V[r][c] = 1;
		while(!q.isEmpty())
		{
			Point p = q.poll();
			
			for(int i=0;i<4;i++)
			{
				int nr = p.x + dr[i];
				int nc = p.y + dc[i];
				if(nr>=0&&nr<N&&nc>=0&&nc<N)
				{
					if((M[nr][nc]!=1)&&(V[nr][nc]==0))
					{
						q.add(new Point(nr, nc));
						V[nr][nc] = V[p.x][p.y]+1;
					}
				}
			}
		}
	}
	public static void bfs(int r, int c)
	{
		int dr[] = {0, 1, 0, -1};
		int dc[] = {1, 0, -1, 0};
		front = -1;
		rear = -1;
		enQ(r, c);
		V[r][c] = 1;
		while(front!=rear)
		{
			int idx = deQ();
			r = Q[idx][0];
			c = Q[idx][1];
			
			for(int i=0;i<4;i++)
			{
				int nr = r+dr[i];
				int nc = c+dc[i];
				if(nr>=0&&nr<N&&nc>=0&&nc<N)
				{
					if((M[nr][nc]!=1)&&(V[nr][nc]==0))
					{
						enQ(nr, nc);
						V[nr][nc] = V[r][c]+1;
					}
				}
			}
		}
	}
	public static void enQ(int r, int c)
	{
		rear++;
		Q[rear][0] = r;
		Q[rear][1] = c;
	}
	public static int deQ()
	{
		front++;
		return front;
	}
}
