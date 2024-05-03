// 学籍番号：22H062，氏名：中江亮介，課題番号：課題14_4

interface iPerson {
    void setPerData(int type, double value);
    void showPerData();
}

interface iSchool {
    int UNIV = 4;
    int HIGH = 3;
    int JUNI = 3;
    int ELEM = 6;
    int ENT = 7;

    String getSchool(int year);
    int getScYear(int year);
}

interface iUniv extends iSchool {
    void showUnivData();
}

class Student implements iPerson, iUniv {
    private String name;
    private double height, weight;
    private int bYear;
    private String uName;
    private String gakubu;

    public Student(String name, double height, double weight, int bYear, String uName, String gakubu) {
        this.name = name;
        this.height = height;
        this.weight = weight;
        this.bYear = bYear;
        this.uName = uName;
        this.gakubu = gakubu;
    }

    public void setPerData(int type, double value) {
        if (type == 0) {
            height = value;
        } else if (type == 1) {
            weight = value;
        } else if (type == 2) {
            bYear = (int) value;
        }
    }

    public void showPerData() {
        System.out.println("名前： " + name + ", 身長： " + height + " cm, 体重：" + weight + "kg, 生まれた年：" + bYear + " 年");
    }

    public String getSchool(int year) {
        int age = year - bYear;
        if (age < ENT) {
            return "未入学";
        } else if (age < ELEM + ENT) {
            return "小学校";
        } else if (age < ELEM + JUNI + ENT) {
            return "中学校";
        } else if (age < ELEM + JUNI + HIGH + ENT) {
            return "高校";
        } else if (age < ELEM + JUNI + HIGH + UNIV + ENT) {
            return "大学";
        } else {
            return "社会人";
        }
    }

    public int getScYear(int year) {
        int age = year - bYear;
        if (age < ENT) {
            return -1;
        } else if (age < ELEM + ENT) {
            return age - ENT + 1;
        } else if (age < ELEM + JUNI + ENT) {
            return age - ELEM - ENT + 1;
        } else if (age < ELEM + JUNI + HIGH + ENT) {
            return age - ELEM - JUNI - ENT + 1;
        } else if (age < ELEM + JUNI + HIGH + UNIV + ENT) {
            return age - ELEM - JUNI - HIGH - ENT + 1;
        } else {
            return -1;
        }
    }

    public void showUnivData() {
        System.out.println("所属：" + uName + "/" + gakubu);
    }
}

class Kadai14_4 {
    public static void main(String[] args) {
        int year = 2023;

        Student student = new Student("Taro", 185.7, 82.6, 2003, "大阪産業大学", "デザイン工学部");

        student.showPerData();

        System.out.println("西暦 " + year + " 年のとき、" + student.getSchool(year) + " " + student.getScYear(year) + " 年生");

        student.setPerData(2, 2013);

        student.showPerData();

        System.out.println("西暦 " + year + " 年のとき、" + student.getSchool(year) + " " + student.getScYear(year) + " 年生");

        if (student.getSchool(year).equals("大学")) {
            student.showUnivData();
        }
    }
}