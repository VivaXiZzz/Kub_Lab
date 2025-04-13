public class Integer implements Number <Integer> {
    Integer a;
    public Integer(Integer a) {
        this.a=a;
    }

    public Integer getA() {
        return a;
    }

    public void setA(Integer a) {
        this.a = a;
    }

    @Override
    public Integer sum(Integer a1, Integer a2) {
        Integer a=new Integer(a1,a2);
    }
}
