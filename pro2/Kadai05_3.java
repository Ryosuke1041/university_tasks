// 学籍番号：22H062，氏名：中江亮介，課題番号：Kadai05_3

import java.io.*;

class Kadai04_4
{
    public static void main(String args[]) throws IOException{
        System.out.println("文字列を入力してください");

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();

        int num = 0;

        for (int i = 0; i < str.length; i++) {
            for (int j = 0; j < str.length - 1; j++) {
                if (num[j] > num[j + 1]) {
                    int sum = num[j];
                    num[j] = num[j + 1];
                    num[j + 1] = sum;
                }
            }
        }
        System.out.println(sum);
    }
}