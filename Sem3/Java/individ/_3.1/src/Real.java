public class Real implements Number {
    private double value;

    public Real(double value) {
        this.value = value;
    }

    public Number sum(Number num) {
        double result = this.value + ((Real)num).value;
        return new Real(result);
    }

    public Number razn(Number num) {
        double result = this.value - ((Real)num).value;
        return new Real(result);
    }

    public Number umn(Number num) {
        double result = this.value * ((Real)num).value;
        return new Real(result);
    }

    public Number del(Number num) {
        double result = this.value / ((Real)num).value;
        return new Real(result);
    }

    public String toval() {
        return ""+value;
    }
}
