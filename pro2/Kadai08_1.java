// wÐÔF22H062C¼F]ºîCÛèÔFÛèKadai08_1

class Measurement_2 
{ 
	//  String  name;     //¼O 
	//  int   age;      //Nî 
	//  double  height;      //g· 
	//  double  weight;      //Ìd 
	//  double  waist;     // Í 
	//  double  standardWeight;    //WÌd 
	 
	 void show(String name, int age, double height, double weight, double waist) 
	 { 
		  double standardWeight =  this.calculate(height); 
		 
		  System.out.printf("¼OF %s  NîF %d Î  g·F %.2f cm  ÌdF %.2f kg   ÍF %.2f cm\n" 
		                   , name, age, height, weight, waist); 
		  System.out.printf("    WÌdÍ %8.3f kg Å·B\n", standardWeight); 
		  System.out.printf("    (Ìd\WÌd)Í%8.3f kg Å·B\n", (weight-standardWeight)); 
		  this.judge(weight, height);
	 } 
	 
	 double calculate(double h){ 
		  double sW = 22.0 * ( h / 100.0 ) * ( h / 100.0 ); 
		  return sW; 
	 }
	 
	 void judge(double w,double h){
	 	double bmi = w / (( h / 100.0 ) * ( h / 100.0 ));
		if(bmi < 18.5){
			System.out.printf("BMI=%.1f  áÌd ", bmi);
		}else if(25 < bmi){
			System.out.printf("BMI=%.1f  ì ", bmi);
		}else{
			System.out.printf("BMI=%.1f  ÊÌd ", bmi);
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
		 
		  System.out.println("\n w¶:student1"); 
		  name = "Kishida";  age = 22;  height = 170.2;  weight = 50.2;  waist = 80.2; 
		  student1.show(name, age, height, weight, waist); 
		  System.out.println("\n w¶:student2"); 
		  name = "Matsuno";  age = 19;  height = 173.3;  weight = 63.3;  waist = 93.3; 
		  student2.show(name, age, height, weight, waist); 
		  System.out.println("\n w¶:student3"); 
		  name = "Suzuki";  age = 20;   height = 161.1;  weight = 71.1;   waist = 51.1; 
		  student3.show(name, age, height, weight, waist); 
	 } 
} 
 