/**
 * Created by maciek on 06.06.17.
 */


public class Karta extends Kolor{
    //private:
    private int standardowa;
    private KartySpecjalne specjalna;



    //public:
    public Karta(Kolory rodzaj, int nr,KartySpecjalne nazwa) {
        this.Rodzaj=rodzaj;
        this.standardowa=nr;
        this.specjalna=nazwa;
    }

    public String PokazKarte() {
        if (this.standardowa == 0) {

            return this.specjalna.toString() + ' ' + this.Rodzaj;
        }
        else {
            return Integer.toString(this.standardowa) + ' ' + this.Rodzaj;
        }
    }

    public String GetWartosc(){
        switch (this.specjalna) {
            case brak:
                break;
            case As:
                return "As";
            case Krol:
                return "Krol";
            case Dama:
                return "Dama";
            case Walet:
                return "Walet";
        }
        return Integer.toString(this.standardowa);
    }
    public String GetKolor(){
        if (this.Rodzaj==Kolory.Trefl) return "Trefl";
        else if (this.Rodzaj==Kolory.Pik) return "Pik";
        else if (this.Rodzaj==Kolory.Karo) return "Karo";
        else return "Kier";
    }

    public int getStandardowa() {
        return standardowa;
    }

}
