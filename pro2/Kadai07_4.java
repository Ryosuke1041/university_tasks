// 学籍番号：22H062，氏名：中江亮介，課題番号：Kadai07_4
import java.io.*;

class Figure_1{
    int major, minor;
    double area;
    String type;

    public void setLength(){
        System.out.printf("長径\t" + major + " 、");
        System.out.printf("短径\t" + minor);
        System.out.println(" に設定しました。");
        getArea();
        getType();
    }

    public void getArea(){
        area = Math.PI * (double)major * (double)minor;
    }

    public void getType(){
        if(major == minor){
            type = "円";
        }else{
            type = "楕円";
        }
    }
}

class Kadai07_4
{ 
	public static void main(String[] args) throws IOException {	
        int[] f_major:{ 80, 50, 30}, f_minor:{ 60, 50, 40}; 
        //int[] f_major:{ 80, 50, 30, 60}, f_minor:{ 60, 50, 40, 60};
        Figure_1 fig = new Figure_1();

        double[] f_area = new double[f_major.length];
        String[] f_type = new String[f_major.length];

        for(int i = 0; i < f_major.length; i++){
            fig.major = f_major[i];
            fig.minor = f_minor[i];
            fig.setLength();
            f_area[i] = fig.area;
            f_type[i] = fig.type;
        }
            
        for(int i=0; i<f_major.length; i++){
            System.out.printf("%2dつ目の図形は、面積:%9.2f の %s です。\n", (i+1), f_area[i], f_type[i]);
        }
    }
}
