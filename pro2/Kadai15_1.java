class Kadai15_1
{
	public static void main(String args[])
	{
		System.out.println("		2023 年 12 月");
		System.out.println("日	月	火	水	木	金	土");
		
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