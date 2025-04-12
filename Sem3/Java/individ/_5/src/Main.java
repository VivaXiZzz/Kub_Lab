import java.util.ArrayList;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {
        Note s = new Note ("a","23","40");
        Note d = new Note ("b","13","28");
        Note b = new Note ("c","54","10");
        ArrayList<Note> a = new ArrayList<>();
        a.add(s);a.add(d);
        NoteBook nb= new NoteBook(a);
        nb.print();
        System.out.println();
        nb.add(b);
        nb.print();
        System.out.println();
        nb.sortByField("num");
        nb.print();
        nb.remove(s);
        System.out.println();
        nb.print();
        }
    }