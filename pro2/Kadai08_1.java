// �w�Дԍ��F22H062�C�����F���]����C�ۑ�ԍ��F�ۑ�Kadai08_1

class Measurement_2 
{ 
	//  String  name;     //���O 
	//  int   age;      //�N�� 
	//  double  height;      //�g�� 
	//  double  weight;      //�̏d 
	//  double  waist;     //���� 
	//  double  standardWeight;    //�W���̏d 
	 
	 void show(String name, int age, double height, double weight, double waist) 
	 { 
		  double standardWeight =  this.calculate(height); 
		 
		  System.out.printf("���O�F %s  �N��F %d ��  �g���F %.2f cm  �̏d�F %.2f kg  ���́F %.2f cm\n" 
		                   , name, age, height, weight, waist); 
		  System.out.printf("    �W���̏d�� %8.3f kg �ł��B\n", standardWeight); 
		  System.out.printf("    (�̏d�\�W���̏d)��%8.3f kg �ł��B\n", (weight-standardWeight)); 
		  this.judge(weight, height);
	 } 
	 
	 double calculate(double h){ 
		  double sW = 22.0 * ( h / 100.0 ) * ( h / 100.0 ); 
		  return sW; 
	 }
	 
	 void judge(double w,double h){
	 	double bmi = w / (( h / 100.0 ) * ( h / 100.0 ));
		if(bmi < 18.5){
			System.out.printf("BMI=%.1f ������ ��̏d ������", bmi);
		}else if(25 < bmi){
			System.out.printf("BMI=%.1f ������ �얞 ������", bmi);
		}else{
			System.out.printf("BMI=%.1f ������ ���ʑ̏d ������", bmi);
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
		 
		  System.out.println("\n �w��:student1"); 
		  name = "Kishida";  age = 22;  height = 170.2;  weight = 50.2;  waist = 80.2; 
		  student1.show(name, age, height, weight, waist); 
		  System.out.println("\n �w��:student2"); 
		  name = "Matsuno";  age = 19;  height = 173.3;  weight = 63.3;  waist = 93.3; 
		  student2.show(name, age, height, weight, waist); 
		  System.out.println("\n �w��:student3"); 
		  name = "Suzuki";  age = 20;   height = 161.1;  weight = 71.1;   waist = 51.1; 
		  student3.show(name, age, height, weight, waist); 
	 } 
} 
 