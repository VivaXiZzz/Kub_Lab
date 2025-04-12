import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        double c = sc.nextDouble();
        double d = sc.nextDouble();
        Integer ai=new Integer(a);
        Integer bi=new Integer(b);
        Real ci=new Real(c);
        Real di=new Real(d);
        Integer isum= (Integer) ai.sum(bi);
        Integer idel= (Integer) ai.del(bi);
        Real rsum= (Real) ci.sum(di);
        Real rdel= (Real) ci.del(di);
        System.out.println(isum.toval() + " " + idel.toval());
        System.out.println(rsum.toval() + " " + rdel.toval());
    }
}