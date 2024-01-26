import java.io.*;
class Kadai15_2
{
	public static void main(String[] args) throws IOException
	{
		System.out.println("®”‚ğ‚P‚Â“ü—Í‚µ‚Ä‚­‚¾‚³‚¢");
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String str1 = br.readLine();
		
		int num1 = Integer.parseInt(str1);
		int num2 = num1;
		int num3 = num1;
		num1 = num1 << 3;
		System.out.println("8”{" + num1);
		
		num1 = num1 << 3;
		System.out.println("64”{" + num1);
		
		System.out.println(num2);
		num2 /= 16;
		System.out.print("16‚ÅŠ„‚é‚Æ" + num2);
		num3 %= 16;
		System.out.println("‚ ‚Ü‚è" + num3);
	}
}