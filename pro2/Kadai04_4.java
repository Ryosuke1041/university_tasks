// 学籍番号：22H062，氏名：中江亮介，課題番号：課題4

import java.io.*;

class Kadai04_4
{
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        long start = System.currentTimeMillis();
        for(int i=1; i<=5; i++){
            int a = (int)(Math.random()*100);
            int b = (int)(Math.random()*100);
            int sum;
            System.out.print(a + "+" + b + "=?");
            int num = Integer.parseInt(br.readLine());
            sum = a+b;
            while(sum != num){
                System.out.print("間違いです。もう一度入力");
                int num = Integer.parseInt(br.readLine());
            }
            System.out.print("正解!!");

        }
        long end = System.currentTimeMillis();
        System.out.println("¥n 5 問正解までの時間は"+((end-start)/1000.0)+"秒でした");
    }
}