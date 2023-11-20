// 学籍番号：22H062，氏名：中江亮介，課題番号：Kadai07_4
import java.io.*;

class Figure_2
{ 
    double width; //横 変更しない
    double height; //縦 変更しない
    double area; //面積 変更しない
    double depth;
    double volume;
    public void setLength(double w, double h, double d) //引数の追記
    { 
    //仮引数をフィールドへ代入
        width = w;
        height = h;
        depth = d;
        System.out.printf(" 横：%7.2f 縦：%7.2f 奥行：%7.2f\n", width, height, depth);
        // getArea(); //このメソッドはコメントにする
    } 
    double getArea() //戻り値の型変更、戻り値を追記
    { 
        area = width * height; //変更しない
        return area;
    } 
    double getVolume(){
        volume = getArea() * depth;
        return volume;
    }
} 
class Kadai08_4
{ 
    public static void main(String[] args)
    { 
        Figure_2 fig1 = new Figure_2(); 
        Figure_2 fig2 = new Figure_2(); 
        //実引数として使用する２つの変数 width, height を宣言追加
        double width = 10.0;
        double height = 40.0;
        double depth = 20.0;
        
        // fig1.width = 10.0; //実引数として使用する変数への代入に変更
        // fig1.height = 40.0; //実引数として使用する変数への代入に変更
        System.out.printf("\n1 つ目の図形の面積を求めます。\n"); 
        fig1.setLength(width, height, depth); 
        System.out.printf(" 面積は %10.2f です。\n", fig1.getArea()); 
        System.out.printf(" 体積は %10.2f です。\n", fig1.getVolume()); 
        width = 22.2; 
        height = 88.8;
        depth = 11.1;
        System.out.printf("\n2 つ目の図形の面積を求めます。\n");
        fig2.setLength(width, height, depth); 
        System.out.printf(" 面積は %10.2f です。\n", fig2.getArea());
        System.out.printf(" 体積は %10.2f です。\n", fig2.getVolume()); 
        System.out.printf("\n");
    } 
} 