// 学籍番号：22H062，氏名：中江亮介，課題番号：Kadai06_4
import java.io.*;

class Kadai06_4
{ 
	public static void main(String[] args) throws IOException {		
        System.out.println("ファイル名を入力してください");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String file_name = br.readLine();

        try {
            BufferedReader br_f = new BufferedReader(new FileReader(file_name));
            String str;
            char[] syou;
            char[] dai;
            char[] hoka;
            while ((str = br_f.readLine()) != null) {
                System.out.println(str);
                for(int i = 0; i < str.length(); i++) {
                    System.out.println(str.charAt(i));
                    char c = str.charAt(i);
                    if(Character.isLowerCase(c) == true){
                        syou = str; 
                    }else if(Character.isUpperCase(c) == true){
                        dai = str;
                    }else{
                        hoka = str;
                    }
                } 
                
            } 
            br_f.close();
            System.out.println(str.length + "行ありました");
            System.out.println("小文字 :" + syou.length);
            System.out.println("大文字 :" + dai.length);
        } catch (IOException e) {
            System.out.println("入力エラーです");
        }
    }
}