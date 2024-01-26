class Figure
{
	double width, height, square;
	
	public double getArea(){
		square = width * height;
        return square;
	}
	
	public void setLength(double w, double h)
    { 
        width = w;
        height = h;
        System.out.printf(" 横：%.1f 縦：%.1f", width, height);
    } 
}

class Kadai15_4
{ 
    public static void main(String[] args)
    { 
        Figure fig1 = new Figure();  
        double width = 10.0;
        double height = 40.0;
        
        System.out.printf("図形の面積を求めます。\n"); 
        fig1.setLength(width, height); 
        System.out.printf(" 面積は %.1f です。\n", fig1.getArea()); 
    } 
} 