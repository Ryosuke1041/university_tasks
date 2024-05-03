   class Measurement_4 
{ 
	private String      name;                     //���O 
	private int         age;                        //�N�� 
	private double      height, weight, waist, standardWeight, bmi;   //�g��, �̏d, ����, �W���̏d, �a�l�h 
	public static int        n=0, total_age=0;         //�l���̃J�E���g, �N��̍��v
	private double total_bmi = 0; 
	private Measurement_4()  
	{   
	 	this.name = "";  this.age = 0;  this.height = 0.0;  this.weight = 0.0;  this.waist = 0.0;   
		this.standardWeight = 0;  this.bmi = 0.0;   
		System.out.printf("���C���X�^���X�ϐ������������܂����B��\n");    
	}    
	public Measurement_4(String na, int ag, double he, double we, double wa)  
	{     
		this();   
		if((check(ag) == 0) && (check(he) == 0) && (check(we) == 0)){
			this.name = na;  this.age = ag;  this.height = he;  this.weight = we;  this.waist = wa;  
			n++;  total_age += ag;   
			System.out.printf("    ���O�F%8s  �N��F%3d ��  �g���F%.2f cm  �̏d�F%.2f kg  ���́F%.2f cm ��ݒ肵�܂����B\n", name, age, height, weight, waist);  
		}else{
			if(check(ag) != 0){
				System.out.printf("**�G���[�F�N��F %3d �Ȃ̂Őݒ�s��", age);
			}
			if(check(he) != 0){
				System.out.printf("**�G���[�F�g���F %.2f �Ȃ̂Őݒ�s��", height);
			}
			if(check(we) != 0){
				System.out.printf("**�G���[�F�̏d�F %.2f �Ȃ̂Őݒ�s��", weight);
			}
		}
	}    
	public static void average(){  
	 	System.out.printf("\n  %2d �l�̔N��̕��ς� %7.2f �˂ł��B\n", n, total_age / n);
		total_bmi = weight / ((height / 100.0) * (height / 100.0));   
		System.out.printf("  %2d �l�̔N��̕��ς� %7.2f �˂ł��B\n", n, total_bmi / n); 
	}    
	public void show(){
		this.calculate();  
		if(name != null){
			System.out.printf("    �W���̏d�� %8.3f kg �ł��B", standardWeight);   
			System.out.printf("  (�̏d�\�W���̏d)��%8.3f kg �ł��B", (weight-standardWeight));   
			this.judge(); 
		} 
	}   
	private void calculate(){ 
		standardWeight = 22.0 * ( height / 100.0 ) * ( height / 100.0 );  
	}  
	private void judge(){   
	 	bmi = weight / ((height / 100.0) * (height / 100.0));   System.out.printf("  �a�l�h=%.1f", bmi);   
		if( bmi < 18.5 )     System.out.printf("  ������ ��̏d ������\n");   
		else if( bmi >= 18.5 && bmi<25.0)  System.out.printf("  ���������ʑ̏d������\n");  
		else        System.out.printf("  ������  �얞  ������\n");  
		total_bmi += bmi;
	}   
	private double check(double tmp){
		if(tmp >= 0.0 && tmp <= 300.0){
			return 0;
		}else{
			return 1;
		}
	}
	private double check(int tmp1){
		if(tmp1 >= 0 && tmp1 <= 150){
			return 0;
		}else{
			return 1;
		}
	}
} 

class Kadai10_1
{  
	public static void main(String[] args)  
	{   
		System.out.printf("\n�w��:student1\n");
		Measurement_4 student1 = new Measurement_4( "Kishida", 222,  170.2,  50.2, 80.2);	student1.show();
		System.out.printf("\n�w��:student2\n");
		Measurement_4 student2 = new Measurement_4( "Kishida",  22,  170.2,  50.2, 80.2);	student2.show();
		System.out.printf("\n�w��:student3\n");
		Measurement_4 student3 = new Measurement_4( "Matsuno",  19, 1173.3, -63.2, 93.3);	student3.show();
		System.out.printf("\n�w��:student4\n");
		Measurement_4 student4 = new Measurement_4( "Matsuno",  19,  173.3,  63.2, 93.3);	student4.show();
		System.out.printf("\n�w��:student5\n");
		Measurement_4 student5 = new Measurement_4(  "Suzuki", -20, -161.1,  71.1, 51.1);	student5.show();
		System.out.printf("\n�w��:student6\n");
		Measurement_4 student6 = new Measurement_4(  "Suzuki",  20,  161.1,  71.1, 51.1);	student6.show();
		
		Measurement_4.average();//�����ɏ��������l���A�N��̕��ϒl�Ƃa�l�h�̕��ϒl��\������N���X���\�b�h��ǉ����Ȃ����B 
	} 
}