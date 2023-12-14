// 学籍番号：22H062，氏名：中江亮介，課題番号：課題11_4

import java.io.*;

class Kadai11_4
{
    public static void main(String args[]) throws IOException{
        double length = (Math.random() * 5) + 1;
        System.out.print(length);

        int deg = Math.rint((Math.random() * 90) + 1);
        System.out.print(deg);

        double S = Math.pow(length) * Math.sin(deg);

        System.out.print(S);
    }
}
