// 学籍番号：22H062，氏名：中江亮介，課題番号：課題11_3

import java.io.*;

class Kadai11_3
{
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("文字列を入力");
        String str1 = br.readLine();

        System.out.println("文字列を入力");
        String str2 = br.readLine();
        int pos = str1.lastIndexOf(str2.charAt(0));
        System.out.println(pos);
        str1 = str1.toLowerCase();
        StringBuffer sb = new StringBuffer(str1.substring(0, pos));
        sb.append(str2.toUpperCase());

        System.out.print(sb);
    }
}