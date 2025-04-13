public class Note {
    private String name;
    private String num;
    private String yo;

    public Note(String name, String num, String yo) {
        this.name = name;
        this.num = num;
        this.yo = yo;
    }
    public String getName() {return name;}
    public void setName(String name) {this.name = name;}
    public String getNum() {return num;}
    public void setNum(String num) {this.num = num;}
    public String getYo() {return yo;}
    public void setYo(String yo) {this.yo = yo;}

    public boolean include(String attribute)
    {return this.name.contains(attribute)||this.num.contains(attribute)||this.yo.contains(attribute);}
}
