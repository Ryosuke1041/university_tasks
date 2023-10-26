// 学籍番号：22H062，氏名：中江亮介，課題番号：Kadai05_2


import java.io.*;

class Kadai05_1 {
	public static void main(String[] args) throws IOException {
		System.out.println("整数を , 区切りで入力してください");

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		String[] array = str.split(",");

		int num = array.length; // 入力された値の個数

		int[] data = new int[num];
		int[][] test = { { 10, 20, 30 }, { 111, 222, 333, 444 } };
		int[][] result = new int[3][];
		int[] sum = new int[3];

		result[0] = data;
		result[1] = test[0];
		result[2] = test[1];

		for (int i = 0; i < num; i++) {
			data[i] = Integer.parseInt(array[i]);
		}

		test[0] = data;
		data[0] = 99;

		System.out.print("入力した値は ");

		for (int i = 0; i < num; i++) {
			System.out.print(data[i] + " ");
			sum[0] += data[i];
		}
		System.out.println();

		for (int i = 0; i < test.length; i++) {
			for (int j = 0; j < test[i].length; j++) {
				System.out.print(test[i][j] + " ");
				sum[1] += test[i][j];
			}
		}
		System.out.println();

		for (int[] i : result) { // for(int i=0;i<result.length;i++){
			for (int j : i) { // for(int j=0;j<i.length;j++){
				System.out.print(j + " "); // System.out.println(i[j]+" ");
				sum[2] += j;
			}
			System.out.println();
		}

		System.out.printf("合計\tdata\ttest\tresult\n");
		System.out.printf(" \t");
		for (int i = 0; i < sum.length; i++) {
			System.out.printf("%d\t", sum[i]);
		}
		System.out.println();

	}
}