// 学籍番号：22H062，氏名：中江亮介，課題番号：課題11_4

import java.io.*;

class Kadai11_4
{
    public static void main(String args[]) throws IOException{
        double length = (Math.random() * 5) + 1;
        System.out.println("ひし形の辺の長さ：" + length);
        
        int deg = (int)Math.rint((Math.random() * 90) + 1);
        System.out.println("内角の 1 つ：" + deg + "度");

        double S = Math.pow(length, 2) * Math.sin(Math.toRadians(deg));

        System.out.print("面積:" + S);
    }
}
