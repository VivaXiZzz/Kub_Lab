public class MeToads <T1 extends Figure,T2 extends Figure>{
    private boolean isPeresPr(Point A, Point B, Point C, Point D)
    {
        Vector AB = new Vector(B.x-A.x, B.y-A.y, 0);
        Vector AC = new Vector(C.x-A.x, C.y-A.y, 0);
        Vector AD = new Vector(D.x-A.x, D.y-A.y, 0);
        Vector ABxAC = AB.proiz(AC);
        Vector ABxAD = AB.proiz(AD);

        Vector CD = new Vector(D.x-C.x, D.y-C.y, 0);
        Vector CA = new Vector(A.x-C.x, A.y-C.y, 0);
        Vector CB = new Vector(B.x-C.x, B.y-C.y, 0);
        Vector CDxCA = CD.proiz(CA);
        Vector CDxCB = CD.proiz(CB);

        return (ABxAC.getZ() * ABxAD.getZ() <= 0) && (CDxCA.getZ() * CDxCB.getZ() <= 0);
    }
    boolean isIntersect(T1 t1, T2 t2)
    {
        int n = t1.p.length, m = t2.p.length;
        for(int i=0; i<n-1; ++i)
            for(int j=0; j<m-1; ++j)
                if(isPeresPr(t1.p[i], t1.p[i+1], t2.p[j], t2.p[j+1])) return true;

        for(int j=0; j<m-1; ++j)
            if(isPeresPr(t1.p[n-1], t1.p[0], t2.p[j], t2.p[j+1])) return true;

        for(int i=0; i<n-1; ++i)
            if(isPeresPr(t1.p[i], t1.p[i+1], t2.p[m-1], t2.p[0])) return true;

        return isPeresPr(t1.p[n-1], t1.p[0], t2.p[m-1], t2.p[0]);
    }
}