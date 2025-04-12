public class Vector
{
    int x, y, z;

    public Vector(int x, int y, int z)
    {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    Vector proiz(Vector v)
    {
        return new Vector(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x);
    }

    public int getX() {return x;}
    public int getY() {
        return y;
    }
    public int getZ() {
        return z;
    }

    public void setX(int x) {
        this.x = x;
    }
    public void setY(int y) {
        this.y = y;
    }
    public void setZ(int z) {
        this.z = z;
    }
}
