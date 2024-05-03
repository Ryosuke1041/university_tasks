   class Measurement_4 
{ 
	private String      name;                     //名前 
	private int         age;                        //年齢 
	private double      height, weight, waist, standardWeight, bmi;   //身長, 体重, 腹囲, 標準体重, ＢＭＩ 
	public static int        n=0, total_age=0;         //人数のカウント, 年齢の合計
	private double total_bmi = 0; 
	private Measurement_4()  
	{   
	 	this.name = "";  this.age = 0;  this.height = 0.0;  this.weight = 0.0;  this.waist = 0.0;   
		this.standardWeight = 0;  this.bmi = 0.0;   
		System.out.printf("＜インスタンス変数を初期化しました。＞\n");    
	}    
	public Measurement_4(String na, int ag, double he, double we, double wa)  
	{     
		this();   
		if((check(ag) == 0) && (check(he) == 0) && (check(we) == 0)){
			this.name = na;  this.age = ag;  this.height = he;  this.weight = we;  this.waist = wa;  
			n++;  total_age += ag;   
			System.out.printf("    名前：%8s  年齢：%3d 歳  身長：%.2f cm  体重：%.2f kg  腹囲：%.2f cm を設定しました。\n", name, age, height, weight, waist);  
		}else{
			if(check(ag) != 0){
				System.out.printf("**エラー：年齢： %3d なので設定不可", age);
			}
			if(check(he) != 0){
				System.out.printf("**エラー：身長： %.2f なので設定不可", height);
			}
			if(check(we) != 0){
				System.out.printf("**エラー：体重： %.2f なので設定不可", weight);
			}
		}
	}    
	public static void average(){  
	 	System.out.printf("\n  %2d 人の年齢の平均は %7.2f 才です。\n", n, total_age / n);
		total_bmi = weight / ((height / 100.0) * (height / 100.0));   
		System.out.printf("  %2d 人の年齢の平均は %7.2f 才です。\n", n, total_bmi / n); 
	}    
	public void show(){
		this.calculate();  
		if(name != null){
			System.out.printf("    標準体重は %8.3f kg です。", standardWeight);   
			System.out.printf("  (体重―標準体重)は%8.3f kg です。", (weight-standardWeight));   
			this.judge(); 
		} 
	}   
	private void calculate(){ 
		standardWeight = 22.0 * ( height / 100.0 ) * ( height / 100.0 );  
	}  
	private void judge(){   
	 	bmi = weight / ((height / 100.0) * (height / 100.0));   System.out.printf("  ＢＭＩ=%.1f", bmi);   
		if( bmi < 18.5 )     System.out.printf("  ＊＊＊ 低体重 ＊＊＊\n");   
		else if( bmi >= 18.5 && bmi<25.0)  System.out.printf("  ＊＊＊普通体重＊＊＊\n");  
		else        System.out.printf("  ＊＊＊  肥満  ＊＊＊\n");  
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
		System.out.printf("\n学生:student1\n");
		Measurement_4 student1 = new Measurement_4( "Kishida", 222,  170.2,  50.2, 80.2);	student1.show();
		System.out.printf("\n学生:student2\n");
		Measurement_4 student2 = new Measurement_4( "Kishida",  22,  170.2,  50.2, 80.2);	student2.show();
		System.out.printf("\n学生:student3\n");
		Measurement_4 student3 = new Measurement_4( "Matsuno",  19, 1173.3, -63.2, 93.3);	student3.show();
		System.out.printf("\n学生:student4\n");
		Measurement_4 student4 = new Measurement_4( "Matsuno",  19,  173.3,  63.2, 93.3);	student4.show();
		System.out.printf("\n学生:student5\n");
		Measurement_4 student5 = new Measurement_4(  "Suzuki", -20, -161.1,  71.1, 51.1);	student5.show();
		System.out.printf("\n学生:student6\n");
		Measurement_4 student6 = new Measurement_4(  "Suzuki",  20,  161.1,  71.1, 51.1);	student6.show();
		
		Measurement_4.average();//ここに処理した人数、年齢の平均値とＢＭＩの平均値を表示するクラスメソッドを追加しなさい。 
	} 
}