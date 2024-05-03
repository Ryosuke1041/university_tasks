// 学籍番号：22H062，氏名：中江亮介，課題番号：課題Kadai08_1

class Measurement_2 
{ 
	//  String  name;     //名前 
	//  int   age;      //年齢 
	//  double  height;      //身長 
	//  double  weight;      //体重 
	//  double  waist;     //腹囲 
	//  double  standardWeight;    //標準体重 
	 
	 void show(String name, int age, double height, double weight, double waist) 
	 { 
		  double standardWeight =  this.calculate(height); 
		 
		  System.out.printf("名前： %s  年齢： %d 歳  身長： %.2f cm  体重： %.2f kg  腹囲： %.2f cm\n" 
		                   , name, age, height, weight, waist); 
		  System.out.printf("    標準体重は %8.3f kg です。\n", standardWeight); 
		  System.out.printf("    (体重―標準体重)は%8.3f kg です。\n", (weight-standardWeight)); 
		  this.judge(weight, height);
	 } 
	 
	 double calculate(double h){ 
		  double sW = 22.0 * ( h / 100.0 ) * ( h / 100.0 ); 
		  return sW; 
	 }
	 
	 void judge(double w,double h){
	 	double bmi = w / (( h / 100.0 ) * ( h / 100.0 ));
		if(bmi < 18.5){
			System.out.printf("BMI=%.1f ＊＊＊ 低体重 ＊＊＊", bmi);
		}else if(25 < bmi){
			System.out.printf("BMI=%.1f ＊＊＊ 肥満 ＊＊＊", bmi);
		}else{
			System.out.printf("BMI=%.1f ＊＊＊ 普通体重 ＊＊＊", bmi);
		}
	 }
}


class Kadai08_1
{ 
	 public static void main(String[] args) 
	 { 
		  Measurement_2 student1 = new Measurement_2(); 
		  Measurement_2 student2 = new Measurement_2(); 
		  Measurement_2 student3 = new Measurement_2();   
		  String name; 
		  int    age; 
		  double height, weight, waist; 
		 
		  System.out.println("\n 学生:student1"); 
		  name = "Kishida";  age = 22;  height = 170.2;  weight = 50.2;  waist = 80.2; 
		  student1.show(name, age, height, weight, waist); 
		  System.out.println("\n 学生:student2"); 
		  name = "Matsuno";  age = 19;  height = 173.3;  weight = 63.3;  waist = 93.3; 
		  student2.show(name, age, height, weight, waist); 
		  System.out.println("\n 学生:student3"); 
		  name = "Suzuki";  age = 20;   height = 161.1;  weight = 71.1;   waist = 51.1; 
		  student3.show(name, age, height, weight, waist); 
	 } 
} 
 