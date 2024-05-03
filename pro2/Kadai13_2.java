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
        Score member;
        member = new Score();

        System.out.println("学籍番号:" + member.number + ", 名前:" + member.name + ", 数学:" + member.math + ", 英語:" + member.english);

		member.number = "22H777";
        member.name = "Taro";
        member.math = 70;
        member.english = 80;

        System.out.println("学籍番号:" + member.number + ", 名前:" + member.name + ", 数学:" + member.math + ", 英語:" + member.english);
    }
}