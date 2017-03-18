/* input.txt
9 12
1 2 1 3 3 2 3 4 2 5 5 4 1 6 6 7 7 8 4 7 4 9 5 9
 */

import java.util.*;
import java.io.FileInputStream;

public class Solution {

	public static void main(String[] args)throws Exception {
		// TODO Auto-generated method stub
		System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int V = sc.nextInt();
		int E = sc.nextInt();
		int adj[][] = new int [V+1][V+1];
		int visited[] = new int [V+1];
		
		for(int i = 0; i<E; i++)
		{
			int n1 = sc.nextInt();
			int n2 = sc.nextInt();
			adj[n1][n2] = 1;
			adj[n2][n1] = 1;
		}
		for(int i =1 ;i<=V; i++)
			visited[i] = -1;
		Queue <Integer> q = new LinkedList<>();
		q.add(1);
		visited[1] = 0;
		while(!q.isEmpty())
		{
			int t = q.poll();
			for(int i= 1; i<=V; i++)
			{
				if(adj[t][i]==1 && visited[i]==-1)
				{
					q.add(i);
					visited[i] = visited[t]+1;
				}
			}
		}
		int s = 0;
		for(int i = 1; i<=V; i++)
		{
			s+= visited[i];
		}
		System.out.println(s);
	}

}
