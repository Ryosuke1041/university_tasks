
class Human{
    private String name;
    private double height, weight;

    private Human(){
        name = "NO name";
        height = 0;
        weight = 0;
    }

    public Human(String n, double h, double w){
        name = n;
        height = h;
        weight = w;
    }

    public void printInfo(){
        System.out.println("名前：" + name + ", 身長：" + height + "cm, 体重：" + weight + "kg");
	}
}

class Kadai12_1
{
    public static void main(String[] args){
		Human[] member;
		member = new Human[3];
		member[0] = new Human("Taro", 160.5, 62.3);
		member[1] = new Human("Jiro", 185.3, 71.8);
		member[2] = new Human("Hanako", 168.3, 52.8);
		
        for (int i = 0; i < member.length; i++) {
            member[i].printInfo();
        }
    }
}