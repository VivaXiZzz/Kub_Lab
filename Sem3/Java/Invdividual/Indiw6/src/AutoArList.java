import java.util.ArrayList;
import java.util.Comparator;

public class AutoArList
{
    private ArrayList<Auto> a;

    public ArrayList<Auto> getA() { return a; }
    public void setA(ArrayList<Auto> a) { this.a = a; }

    public void add(Auto p)
    {
        if (a == null) a = new ArrayList<Auto>();
        a.add(p);
    }

    public void del(String nomer)
    {
        for(int i=0;i<a.size();++i)
            if(nomer.equalsIgnoreCase(a.get(i).getNomer())) a.remove(a.get(i));
    }

    public String toString()
    {
        String str = "";
        for(int i=0;i<a.size();++i)
            str += a.get(i).toString();
        return str;
    }

    void sortNomer()
    {
        Comparator<Auto> c = (a1, a2) -> a1.getNomer().compareTo(a2.getNomer());
        a.sort(c);
    }

    void sortObyom()
    {
        Comparator<Auto> c = (a1, a2) -> a1.getObyom()- a2.getObyom();
        a.sort(c);
    }


    void sortMarka()
    {
        Comparator<Auto> c = (a1, a2) -> a1.getMarka().compareTo(a2.getMarka());
        a.sort(c);
    }
}
