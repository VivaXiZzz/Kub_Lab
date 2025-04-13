import static java.lang.Math.sqrt;

public class Square extends Rectangle{
    double line;

    public Square(double[] c1, double[] c2, double[] c3, double[] c4) {
        super(c1, c2, c3, c4);
        this.line = sqrt((super.getC3()[0] - super.getC2()[0]) * (super.getC3()[0] - super.getC2()[0]) + (super.getC3()[1] - super.getC2()[1])*(super.getC3()[1] - super.getC2()[1]));
    }

    public double getLine() {
        return line;
    }

    public void setLine(double line) {
        this.line = line;
    }

    @Override
    public double Ploshad()
    {
        return line*line;
    }
    public double R_In_Circle()
    {
        return line*0.5;
    }
    public double R_Out_Circle()
    {
        return line* sqrt(2)*0.5;
    }
}
