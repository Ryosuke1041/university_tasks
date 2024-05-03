// 学籍番号：22H062，氏名：中江亮介，課題番号：課題12_3

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

    public boolean compSmData(Human h, int n) {
        if (n == 1) {
            return this.height < h.height;
        } else if (n == 2) {
            return this.weight < h.weight;
        } else {
            return false;
        }
    }
}

class Kadai12_4
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

        if (member[0].compSmData(member[2], 1)) {
            System.out.println("身長が高いのは");
            member[2].printInfo();
        } else {
            System.out.println("身長が高いのは");
            member[0].printInfo();
        }

        
    }
}