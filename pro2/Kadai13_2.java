class Student{
    public String name, number;

    public Student(){
        name = "No name";
		number = "00H000";
    }
}
	
class Score extends Student{
	public int math;
	public int english;
	
	public Score(){
		math = 0;
		english = 0;
	}
}

class Kadai13_2
{
    public static void main(String[] args){
        Score member1;
        member1 = new Score();

        System.out.println("学籍番号:" + member1.number + ", 名前:" + member1.name + ", 数学:" + member1.math + ", 英語:" + member1.english);

		member1.number = "22H777";
        member1.name = "Taro";
        member1.math = 70;
        member1.english = 80;

        System.out.println("学籍番号:" + member1.number + ", 名前:" + member1.name + ", 数学:" + member1.math + ", 英語:" + member1.english);
    }
}