// 学籍番号：22H062，氏名：中江亮介，課題番号：Kadai06_5
import java.io.*;

class Kadai06_5
{ 
	static int tefuda_m[] = new int[5];
    static int tefuda_n[] = new int[5];

    public static void showCards()
    {
        System.out.println("カードは");
        String str_out;
        for(int i=0;i<5;i++){
            System.out.print("[" +(i+1)+"] ");
            switch (tefuda_m[i]){
                case 0:
                    str_out= "スペード¥t";
                    break;
                case 1:
                    str_out="ハート¥t";
                    break;
                case 2:
                    str_out="ダイヤ¥t";
                    break;
                case 3:
                    str_out="クラブ¥t";
                    break;
                default:
                    str_out="??? ";
            }
            System.out.println(str_out+(tefuda_n[i]+1));
        }
    }


    public static void main(String[] args) throws IOException
    //課題では入力があるのであらかじめこのように記述しています。
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int count=0,mark,num;
        boolean[][] cards = new boolean[4][13];
        while(count<5){
            mark = (int)(Math.random()*4); // 0:スペード 1:ハート 2:ダイヤ 3:クラブ
            num = (int)(Math.random()*13);
            tefuda_m[count]=mark;
            tefuda_n[count]=num;
            count++;
            cards[mark][num] = true;
        }
        showCards(); //showCards()メソッドを呼び出すことで出力している

        System.out.print("交換する枚数は？");
        int maisuu = Integer.parseInt(br.readLine());
        int changed_num;
        for(int i = 0; i < maisuu; i++){
            System.out.print(i+1 + "枚目は何番のカードを交換しますか？");
            changed_num = Integer.parseInt(br.readLine());
            for(int k = 0; k < 5; k++){
                if(k == changed_num - 1){
                    mark = (int)(Math.random()*4); // 0:スペード 1:ハート 2:ダイヤ 3:クラブ
                    num = (int)(Math.random()*13);
                    tefuda_m[k]=mark;
                    tefuda_n[k]=num;
                    cards[mark][num] = true;
                }
            }
        }
        System.out.println("カードは");
        String str_out;
        for(int i = 0; i < 5; i++){
            System.out.print("[" +(i+1)+"] ");
            switch (tefuda_m[i]){
                case 0:
                    str_out= "スペード¥t";
                    break;
                case 1:
                    str_out="ハート¥t";
                    break;
                case 2:
                    str_out="ダイヤ¥t";
                    break;
                case 3:
                    str_out="クラブ¥t";
                    break;
                default:
                    str_out="??? ";
            }
            System.out.println(str_out+(tefuda_n[i]+1));
        }
    }
}
