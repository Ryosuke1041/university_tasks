// 学籍番号：22H062，氏名：中江亮介，課題番号：課題12_3

class Human1{
    private String name;
    private double height, weight;

    private Human1(){
        name = "NO name";
        height = 0;
        weight = 0;
    }

    public Human1(String n, double h, double w){
        name = n;
        height = h;
        weight = w;
    }

    public void printInfo(){
        System.out.println("名前：" + name + ", 身長：" + height + "cm, 体重：" + weight + "kg");
	}

    public boolean compSmData(Human1 h, int n) {
        if (n == 1) {
            return this.height < h.height;
        } else if (n == 2) {
            return this.weight < h.weight;
        } else {
            return false;
        }
    }
}

class Kadai12_3
{
    public static void main(String[] args){
		Human1[] member;
		member = new Human1[3];
		member[0] = new Human1("Taro", 160.5, 62.3);
		member[1] = new Human1("Jiro", 185.3, 71.8);
		member[2] = new Human1("Hanako", 168.3, 52.8);
		
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