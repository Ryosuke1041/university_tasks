class Student{
    public String name, number;

    public Student(){
        name = "No name";
		number = "00H000";
    }
}
	
class Score{
	public int math;
	public int english;
	
	public Score(){
		math = 0;
		english = 0;
	}
}

class Kadai13_1
{
    public static void main(String[] args){
		Student person;
		person = new Student();
		Score data;
		data = new Score();
		
		System.out.println("学籍番号:" + person.name + "名前:" + person.number);
		System.out.println("数学:" + data.math + "英語:" + data.english);
    }
}
