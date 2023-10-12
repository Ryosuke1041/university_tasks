// 学籍番号：22H062，氏名：中江亮介，課題番号：課題3

import java.io.*;

class Kadai03_3 {
  public static void main(String[] args) throws IOException {
    System.out.println("3 辺の長さを入力してください");

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int a = Integer.parseInt(br.readLine());
    int b = Integer.parseInt(br.readLine());
    int c = Integer.parseInt(br.readLine());

    if (a + b > c && b + c > a && c + a > b) {
      double s = (a + b + c) / 2.0;
      double area = Math.sqrt(s * (s - a) * (s - b) * (s - c));
      System.out.println("三角形の面積は" + area);
    } else {
      System.out.println("三角形を作れません");
    }
  }
}