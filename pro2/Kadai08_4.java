// 学籍番号：22H062，氏名：中江亮介，課題番号：Kadai07_4
import java.io.*;

class Figure_2
{ 
    double width; //横 変更しない
    double height; //縦 変更しない
    double area; //面積 変更しない
    public void setLength(double w, double h) //引数の追記
    { 
    //仮引数をフィールドへ代入
        width = w;
        height = h;
        System.out.printf(" 横：%7.2f 縦：%7.2f\n", width, height);
        // getArea(); //このメソッドはコメントにする
    } 
    double getArea() //戻り値の型変更、戻り値を追記
    { 
        area = width * height; //変更しない
        return area;
    } 
} 
class Kadai08_4_sample
{ 
    public static void main(String[] args)
    { 
        Figure fig1 = new Figure(); 
        Figure fig2 = new Figure(); 
        //実引数として使用する２つの変数 width, height を宣言追加
        double width = 10.0;
        double height = 40.0;
        
        // fig1.width = 10.0; //実引数として使用する変数への代入に変更
        // fig1.height = 40.0; //実引数として使用する変数への代入に変更
        System.out.printf("\n1 つ目の図形の面積を求めます。\n"); 
        fig1.setLength(width, height); 
        System.out.printf(" 面積は %10.2f です。\n", fig1.getArea()); //ここは戻り値で値を表示する
        width = 22.2; 
        height = 88.8; 
        System.out.printf("\n2 つ目の図形の面積を求めます。\n");
        fig2.setLength(width, height); 
        System.out.printf(" 面積は %10.2f です。\n", fig2.getArea()); //ここは戻り値で値を表示する
        System.out.printf("\n");
    } 
} 