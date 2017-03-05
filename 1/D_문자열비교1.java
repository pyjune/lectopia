import java.util.Scanner;
import java.io.FileInputStream;

public class Solution {

	public static void main(String[] args) throws Exception{
		
		//System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		String pattern;
		String text;
		for(int tc = 1; tc<=T;tc++)
		{
			pattern = sc.next();
			text = sc.next();
			
			int r=0;
			if(text.contains(pattern))
				r = 1;
			
			System.out.println("#"+tc+" "+r);
			
		}
	}

}

