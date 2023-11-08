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
            int syou = 0;
            int dai = 0;
            int hoka = 0;
            int sum = 0;
            while ((str = br_f.readLine()) != null) {
                for(int i = 0; i < str.length(); i++) {
                    System.out.println(str.charAt(i));
                    char c = str.charAt(i);
                    if(Character.isLowerCase(c) == true){
                        syou += 1; 
                    }else if(Character.isUpperCase(c) == true){
                        dai += 1;
                    }else{
                        hoka += 1;
                    }
                }
                sum += 1;
            } 
            br_f.close();
            System.out.println(sum + "行ありました");
            System.out.println("小文字 :" + syou);
            System.out.println("大文字 :" + dai);
            System.out.println("その他 :" + hoka);
        } catch (IOException e) {
            System.out.println("入力エラーです");
        }
    }
}