import java.io.*;
class Kadai15_2
{
	public static void main(String[] args) throws IOException
	{
		System.out.println("整数を１つ入力してください");
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String str1 = br.readLine();
		
		int num1 = Integer.parseInt(str1);
		int num2 = num1;
		int num3 = num1;
		num1 = num1 << 3;
		System.out.println("8倍" + num1);
		
		num1 = num1 << 3;
		System.out.println("64倍" + num1);
		
		System.out.println(num2);
		num2 /= 16;
		System.out.print("16で割ると" + num2);
		num3 %= 16;
		System.out.println("あまり" + num3);
	}
}