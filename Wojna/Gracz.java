import java.util.Scanner;

/**
 * Created by maciek on 10.06.17.
 */
public class Gracz {
    //private:
    private String nazwa;
    private Talia wlasna;
    private Talia pomocnicza;

    public Gracz() {
        this.pomocnicza=new Talia(0);
        Scanner odczyt=new Scanner(System.in);
        System.out.println("Podaj nazwe gracza");
        this.nazwa=odczyt.nextLine();
    }

    //public:
    public Gracz(String nazwa) {
        this.pomocnicza=new Talia(0);
        this.nazwa = nazwa;
    }


    public String getNazwa() {
        return nazwa;
    }

    public void setWlasna(Karta [] Arg,int Arg2) {
        this.wlasna = new Talia(Arg,Arg2);
    }

    public void ResetPomocniczej(){
        this.pomocnicza=new Talia(0);
    }

    public void TasujTalie(){
        this.wlasna.Tasuj();
    }
    public Talia getWlasna() {
        return wlasna;
    }

    public Talia getPomocnicza() {
        return pomocnicza;
    }
}
