// 学籍番号：22H062，氏名：中江亮介，課題番号：Kadai08_3
import java.io.*;

class Score_1{
    int s1, s2, s3;//, total;
    //double average;

    public void setScore(){
        System.out.printf("科目１ : " + s1 + " 点\t");
        System.out.printf("科目２ : " + s2 + " 点\t");
        System.out.println("科目３ : " + s3 + " 点");
        // getTotal();
        // getAverage();
    }

    int getTotal(){
        int total = s1 + s2 + s3;
        return total;
    }

    double getAverage(){
        getTotal();
        double average = (double)total / 3;
        return average;
    }
}

class Kadai08_3
{ 
	public static void main(String[] args) throws IOException {	
        int[] math = { 40, 80}, chmi = { 90, 50}, phys = { 60, 50};
        //int[] math = { 40, 80, 60}, chmi = { 90, 50, 20}, phys = { 60, 50, 50};

        Score_1 subject = new Score_1();

        for(int i = 0; i < math.length; i++){
            // subject.s1 = math[i];
            // subject.s2 = chmi[i];
            // subject.s3 = phys[i];
            System.out.println(i+1 + "番目の学生");
            subject.setScore();
            System.out.printf("合計点： " + subject.total + "点\t");
            System.out.println("平均点： " + String.format("%.2f", subject.average) + "点");
        }
    }
}
