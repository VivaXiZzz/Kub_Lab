import java.lang.Math;
public class Vector {
    private int x;
    private int y;
    private int z;
    Vector(int x,int y,int z)
    {
        this.x=x;
        this.y=y;
        this.z=z;
    }

    private int getX()
    {
        return x;
    }
    private void setX(int x)
    {
        this.x=x;
    }

    private int getY()
    {
        return y;
    }
    private void setY(int y)
    {
        this.y=y;
    }

    private int getZ()
    {
        return z;
    }
    private void setZ(int z)
    {
        this.z=z;
    }

    @Override
    public String toString() {
        return "Vector{" +
                "x=" + x +
                ", y=" + y +
                ", z=" + z +
                '}';
    }

    public Vector VecSum(Vector a)
    {
        int bx=x+a.x;
        int by=y+a.y;
        int bz=z+a.z;
        return new Vector(bx,by,bz);
    }

    public Vector VecRazn(Vector a)
    {
        int bx=x-a.x;
        int by=y-a.y;
        int bz=z-a.z;
        return new Vector(bx,by,bz);
    }

    public int ScalarProiz(Vector a)
    {
        return x*a.x+y*a.y+z*a.z;
    }

    public double Length()
    {
        return Math.sqrt(x*x+y*y+z*z);
    }

    public double CosAB(Vector a)
    {
        return (x*a.x+y*a.y+z*a.z)/(Math.sqrt(x*x+y*y+z*z)*Math.sqrt(a.x*a.x+a.y*a.y+a.z*a.z));
    }
}
