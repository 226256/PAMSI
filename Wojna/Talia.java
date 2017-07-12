import java.util.Random;

/**
 * Created by maciek on 06.06.17.
 */
public class Talia {
    //private
    private Karta [] mojatalia;
    private int ilosckartwtalii;

    //public:
    public static final int maksilosckart=56;

    public Talia() {
        this.ilosckartwtalii=0;
        Kolory [] dostepneKolory={Kolory.Karo,Kolory.Kier,Kolory.Pik,Kolory.Trefl};
        KartySpecjalne [] dostepneSpecjalne={KartySpecjalne.As,KartySpecjalne.Krol,KartySpecjalne.Dama,KartySpecjalne.Walet};
        this.mojatalia=new Karta[maksilosckart];
        int miejscewtalii=0;
        for(int i=0;i<4;++i){
            for (int j=1;j<11;++j){
                Karta temp=new Karta(dostepneKolory[i],j,KartySpecjalne.brak);
                this.mojatalia[miejscewtalii]=temp;
                ++this.ilosckartwtalii;
                ++miejscewtalii;
            }
            for(int j=0;j<4;++j){
                Karta temp=new Karta(dostepneKolory[i],0,dostepneSpecjalne[j]);
                this.mojatalia[miejscewtalii]=temp;
                ++this.ilosckartwtalii;
                ++miejscewtalii;
            }
        }
    }

    public Talia(int ilosckartwtalii) {
        if(ilosckartwtalii!=0) System.out.println("Nie mozna stworzyc pustej talii");
        else {
            mojatalia=new Karta[maksilosckart];
            this.ilosckartwtalii = ilosckartwtalii;
        }
    }

    public Talia(Karta[] talia,int ilosckart) {
        this.mojatalia=new Karta[maksilosckart];
        for (int i=0;i<ilosckart;++i){
            this.mojatalia[i]=talia[i];
            ++this.ilosckartwtalii;
        }
    }

    public void Tasuj(){
        Random generator=new Random();
        for(int i=0;i<56;++i){
            int pierwsza=0,druga=0;
            while(pierwsza==druga){
                pierwsza=generator.nextInt(ilosckartwtalii);
                druga=generator.nextInt(ilosckartwtalii);
            }
            Karta temp=this.mojatalia[pierwsza];
            this.mojatalia[pierwsza]=this.mojatalia[druga];
            this.mojatalia[druga]=temp;
        }
    }

    public void PokazWszystkie(){
        for(int i=0;i<ilosckartwtalii;++i){
            this.mojatalia[i].PokazKarte();
        }
    }

    public int getIlosckartwtalii() {
        return ilosckartwtalii;
    }


    /*
        Metoda zwracajaca karte ostatnia w tablicy

        Parametry:
            -void

        Zwraca:
            -Karta
     */

    public Karta WezPierwszaZGory(){
        Karta temp=this.mojatalia[(this.ilosckartwtalii)-1];
        this.mojatalia[(this.ilosckartwtalii--)-1]=null;
        return temp;
    }


    /*
        Tutaj 2 metody dzieki ktorym dziele talie na pol i rozdaje te polowy graczom

        Parametry:
            -void

        Zwraca:
            -Polowe talii kart w postaci tablicy kart Karta []
     */
    public Karta[] DajPierwszePol(){

        Karta[] temp = new Karta [maksilosckart/2];
        if(this.ilosckartwtalii!=0) {
            for (int i = 0; i < maksilosckart / 2; ++i) {
                temp[i] = this.mojatalia[i];
                this.mojatalia[i] = null;
                this.ilosckartwtalii--;
            }
        }
        return temp;
    }

    public Karta[] DajDrugiePol(){
        Karta[] temp = new Karta [maksilosckart/2];
        if(this.ilosckartwtalii!=0) {
            for (int i = maksilosckart/2; i < maksilosckart; ++i) {
                temp[i-maksilosckart/2] = this.mojatalia[i];
                this.mojatalia[i] = null;
                this.ilosckartwtalii--;
            }
        }
        return temp;
    }

    public void DodajKarte(Karta Arg){
        if(this.ilosckartwtalii!= maksilosckart){
            this.mojatalia[this.ilosckartwtalii++]=Arg;
        }
        else {
            System.out.println("Brak miejsca, nieoczekiwany blad!");
        }
    }

    public Karta[] getMojatalia() {
        return mojatalia;
    }
}

