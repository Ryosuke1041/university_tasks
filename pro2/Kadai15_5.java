class Kakeibo
{
	private static int savings = 0;	// ’™‹à
	private int income; 	// û“ü
	private int expenses;	// xo
	
	private Kakeibo(){
		savings = 0;
		income = 0;
		expenses = 0;
	}
	
	public void Kakeibo(int inco, int expe){
		if(inco < 0 || expe < 0){
			System.out.println("***** ƒGƒ‰[F“ü—Í‚µ‚½‹àŠz‚Í–³Œø‚Å‚·B *****");
		}else{
			income = inco;
			expenses = expe;
			savings += income - expenses;
		}
		
	}
	
	public void showData()
	{
		System.out.printf("û“ü %7d‰~ xo %7d‰~\n", income, expenses);
	}

	public static void showSavings()
	{
		System.out.printf("’™‹à  : %7d ‰~\n", savings);
	}
}


class Kadai15_5
{
	public static void main(String args[])
	{
		Kakeibo kakei1 = new Kakeibo(5000,  1500);		kakei1.showData();	Kakeibo.showSavings();
		Kakeibo kakei2 = new Kakeibo(   0, -2500);		kakei2.showData();	Kakeibo.showSavings();
		Kakeibo kakei3 = new Kakeibo(   0,  2500);		kakei3.showData();	Kakeibo.showSavings();
		Kakeibo kakei4 = new Kakeibo(-3000,  500);		kakei4.showData();	Kakeibo.showSavings();
		Kakeibo kakei5 = new Kakeibo(3000,   500);		kakei5.showData();	Kakeibo.showSavings();
		
	}
}

