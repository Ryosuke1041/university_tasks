//課題３．（１０点）
//課題３のサンプルプログラム

class Score
{
	private int s1, s2, s3, total;
	private double average;
	
	public void setScore_3(int s1, int s2)
	{
		if(checkScore(s1) == 0 && checkScore(s2) == 0){
			this.s1 = s1;			this.s2 = s2;
			System.out.printf("\n　　科目１：%6d 点\t　　科目２：%6d 点\n", this.s1, this.s2);
		}
		else{
			this.s1 = 0;			this.s2 = 0;
			System.out.printf("\n　　***** エラー：入力された点数は不適切なので点数を初期化しました。 *****\n");
		}
	}

	public void setScore_3(int s1, int s2, int s3)
	{
		if(checkScore(s1) == 0 && checkScore(s2) == 0 && checkScore(s3) == 0){
			this.s1 = s1;			this.s2 = s2;		this.s3 = s3;
			System.out.printf("\n　　科目１：%6d 点\t　　科目２：%6d 点\t　　科目３：%6d 点\n", this.s1, this.s2, this.s3);
		}
		else{
			this.s1 = 0;			this.s2 = 0;		this.s3 = 0;
			System.out.printf("\n　　***** エラー：入力された点数は不適切なので点数を初期化しました。 *****\n");
		}
	}

	private int checkScore(int sn) 
	{
		if( sn >= 0 && sn <= 100) return 0;
		else return 1;
	}

	public int getTotal(int n)
	{
		if(n == 2){
			total = s1 + s2;		
		}else if(n == 3){
			total = s1 + s2 + s3;		
		}
		return total;
	}

	public double getAverage(int n)
	{
		if(n == 2){
			average = (double)total / 2;		
		}else if(n == 3){
			average = (double)total / 3;
		}
		return average;
	}
}

class Kadai09_3
{
	public static void main(String[] args)
	{
		Score subject = new Score();
		int n;									//コメントを外す
		
		//subject.setScore_3( -75, 182);					//コメントにする
		subject.setScore_3( -75, 182);  n=2;		//コメントを外す
		System.out.printf("　　合計点：%6d 点　　平均点：%6.2f 点\n", subject.getTotal(n), subject.getAverage(n));
		
		//subject.setScore_3( -75, 82);						//コメントにする
		subject.setScore_3( 75, 82);  n=2;		//コメントを外す
		System.out.printf("　　合計点：%6d 点　　平均点：%6.2f 点\n", subject.getTotal(n), subject.getAverage(n));
		
		//subject.setScore_3( 75, 182);						//コメントにする
		subject.setScore_3( 75, 182, -87);  n=3;		//コメントを外す
		System.out.printf("　　合計点：%6d 点　　平均点：%6.2f 点\n", subject.getTotal(n), subject.getAverage(n));
		
		//subject.setScore_3( 75, 82);					//コメントにする
		subject.setScore_3( 75, 82, 87);  n=3;		//コメントを外す
		System.out.printf("　　合計点：%6d 点　　平均点：%6.2f 点\n", subject.getTotal(n), subject.getAverage(n));
	}
}