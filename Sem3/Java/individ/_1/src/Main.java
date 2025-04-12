import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Введите координаты первого вектора");
        int x1 = sc.nextInt();
        int y1 = sc.nextInt();
        int z1 = sc.nextInt();
        System.out.println("Введите координаты второго вектора");
        int x2 = sc.nextInt();
        int y2 = sc.nextInt();
        int z2 = sc.nextInt();
        Vector a=new Vector(x1,y1,z1);
        Vector b=new Vector(x2,y2,z2);
        Vector c=a.VecSum(b);
        System.out.println("Сумма векторов: " + c.toString());
        c=a.VecRazn(b);
        System.out.println("Разность векторов: " + c.toString());
        System.out.println("Скалярное произведение векторов: " + a.ScalarProiz(b));
        System.out.println("Длина векторов первого и второго соответственно: " + a.Length() + " " + b.Length());
        System.out.println("Косинус между векторами: " + a.CosAB(b));
    }
}