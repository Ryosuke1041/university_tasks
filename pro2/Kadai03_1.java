// 学籍番号：22H062，氏名：中江亮介，課題番号：課題１

import java.io.*;

class Kadai03_1
{
   public static void main(String[] args) throws IOException
   {
      System.out.println("整数を2 つ入力してください");

      BufferedReader br =
        new BufferedReader(new InputStreamReader(System.in));
        
      int num1 = Integer.parseInt(br.readLine());
      int num2 = Integer.parseInt(br.readLine());

      if (num1 > num2) {
        System.out.println(num1 + " ÷ " + num2 + " = " + (double)num1 / num2);
      } else if (num1 < num2) {
        System.out.println(num2 + " ÷ " + num1 + " = " + (double)num2 / num1);
      } else {
        System.out.println("同じ値です");
      }
   }
}
