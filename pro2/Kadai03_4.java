// 学籍番号：22H062，氏名：中江亮介，課題番号：課題4

import java.io.*;

class Kadai03_4
{
   public static void main(String[] args) throws IOException {
      int x = (int)(Math.random() * 5);

      switch (x) {
        case 0:
          System.out.println("今日のあなたの運勢は 大吉(*^▽^*)");
          break;
        case 1:
          System.out.println("今日のあなたの運勢は 中吉(^v^)");
          break;
        case 2:
          System.out.println("今日のあなたの運勢は 小吉(^_^)");
          break;
        case 3:
          System.out.println("今日のあなたの運勢は 末吉(-_-)");
          break;
        case 4:
          System.out.println("今日のあなたの運勢は 凶(T_T)");
          break;
        default:
          System.out.println("今日のあなたの運勢は おみくじ失敗");
          break;
      }
   }
}