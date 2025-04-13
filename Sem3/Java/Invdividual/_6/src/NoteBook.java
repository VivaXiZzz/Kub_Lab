import java.util.ArrayList;

public class NoteBook {
    private ArrayList<Note> notes;
    public NoteBook(ArrayList<Note> notes) {this.notes = notes;}

    public ArrayList<Note> getNotes() {return notes;}
    public void setNotes(ArrayList<Note> notes) {this.notes = notes;}

    public void add(Note noted){
        this.notes.add(noted);
    }

    public void remove(Note noted){
        this.notes.remove(noted);
    }

    public ArrayList<Note> findNoteByAttribute(String attribute) {
        ArrayList<Note> finded = new ArrayList<>();
        for(Note a:this.notes) {
            if(a.include(attribute)){finded.add(a);}
        }
        return finded;
    }

    public void sortByField(String field) {
        if (field.equals("name")){
            for(int i=0;i<this.notes.size()-1;++i){
                for(int j=0;j<this.notes.size()-i-1;++j){
                    if(this.notes.get(j).getName().compareTo(this.notes.get(j+1).getName())>0){
                        Note temp = this.notes.get(j);
                        this.notes.set(j,this.notes.get(j+1));
                        this.notes.set(j+1,temp);
                    }
                }
            }
        }
        if (field.equals("num")){
            for(int i=0;i<this.notes.size()-1;++i){
                for(int j=0;j<this.notes.size()-i-1;++j){
                    if(this.notes.get(j).getNum().compareTo(this.notes.get(j+1).getNum())>0){
                        Note temp = this.notes.get(j);
                        this.notes.set(j,this.notes.get(j+1));
                        this.notes.set(j+1,temp);
                    }
                }
            }
        }
        if (field.equals("yo")){
            for(int i=0;i<this.notes.size()-1;++i){
                for(int j=0;j<this.notes.size()-i-1;++j){
                    if(this.notes.get(j).getYo().compareTo(this.notes.get(j+1).getYo())>0){
                        Note temp = this.notes.get(j);
                        this.notes.set(j,this.notes.get(j+1));
                        this.notes.set(j+1,temp);
                    }
                }
            }
        }
    }
    public String tryString(int n) {
        return notes.get(n).getName() + " " + " " + notes.get(n).getNum() + " " + " " + notes.get(n).getYo();
    }

    public void print() {
        for(int i=0;i<notes.size();++i)
            System.out.println("Note:{"+tryString(i)+"}");
    }
}
