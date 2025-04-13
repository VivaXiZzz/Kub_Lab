abstract public class Figure {
    Point []p;
    String id;
    Figure(String id,Point[]p)
    {
        this.p=p;
        this.id=id;
    }
    void move(int xx,int yy)
    {
        for(Point cord:p)
        {
            cord.x+=xx;
            cord.y+=yy;
        }
    }
}
