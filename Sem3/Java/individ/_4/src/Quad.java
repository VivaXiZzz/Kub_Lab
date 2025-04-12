public class Quad extends Figure {

    public Quad(String id,Point[]p) throws FigureException {
        super(id,p);
        int n=p.length;
        if(n!=4) throw new FigureException("Неверное число вершин квадрата: "+n);
        /*Vector AB = new Vector(p[1].x - p[0].x, p[1].y - p[0].y, 0);
        Vector AC = new Vector(p[2].x - p[0].x, p[2].y - p[0].y, 0);
        Vector AD = new Vector(p[3].x - p[0].x, p[3].y - p[0].y, 0);
        Vector BC = new Vector(p[2].x - p[1].x, p[2].y - p[1].y, 0);
        Vector BD = new Vector(p[3].x - p[1].x, p[3].y - p[1].y, 0);
        Vector ABxAC = AB.proiz(AC);
        Vector ABxAD = AB.proiz(AD);
        Vector ACxAD = AC.proiz(AD);
        Vector BCxBD = BC.proiz(BD);*/

        boolean f=false;
        double side1 = p[0].pSize(p[1]);
        double side2 = p[1].pSize(p[2]);
        double side3 = p[2].pSize(p[3]);
        double side4 = p[3].pSize(p[0]);

        if (side1 == side2 && side2 == side3 && side3 == side4) {
            double d1 = p[1].pSize(p[3]);
            double d2 = p[0].pSize(p[2]);
            if(d1==d2)f=true;
        }
        if(/*ABxAC.getZ() * ABxAD.getZ() * ACxAD.getZ() * BCxBD.getZ() == 0||*/!f)
            throw new FigureException("Некорректные координаты вершин квадрата: " + super.toString());
        }
        public String toString() {return "Quad: " + super.toString();}
}
