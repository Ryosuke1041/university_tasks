 Person
{
	protected String name;
	protected double height, weight;
	
	 void ;
}

class Student Person
{
	private String number;
	
	public Student(String num, String nam, double ht, double wt)
	{
		number = num;
		name = nam;
		height = ht;
		weight = wt;
	}
	
	public  
	{
		System.out.println("学籍番号: " + number + ", 名前： " + name +  ", 身長： " + height + "cm, 体重："+ weight + "kg");
	}
}

class Teacher  Person
{
	private String affiliation;
	private String[] subjects = new String[3];

	public Teacher(String aff, String na, double ht, double wt, String[] subs)
	{
		affiliation = aff;
		name = na;
		height = ht;
		weight = wt;
		subjects = ;
	}

	public  
	{
		System.out.println("所属："+affiliation+", 名前： " + name + ", 身長： " + height+ "cm, 体重："+ weight + "kg");
		System.out.println("担当科目："+subjects[0]+", "+subjects[1]+", "+subjects[2]+", ");
	}
}



class Toi14_4
{
	public static void main(String[] args)
	{
		Person[] members = new Person[2];
		
		members[0] = new ("77H777","taro",185.7,82.6);
		String[] strs = ;
		members[1] = new ("産大","Ichiro", 180.0, 75.0, );
		
		
		for(int i=0; i<members.length; i++){
			members[i].;
			if(members[i] ) System.out.println("Studentクラスです");
			else System.out.println("Studentクラスではありません");
			System.out.println();
		}
	}
}

