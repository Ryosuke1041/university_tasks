abstract class Person {
    protected String name;
    protected double height;
    protected double weight;

    public abstract void setPerData(int type, double value);

    public void showPerData() {
        System.out.println("名前： " + name + ", 身長： " + height + " cm, 体重：" + weight + "kg");
    }
}

class Student extends Person {
    public Student(String name, double height, double weight) {
        this.name = name;
        this.height = height;
        this.weight = weight;
    }

    public void setPerData(int type, double value) {
        if (type == 0) {
            height = value;
        } else if (type == 1) {
            weight = value;
        }
    }
}

class Kadai14_1 {
    public static void main(String[] args) {
        Student student = new Student("Taro", 185.7, 82.6);

        student.showPerData();

        student.setPerData(0, 162.3);
        student.setPerData(1, 55.6);

        student.showPerData();
    }
}