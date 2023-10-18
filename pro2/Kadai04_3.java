// 学籍番号：22H062，氏名：中江亮介，課題番号：課題3

import java.io.*;

class Kadai04_3
{
   public static void main(String[] args) throws IOException {
      System.out.println("高さ？");
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int num = Integer.parseInt(br.readLine());

      for(int i=0; i<num; i++){
         for(int k = 0; k < num-i; k++){
            System.out.print(" ");
         }
         for(int j=0; j<=i; j++){
            if(j != i){
               System.out.print("*");
               System.out.print("-");
            }else{
               System.out.print("*");
            }
         }
         System.out.print("\n");
      }
   }
}