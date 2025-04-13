public class Integer implements Number {
    private int value;

    public Integer(int value) {
        this.value = value;
    }

    public Number sum(Number num) {
        int result = this.value + ((Integer)num).value;
        return new Integer(result);
    }

    public Number razn(Number num) {
        int result = this.value - ((Integer)num).value;
        return new Integer(result);
    }

    public Number umn(Number num) {
        int result = this.value * ((Integer)num).value;
        return new Integer(result);
    }

    public Number del(Number num) {
        int result = this.value / ((Integer)num).value;
        return new Integer(result);
    }

    public String toval() {
        return ""+value;
    }
}
