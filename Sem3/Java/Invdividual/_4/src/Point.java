public class Point
{
    protected int x, y;

    public Point(int x, int y)
    {
        this.x = x;
        this.y = y;
    }

    public int getX() { return x; }
    public int getY() { return y; }

    public void setX(int x) { this.x = x; }
    public void setY(int y) { this.y = y; }

    double pSize(Point p1){return (p1.getX()-x)*(p1.getX()-x)+(p1.getY()-y)*(p1.getY()-y);}
    @Override
    public String toString() { return "(" + x + "; " + y + ")"; }
}
