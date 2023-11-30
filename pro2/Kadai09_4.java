// 学籍番号：22H062，氏名：中江亮介，課題番号：Kadai09_4


class Figure_3
{
	private double width;			//横
	private double height;			//縦
	private double depth;		//不足しているコードを追加しなさい
	private double square;			//面積
	private double volume;		//不足しているコードを追加しなさい

	public int setLength(int w)
	{
		if( w >= 0 ){
			width = (double)w;
			return 0;
		}
		else{
			System.out.printf("*** 横 " +w+ " が不適切なので設定できませんでした。 ***");
			return 1;
		}
	}
	public int setLength(int w, int h)
	{
		if( this.setLength(w) == 0  && h >= 0 ){
			height = (double)h;
			return 0;
		}
		else{
			if( h < 0) System.out.printf("*** 縦 " +h+ " が不適切なので設定できませんでした。 ***");
			return 1;
		}
	}

	public int setLength(int w, int h, int d)
	{
		if( this.setLength(w) == 0  && h >= 0 && d >= 0){
			depth = (double)d;
			return 0;
		}
		else{
			if( d < 0) System.out.printf("*** 奥行 " +d+ "  が不適切なので設定できませんでした。 ***");
			return 1;
		}
	}		//不足しているコードを追加しなさい

	public double getArea() {			//面積を計算
		square = width * height;
		return square;
	}

	public double getVolume(){
		volume = getArea() * depth;
		return volume;
	}		//不足しているコードを追加しなさい
}

class Kadai09_4
{
	public static void main(String[] args)
	{
		Figure_3 fig = new Figure_3();
		int i;
		int w[] = { -10,  10,  10,  10};
		int h[] = {  20, -20,  20,  20};
		int d[] = { 30, 30, -30, 30};	//不足箇所を追加しなさい

		for ( i = 0 ; i <w.length ; i++ ) {
			System.out.printf("\n %2dつ目の図形の面積を求めます。\n", i+1);
			if(fig.setLength(w[i], h[i]) == 0){
				System.out.printf("面積は%.2fです。",fig.getArea());
			}
			System.out.printf("\n %2dつ目の図形の体積を求めます。\n", i+1);
			if(fig.setLength(w[i], h[i]) == 0 && fig.setLength(w[i], h[i], d[i]) == 0){
				System.out.printf("体積は%.2fです。",fig.getVolume());
			}//不足箇所を追加しなさい
			System.out.printf("\n");
		}
	}
}

