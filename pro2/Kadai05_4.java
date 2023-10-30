// 学籍番号：22H062，氏名：中江亮介，課題番号：Kadai05_4

import java.io.*;
import java.util.*;

class Kadai05_4 {
    public static void main(String[] args) throws IOException {
        try {
            BufferedReader br_f = new BufferedReader(new FileReader("data.csv"));
            String str;
            ArrayList<String> array = new ArrayList<String>();
            while ((str = br_f.readLine()) != null) {
                array.add(str);
            }
            br_f.close();
            int[][] num = new int[array.size()][];
            for (int i = 0; i < array.size(); i++) {
                String[] sp = array.get(i).split(",");
                num[i] = new int[sp.length];
                for (int j = 0; j < sp.length; j++) {
                    num[i][j] = Integer.parseInt(sp[j]);
                }
            }
            // ここにプログラムを追加する
            for (int i = 0; i < num.length; i++) {
                System.out.print(i + "行目は" + num[i].length + "個のデータがあり、平均は");
                double sum = 0;
                for (int j = 0; j < num[i].length; j++) {
                    sum += num[i][j];
                }
                System.out.println(sum / num[i].length);
            }
        } catch (IOException e) {
            System.out.println("入力エラーです");
        }
    }
}