interface iPerson{
    void setPerData(int type, double value);
    void showPerData();
}

class Student implements iPerson{
    private String name;
    private double height, weight;

    public Student(String name, double height, double weight){
        this.name = name;
        this.height = height;
        this.weight = weight;
    }

    public void setPerData(int type, double value){
        if (type == 0) {
            height = value;
        } else if (type == 1) {
            weight = value;
        }
    }

    public void showPerData(){
        System.out.println("名前： " + name + ", 身長： " + height + " cm, 体重：" + weight + "kg");
    }
}

class Kadai14_2{
    public static void main(String[] args){
        Student student = new Student("Taro", 185.7, 82.6);

        student.showPerData();

        student.setPerData(0, 162.3);
        student.setPerData(1, 55.6);

        student.showPerData();
    }
}