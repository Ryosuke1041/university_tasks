// 学籍番号：22H062，氏名：中江亮介，課題番号：課題11_3

import java.io.*;

class Kadai11_3
{
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.print("文字列を入力");
        String str1 = br.readLine();

        System.out.print("文字列を入力");
        String str2 = br.readLine();
        char sb = str2.charAt(0);
        int pos = str1.lastIndexOf(sb);
        StringBuffer sb = str1.substring(0, pos-1);
        sb.append(str2);

        System.out.print(sb);
    }
}