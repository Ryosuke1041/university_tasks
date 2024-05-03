// 学籍番号：22H062，氏名：中江亮介，課題番号：Kadai10_3

class Kakeibo_1
{
	private int year, month, day, income, expenses;		//年, 月, 日, 収入, 支出
    private static int savings;
	
	private Kakeibo_1()		//クラスの外からアクセスできないようにしなさい。
	{
		year = 0;   month = 0;   day = 0;   income = 0;   expenses = 0;
		System.out.printf("\n＜インスタンス変数を初期化しました。＞\n");
	}

    public Kakeibo_1(int y, int m, int d, int inco, int expe){
        this();
        year = y;
        month = m;
        day = d;
        if(inco >= 0 && expe >= 0){
            income = inco;
            expenses = expe;
            savings += income - expenses;
            System.out.println("＜正常に入出金処理出来ました＞");
        }else{
            System.out.println(" ***** エラー：入力した金額は無効です。 *****");
        }
    }

    public static void showSavings(){
        System.out.printf("貯金  "+ savings + "円");
    }

	public void showData()
	{
		System.out.printf("%04d年 %02d月 %02d日: 収入%7d円   支出%7d円", year, month, day, income, expenses);
	}
}

class Kadai10_3
{
	public static void main(String args[])
	{

		//Kakeibo_1 kakei1 = new Kakeibo_1();		kakei1.showData();				//この行をコメントにしなさい
		
		
		Kakeibo_1 kakei2 = new Kakeibo_1(2022, 11, 27,  5000,  1500);		kakei2.showData();	Kakeibo_1.showSavings();
		Kakeibo_1 kakei3 = new Kakeibo_1(2022, 11, 28,     0, -2500);		kakei3.showData();	Kakeibo_1.showSavings();
		Kakeibo_1 kakei4 = new Kakeibo_1(2022, 11, 30,     0,  2500);		kakei4.showData();	Kakeibo_1.showSavings();
		Kakeibo_1 kakei5 = new Kakeibo_1(2022, 12,  1, -3000,   500);		kakei5.showData();	Kakeibo_1.showSavings();
		Kakeibo_1 kakei6 = new Kakeibo_1(2022, 12,  2,  3000,   500);		kakei6.showData();	Kakeibo_1.showSavings();
		
		
	}
}

