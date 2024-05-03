// 学籍番号：22H062，氏名：中江亮介，課題番号：課題13_3


class Student {
    protected String name, number;

    public Student(String number, String name) {
        this.number = number;
        this.name = name;
    }

    protected Student() {
        name = "No name";
        number = "00H000";
    }

    public String toString() {
        return "学籍番号:" + number + ", 名前:" + name;
    }
}

class Score extends Student {
    private int math;
    private int english;

    public Score(String number, String name, int math, int english) {
        super(number, name);
        this.math = math;
        this.english = english;
    }

    private Score() {
        math = 0;
        english = 0;
    }

    public String toString() {
        return super.toString() + ", 数学:" + math + ", 英語:" + english;
    }
}

class Kadai13_3 {
    public static void main(String[] args) {
        Score member = new Score("22H777", "Taro", 70, 80);

        System.out.println(member.toString());
    }
}