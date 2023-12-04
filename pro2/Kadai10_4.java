// 学籍番号：22H062，氏名：中江亮介，課題番号：Kadai10_4


class Score_4
{
	private int s1, s2, s3, total, n1, n2, total_s1, total_s2;
	private double average;

    public Score_4()
	{
		s1 = 0;
        s2 = 0;
        s3 = 0;
        total = 0;
        n1++;
        System.out.printf("＜%3d 番目：インスタンス変数を初期化しました。＞", n1);
	}
	
	public Score_4(int s1, int s2)
	{
        this();
		if(checkScore(s1) == 0 && checkScore(s2) == 0){
			this.s1 = s1;			this.s2 = s2;
            n2++;
            System.out.printf("＜%3d つ目の登録", n2);
			System.out.printf("\n　　科目１：%6d 点\t　　科目２：%6d 点\n", this.s1, this.s2);
            total_s1 = this.s1;
            total_s2 = this.s2;
		}
		else{
			this.s1 = 0;			this.s2 = 0;
			System.out.printf("\n　　***** エラー：入力された点数は不適切なので点数を初期化しました。 *****\n");
		}
	}

	private int checkScore(int sn) 
	{
		if( sn >= 0 && sn <= 100) return 0;
		else return 1;
	}

    public double getAve_sn(int gA){

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

class Kadai010_4
{
	public static void main(String[] args)
	{
		int n; 
 
        Score_4 sub1 = new Score_4( -88, 77); n=2; 
        System.out.printf(" 合計点：%6d 点 平均点：%6.2f 点\n", sub1.getTotal(n), sub1.getAverage(n)); 
        
        Score_4 sub2 = new Score_4( 88, 77); n=2; 
        System.out.printf(" 合計点：%6d 点 平均点：%6.2f 点\n", sub2.getTotal(n), sub2.getAverage(n)); 
        
        Score_4 sub3 = new Score_4( 75, 182); n=2; 
        System.out.printf(" 合計点：%6d 点 平均点：%6.2f 点\n", sub3.getTotal(n), sub3.getAverage(n)); 
        
        Score_4 sub4 = new Score_4( 75, 82); n=2; 
        System.out.printf(" 合計点：%6d 点 平均点：%6.2f 点\n", sub4.getTotal(n), sub4.getAverage(n)); 
        
        System.out.printf("\n"); 
        //ここに科目１の平均値と科目２の平均値をクラスメソッドの戻り値として取得し表示させるコードを追加しなさい。
	}
}