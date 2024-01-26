class Kadai15_1
{
	public static void main(String args[])
	{
		System.out.println("		2023 ”N 12 Œ");
		System.out.println("“ú	Œ	‰Î	…	–Ø	‹à	“y");
		
		for(int i = 1; i <= 31; i++){
			if(i == 1){
				System.out.printf("					" + i + "\t");
			}else{
				if(i % 7 == 2){
					System.out.println(i);
				}else{
					System.out.print(i + "\t");
				}
			}
		}
	}
	
}