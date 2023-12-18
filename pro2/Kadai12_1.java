
class Human{
    String name;
    double height, weight;

    public Human(){
        name = "NO name";
        height = 0;
        weight = 0;
    }


    public void printInfo(){
        System.out.println("名前：" + name[i] + ", 身長：" + height[i] + "cm, 体重：" + weight[i] + "kg");
    }
}

class Kadai12_1
{
    public static void main(String[] args){
		Human person;
        person = new Human();
        person.printInfo();
        person.name = "Taro";
        person.height = 160.5;
        person.weight = 62.3;
		person.printInfo();
    }
}
