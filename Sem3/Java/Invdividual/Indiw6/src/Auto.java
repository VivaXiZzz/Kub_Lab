public class Auto
{
    private String marka, nomer;
    private int probeg, price, year, obyom;

    public Auto(String nomer, String marka, int probeg, int price, int year, int obyom)
    {
        this.nomer = nomer;
        this.marka = marka;
        this.probeg = probeg;
        this.year = year;
        this.price = price;
        this.obyom = obyom;
    }

    @Override
    public String toString()
    {
        return "номер: " + nomer + ", марка: " + marka + ", пробег: " + probeg + ", цена: " + price
            + ", год выпуска: " + year + ", объём двигателя: " + obyom + "\n";
    }

    public String getMarka() { return marka; }
    public String getNomer() { return nomer; }
    public int getProbeg() { return probeg; }
    public int getYear() { return year; }
    public int getPrice() { return price; }
    public int getObyom() { return obyom; }

    public void setMarka(String marka) { this.marka = marka; }
    public void setNomer(String nomer) { this.nomer = nomer; }
    public void setProbeg(int probeg) { this.probeg = probeg; }
    public void setYear(int year) { this.year = year; }
    public void setPrice(int price) { this.price = price; }
    public void setObyom(int obyom) { this.obyom = obyom; }
}
