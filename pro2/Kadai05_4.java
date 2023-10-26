import java.io.*;
import java.util.*;

class Kadai05_4 
{
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
                    um[i][j] = Integer.parseInt(sp[j]);
                } 
            } 
            // ここにプログラムを追加する
        } 
        catch (IOException e) {
            System.out.println("入力エラーです");
        } 
    } 
} 