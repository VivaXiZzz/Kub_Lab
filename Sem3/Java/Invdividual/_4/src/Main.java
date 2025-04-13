public class Main{
    public static void main(String[] args) throws FigureException{
        Point[]P=new Point[5];
        P[0] = new Point(0,0);
        P[1] = new Point(0,1);
        P[2] = new Point(4,4);
        P[3]= new Point(5,4);
        P[4] = new Point(5,0);
        Point[]Q1=new Point[4];
        Q1[0] = new Point(999,999);
        Q1[1] = new Point(999,1001);
        Q1[2] = new Point(1001,1001);
        Q1[3] = new Point(1001,999);
        Point[]Q2=new Point[4];
        Q2[0] = new Point(-1,-1);
        Q2[1] = new Point(-1,1);
        Q2[2] = new Point(1,1);
        Q2[3] = new Point(1,-1);
        Pentagon pg = new Pentagon("pq",P);
        Quad sq1 = new Quad("sq1",Q1);
        Quad sq2 = new Quad("sq2",Q2);

        MeToads<Pentagon, Quad> meToads = new MeToads<>();
        boolean isIntersect1 = meToads.isIntersect(pg,sq1);
        boolean isIntersect2 = meToads.isIntersect(pg,sq2);
        System.out.println("пересекаются ли фигуры? pg sq1 " + isIntersect1);
        System.out.println("пересекаются ли фигуры? pg sq2 " + isIntersect2);

    }
}