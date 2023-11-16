// 学籍番号：22H062，氏名：中江亮介，課題番号：Kadai07_3
import java.io.*;

class Score_1{
    private int s1, s2, s3, total;
    private double average;

    public void setScore(){
        system.out.printf("科目１ : " + s1 + " 点");
        system.out.printf("科目２ : " + s2 + " 点");
        system.out.println("科目３ : " + s3 + " 点");
        getTotal.show();
        getAverage.show();
    }

    public void getTotal(){
        total = s1 + s2 + s3;
        system.out.printf("合計点： " + total);
    }

    public void getTotal(){
        average = total / 3;
        system.out.println("平均点： " + average);
    }
}

class Kadai07_3
{ 
	public static void main(String[] args) throws IOException {	
        int[] math = { 40, 80}, chmi = { 90, 50}, phys = { 60, 50};
        int[] math = { 40, 80, 60}, chmi = { 90, 50, 20}, phys = { 60, 50, 50};

        Score_1 subject1 = new Score_1();

        for(int i = 0; i < math.length; i++){
            Score_1.s1 = math[i];
            Score_1.s2 = chmi[i];
            Score_1.s3 = phys[i];
            system.out.println(i + "番目の学生");
            setScore.show();
        }
    }
}
