import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        double[]arr1=new double[2];
        double[]arr2=new double[2];
        double[]arr3=new double[2];
        double[]arr4=new double[2];
        System.out.println("Введите координаты четырехугольника x,y для каждой из 4 точек поочередно как хотели бы видеть на графике");
        for(int i=0;i<2;++i)arr1[i]= sc.nextDouble();
        for(int i=0;i<2;++i)arr2[i]= sc.nextDouble();
        for(int i=0;i<2;++i)arr3[i]= sc.nextDouble();
        for(int i=0;i<2;++i)arr4[i]= sc.nextDouble();
        Quadrilateral q=new Quadrilateral(arr1,arr2,arr3,arr4);
        //Rectangle r=new Rectangle(arr1,arr2,arr3,arr4);
        //Square s=new Square(arr1,arr2,arr3,arr4);
        System.out.println("Площадь четырехугольника:"+q.Ploshad());
        //System.out.println("Площадь прямоугольника:"+r.Ploshad());
        //System.out.println("Площадь квадрата:"+s.Ploshad());
    }
}