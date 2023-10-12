// 学籍番号：22H062，氏名：中江亮介，課題番号：課題2

import java.io.*;

class Kadai03_2 {
   public static void main(String[] args) throws IOException {
      System.out.print("整数を入力してください");

      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

      int num = Integer.parseInt(br.readLine());

      System.out.println("入力した値" + num + (((num % 2) == 0) ? "は偶数です。" : "は奇数です。"));

   }
}