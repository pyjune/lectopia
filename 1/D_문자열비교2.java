import java.util.Scanner;
import java.io.FileInputStream;

public class Solution {

	public static void main(String[] args) throws Exception{
		
		System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		char[] pattern;
		char[] text;
		for(int tc = 1; tc<=T;tc++)
		{
			String strPat = sc.next();
			String strTxt = sc.next();
			int patLen = strPat.length();
			int txtLen = strTxt.length();
			pattern = new char[patLen];
			text = new char[txtLen];
			
			pattern = strPat.toCharArray();
			text = strTxt.toCharArray();
			int r = 0;
			int j =0;
			for(int i= 0; i<=txtLen-patLen; i++)
			{
				for(j = 0; j<patLen; j++)
				{
					if(pattern[j] != text[i+j])
						break;
				}
				if(j==patLen)
				{
					r = 1;
					break;
				}
			}
			
			System.out.println("#"+tc+" "+r);
			
		}
	}

}

