// 学籍番号：22H062，氏名：中江亮介，課題番号：Kadai05_3

import java.io.*;
import java.util.Arrays;

class Kadai05_3 {
    public static void main(String[] args) throws IOException {
        System.out.println("文字列を入力してください");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        char c[] = new char[str.length()];
        // 一文字ずつ配列に格納
        for (int i = 0; i < str.length(); i++) {
            c[i] = str.charAt(i);
        }
        Arrays.sort(c);
        System.out.println(c);
    }
}