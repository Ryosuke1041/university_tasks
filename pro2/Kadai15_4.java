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
        System.out.printf(" ���F%.1f �c�F%.1f", width, height);
    } 
}

class Kadai15_4
{ 
    public static void main(String[] args)
    { 
        Figure fig1 = new Figure();  
        double width = 10.0;
        double height = 40.0;
        
        System.out.printf("�}�`�̖ʐς����߂܂��B\n"); 
        fig1.setLength(width, height); 
        System.out.printf(" �ʐς� %.1f �ł��B\n", fig1.getArea()); 
    } 
} 