class Measurement_3 {
    private String name; // 名前
    private int age; // 年齢
    private double height; // 身長
    private double weight; // 体重
    private double waist; // 腹囲
    private double standardWeight; // 標準体重
    private double bmi; // ＢＭＩ

    public void show(String na, int ag, double he, double we, double wa) {
        if ((check(ag) == 0) && (check(he) == 0) && (check(we) == 0)) {
            name = na;
            age = ag;
            height = he;
            weight = we;
            waist = wa;
            calculate();
            System.out.printf("\n 名前： %s    年齢： %d 歳    身長： %.2f cm    体重： %.2f kg    腹囲： %.2f cm\n",
                    name, age, height, weight, waist);
            System.out.printf("    標準体重は %8.3f kg です。\n", standardWeight);
            System.out.printf("    (体重―標準体重)は%8.3f kg です。\n", (weight - standardWeight));
            judge();
        } else {
            if (check(ag) == 1) System.out.printf("  ＊＊エラー：年齢：%4d なので判定不可＊＊\n", ag);
            if (check(he) == 1) System.out.printf("  ＊＊エラー：身長：%.2f なので判定不可＊＊\n", he);
            if (check(we) == 1) System.out.printf("  ＊＊エラー：体重：%.2f なので判定不可＊＊\n", we);
        
        }
    }

    private int check(int tmp1) {
        if (tmp1 >= 0 && tmp1 <= 150) return 0;
        else return 1;
    }

    private int check(double tmp) {
        if (tmp >= 0.0 && tmp <=300.0) return 0;
        else return 1;
    }

    private void calculate() {
        standardWeight = 22.0 * (height / 100.0) * (height / 100.0);
    }

    private void judge() {
        bmi = weight / ((height / 100.0) * (height / 100.0));
        System.out.printf("    ＢＭＩ=%.1f", bmi);
        if (bmi < 18.5)
            System.out.printf("  ＊＊＊ 低体重 ＊＊＊\n");
        else if (bmi >= 18.5 && bmi < 25.0)
            System.out.printf("  ＊＊＊普通体重＊＊＊\n");
        else
            System.out.printf("  ＊＊＊  肥満  ＊＊＊\n");
    }
}

class Kadai09_1 {
    public static void main(String[] args) {
        Measurement_3 student1 = new Measurement_3();
        Measurement_3 student2 = new Measurement_3();
        Measurement_3 student3 = new Measurement_3();
        String name;
        int age;
        double height, weight, waist;

        System.out.println("\n学生:student1");
		name = "Kishida";  age = 222;  height = 170.2;  weight = 50.2;  waist = 80.2;
		student1.show(name, age, height, weight, waist);
		name = "Kishida";  age = 22;  height = 170.2;  weight = 50.2;  waist = 80.2;
		student1.show(name, age, height, weight, waist);
		
		System.out.println("\n学生:student2");
		name = "Matsuno";  age = 19;  height = 1173.3;  weight = -63.3;  waist = 93.3;
		student2.show(name, age, height, weight, waist);
		name = "Matsuno";  age = 19;  height = 173.3;  weight = 63.3;  waist = 93.3;
		student1.show(name, age, height, weight, waist);
		
		System.out.println("\n学生:student3");
		name = "Suzuki";  age = -20;  height = -161.1;  weight = 71.1;  waist = 51.1;
		student3.show(name, age, height, weight, waist);
		name = "Suzuki";  age = 20;  height = 161.1;  weight = 71.1;  waist = 51.1;
		student3.show(name, age, height, weight, waist);

    }
}