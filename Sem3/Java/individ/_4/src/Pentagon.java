public class Pentagon extends Figure {
    public Pentagon(String id,Point[]p) throws FigureException {
        super(id,p);
        int n = p.length;
        if(n!=5) throw new FigureException("Неверное число вершин пятиугольника: " + n);
        /*Vector AB = new Vector(p[1].x-p[0].x,p[1].y-p[0].y,0);
        Vector BC = new Vector(p[2].x-p[1].x,p[2].y-p[1].y,0);
        Vector CD = new Vector(p[3].x-p[2].x,p[3].y-p[2].y,0);
        Vector DF = new Vector(p[4].x-p[3].x,p[4].y-p[3].y,0);
        Vector FA = new Vector(p[0].x-p[4].x,p[0].y-p[4].y,0);*/
        if(p[0]==p[1]||p[0]==p[2]||p[0]==p[3]||p[0]==p[4]||p[1]==p[2]||p[1]==p[3]||p[1]==p[4]||p[2]==p[3]||p[2]==p[4]||p[3]==p[4])throw new FigureException("Точки совпали это не пятиугольник");
    }
    public String toString() {return "Pentagon: " + super.toString();}
}
