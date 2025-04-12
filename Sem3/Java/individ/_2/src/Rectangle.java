import static java.lang.Math.sqrt;

public class Rectangle extends Quadrilateral {
    final int cos = 1;

    public Rectangle(double[] c1, double[] c2, double[] c3, double[] c4) {
        super(c1, c2, c3, c4);
    }

    public int getCos() {
        return cos;
    }

    @Override
    public double Ploshad()
    {
    return sqrt((super.getC3()[0] - super.getC2()[0]) * (super.getC3()[0] - super.getC2()[0]) + (super.getC3()[1] - super.getC2()[1]) * (super.getC3()[1] - super.getC2()[1]))* sqrt((super.getC2()[0] - super.getC1()[0]) * (super.getC2()[0] - super.getC1()[0]) + (super.getC2()[1] - super.getC1()[1]) * (super.getC2()[1] - super.getC1()[1]));
    }
    public boolean Put_Circle_In()
    {
        return(sqrt((super.getC3()[0] - super.getC2()[0]) * (super.getC3()[0] - super.getC2()[0]) + (super.getC3()[1] - super.getC2()[1]) * (super.getC3()[1] - super.getC2()[1]))== sqrt((super.getC2()[0] - super.getC1()[0]) * (super.getC2()[0] - super.getC1()[0]) + (super.getC2()[1] - super.getC1()[1]) * (super.getC2()[1] - super.getC1()[1])));
    }
}
