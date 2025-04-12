import java.util.Arrays;
import java.lang.Math;

import static java.lang.Math.pow;
import static java.lang.Math.sqrt;

public class Quadrilateral {
    private double[] c1;
    private double[] c2;
    private double[] c3;
    private double[] c4;

    Quadrilateral(double[] c1, double[] c2, double[] c3, double[] c4) {
        this.c1 = c1;
        this.c2 = c2;
        this.c3 = c3;
        this.c4 = c4;
    }

    public double[] getC1() {
        return c1;
    }

    public void setC1(double[] c1) {
        this.c1 = c1;
    }

    public double[] getC2() {
        return c2;
    }

    public void setC2(double[] c2) {
        this.c2 = c2;
    }

    public double[] getC3() {
        return c3;
    }

    public void setC3(double[] c3) {
        this.c3 = c3;
    }

    public double[] getC4() {
        return c4;
    }

    public void setC4(double[] c4) {
        this.c4 = c4;
    }

    @Override
    public String toString() {
        return "Quadrilateral{" +
                "c1=" + Arrays.toString(c1) +
                ", c2=" + Arrays.toString(c2) +
                ", c3=" + Arrays.toString(c3) +
                ", c4=" + Arrays.toString(c4) +
                '}';
    }

    public double[] Lines() {
        double[] a = new double[4];
        a[0] = sqrt((c2[0] - c1[0]) * (c2[0] - c1[0]) + (c2[1] - c1[1]) * (c2[1] - c1[1]));
        a[1] = sqrt((c3[0] - c2[0]) * (c3[0] - c2[0]) + (c3[1] - c2[1]) * (c3[1] - c2[1]));
        a[2] = sqrt((c4[0] - c3[0]) * (c4[0] - c3[0]) + (c4[1] - c3[1]) * (c4[1] - c3[1]));
        a[3] = sqrt((c1[0] - c4[0]) * (c1[0] - c4[0]) + (c1[1] - c4[1]) * (c1[1] - c4[1]));
        return a;
    }

    private double Perimetr() {
        double[] a = Lines();
        double sum = 0;
        for (int i = 0; i < 4; ++i) {
            sum += a[i];
        }
        return sum;
    }

    public double Ploshad()
    {
        //return c1[0]*c4[0]+c1[1]*c4[1]+c2[0]*c1[0]+c2[1]*c1[1]+c3[0]*c2[0]+c3[1]*c2[1]+c4[0]*c3[0]+c4[1]*c3[1];
        return Math.abs(c1[0]*c4[1]-c1[1]*c4[0]+c2[0]*c1[1]-c2[1]*c1[0]+c3[0]*c2[1]-c3[1]*c2[0]+c4[0]*c3[1]-c4[1]*c3[0])/2;
    }


    public String Vivod()
    {
        return "Периметр и площадь: " + Perimetr() + " " + Ploshad();
    }
}
