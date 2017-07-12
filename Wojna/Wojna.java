import javax.swing.*;
import java.util.Objects;
import java.util.Scanner;

/**
 * Created by maciek on 10.06.17.
 */
public class Wojna {
    private Gracz pierwszy;
    private Gracz drugi;
    private Talia Glowna;

    enum WariantyWojny{Silniejsza,Slabsza,Wojna}


    public Wojna() {
        this.Glowna=new Talia();
        this.pierwszy = new Gracz();
        this.drugi = new Gracz("Komputer");


    }

    private void Bitwa(int i,Karta[] pierwszePole,Karta[] drugiePole){
        WariantyWojny PierwszaOdDrugiej;
        if(this.pierwszy.getWlasna().getIlosckartwtalii()!=0 && this.drugi.getWlasna().getIlosckartwtalii()!=0) {
            pierwszePole[i] = this.pierwszy.getWlasna().WezPierwszaZGory();
            drugiePole[i]=this.drugi.getWlasna().WezPierwszaZGory();

        }
        else if (this.pierwszy.getWlasna().getIlosckartwtalii()==0 && this.drugi.getWlasna().getIlosckartwtalii()==0){
            this.PierwszemuBrakujeKart();
            this.DrugiemuBrakujeKart();
        }
        else if (this.pierwszy.getWlasna().getIlosckartwtalii()==0){
            this.PierwszemuBrakujeKart();
        }
        else if (this.drugi.getWlasna().getIlosckartwtalii()==0){
            this.DrugiemuBrakujeKart();
        }
        if (i!=0) {
            if(this.pierwszy.getWlasna().getIlosckartwtalii()==0 || this.pierwszy.getWlasna().getIlosckartwtalii()==1) {
                this.PierwszemuBrakujeKart();
            }
            pierwszePole[i + 1] = this.pierwszy.getWlasna().WezPierwszaZGory();
            System.out.println("Jedna karta odwrocona");
            pierwszePole[i + 2] = this.pierwszy.getWlasna().WezPierwszaZGory();
            System.out.println("Karta gracza "+ this.pierwszy.getNazwa() + ": "+pierwszePole[i+2].PokazKarte());

            if (this.drugi.getWlasna().getIlosckartwtalii()==0 || this.drugi.getWlasna().getIlosckartwtalii()==1) {
                this.DrugiemuBrakujeKart();
            }
            drugiePole[i+1]=this.drugi.getWlasna().WezPierwszaZGory();
            System.out.println("Jedna karta odwrocona");
            drugiePole[i+2]=this.drugi.getWlasna().WezPierwszaZGory();
            System.out.println("Karta gracza Komputer: " + drugiePole[i+2].PokazKarte());

            PierwszaOdDrugiej=this.Porownaj(pierwszePole[i+2],drugiePole[i+2]);
            if (PierwszaOdDrugiej==WariantyWojny.Wojna){
                System.out.println("Wojna!");
                Bitwa(i+3,pierwszePole,drugiePole);
            }
            else if (PierwszaOdDrugiej==WariantyWojny.Silniejsza){//podczas bitwy wygral pierwszy gracz
                System.out.println("");
                System.out.println("Wygrywa gracz, zabiera przeciwnikowi " +(i+2)+" kart!");
                for (int k=0;k<(i+3);++k){
                    this.pierwszy.getPomocnicza().DodajKarte(pierwszePole[k]);
                    this.pierwszy.getPomocnicza().DodajKarte(drugiePole[k]);
                    drugiePole[k]=null;
                }
            }
            else {//podczas bitwy wygral drugi gracz
                System.out.println("");
                System.out.println("Wygrywa gracz Komputer, zabiera przeciwnikowi " + (i+2)+" kart!");
                for (int k=0;k<(i+3);++k){
                    this.drugi.getPomocnicza().DodajKarte(drugiePole[k]);
                    this.drugi.getPomocnicza().DodajKarte(pierwszePole[k]);
                    pierwszePole[k]=null;
                }
            }
        }
        else{
            System.out.println("Karta gracza "+ this.pierwszy.getNazwa() + ": "+pierwszePole[i].PokazKarte());
            System.out.println("Karta gracza Komputer: " + drugiePole[i].PokazKarte());
            PierwszaOdDrugiej=this.Porownaj(pierwszePole[i],drugiePole[i]);
            if (PierwszaOdDrugiej==WariantyWojny.Wojna) Bitwa(i+1,pierwszePole,drugiePole);
            else if (PierwszaOdDrugiej==WariantyWojny.Silniejsza){
                System.out.println("");
                System.out.println("Wygrywa gracz, zabiera przeciwnikowi 1 karte!");
                this.pierwszy.getPomocnicza().DodajKarte(pierwszePole[i]);
                this.pierwszy.getPomocnicza().DodajKarte(drugiePole[i]);
                drugiePole[i]=null;
            }
            else{
                System.out.println("");
                System.out.println("Wygrywa gracz Komputer, zabiera przeciwnikowi 1 karte!");
                this.drugi.getPomocnicza().DodajKarte(drugiePole[i]);
                this.drugi.getPomocnicza().DodajKarte(pierwszePole[i]);
                pierwszePole[i]=null;
            }

        }

    }

    private void PierwszemuBrakujeKart(){
        System.out.println("Graczowi " + this.pierwszy.getNazwa() + " brakuje kart, trzeba przetasowac");
        this.pierwszy.setWlasna(this.pierwszy.getPomocnicza().getMojatalia(),this.pierwszy.getPomocnicza().getIlosckartwtalii());
        this.pierwszy.TasujTalie();this.pierwszy.ResetPomocniczej();
        System.out.println("Gracz ma w glownej talii " +this.pierwszy.getWlasna().getIlosckartwtalii()+" kart, a w pomocniczej " + this.pierwszy.getPomocnicza().getIlosckartwtalii());
    }

    private void DrugiemuBrakujeKart(){
        System.out.println("Graczowi " + this.drugi.getNazwa() + " brakuje kart, trzeba przetasowac");
        this.drugi.setWlasna(this.drugi.getPomocnicza().getMojatalia(),this.drugi.getPomocnicza().getIlosckartwtalii());
        this.drugi.TasujTalie();this.drugi.ResetPomocniczej();
        System.out.println("Komputer ma w glownej talii " +this.drugi.getWlasna().getIlosckartwtalii()+" kart, a w pomocniczej " + this.drugi.getPomocnicza().getIlosckartwtalii());
    }


    public void RozpocznijGre(){
        boolean CzyKonczymy=false;
        String znakGracza;
        this.Glowna.Tasuj();

        this.pierwszy.setWlasna(Glowna.DajPierwszePol(),28);
        this.drugi.setWlasna(Glowna.DajDrugiePol(),28);


        //-----------Tutaj takie informacje wejsciowe o wszystkim co mamy--------------

        System.out.println("Informacje poczatkowe:");
        System.out.println("Liczba kart gracza: " + this.pierwszy.getWlasna().getIlosckartwtalii());
        System.out.println("Liczba kart w talii pomocniczej: " + this.pierwszy.getPomocnicza().getIlosckartwtalii());

        System.out.println("Liczba kart komputera: " + this.drugi.getWlasna().getIlosckartwtalii());
        System.out.println("Liczba kart w talii pomocniczej: " + this.drugi.getPomocnicza().getIlosckartwtalii());

        System.out.println("\tDodatkowo sprawdzamy czy rozdano wszystkie karty. Liczba kart w talii glownej: " + this.Glowna.getIlosckartwtalii());

        //-----------------------------------------------------------------------------

        Karta[] polebitwypierwsze=new Karta[Talia.maksilosckart];
        Karta[] polebitwydrugie=new Karta[Talia.maksilosckart];

        Scanner odczyt = new Scanner(System.in);
        System.out.println("Czy gramy?[T/n]");
        znakGracza=odczyt.nextLine();
        if(Objects.equals(znakGracza,"n")) CzyKonczymy=true;
        while (!CzyKonczymy) {


            System.out.println("Zaczynamy nowe starcie! (znak = " + znakGracza + ")");
            System.out.println("Gracz ma w glownej talii " +this.pierwszy.getWlasna().getIlosckartwtalii()+" kart, a w pomocniczej " + this.pierwszy.getPomocnicza().getIlosckartwtalii());
            System.out.println("Komputer ma w glownej talii " +this.drugi.getWlasna().getIlosckartwtalii()+" kart, a w pomocniczej " + this.drugi.getPomocnicza().getIlosckartwtalii());

            this.Bitwa(0,polebitwypierwsze,polebitwydrugie);
            System.out.println("Czy gramy dalej?[T/n]");
            znakGracza = odczyt.nextLine();

            while (!Objects.equals(znakGracza, "T") & !Objects.equals(znakGracza, "n")){
                System.out.println("Czy gramy dalej?[T/n]");
                znakGracza = odczyt.nextLine();
            }
            if (Objects.equals(znakGracza, "n")) CzyKonczymy=true;
            System.out.println("");
        }
        int liczbaKartGracza=this.pierwszy.getPomocnicza().getIlosckartwtalii()+this.pierwszy.getWlasna().getIlosckartwtalii();
        int liczbaKartKomputera=this.drugi.getPomocnicza().getIlosckartwtalii()+this.drugi.getWlasna().getIlosckartwtalii();


        if(liczbaKartGracza>liczbaKartKomputera) {
            System.out.println("Wygrywa " + this.pierwszy.getNazwa());
            System.out.println(("Posiada "+liczbaKartGracza+" kart!"));
        }
        else if (liczbaKartGracza<liczbaKartKomputera){
            System.out.println("Wygrywa komputer!");
            System.out.println(("Posiada "+liczbaKartKomputera+" kart!"));
        }
        else System.out.println("Remis!");
        System.out.println(("Gracz posiada "+liczbaKartGracza+" kart!"));
        System.out.println(("Komputer posiada "+liczbaKartKomputera+" kart!"));


    }

    public WariantyWojny Porownaj(Karta pierwsza,Karta druga){
        if (Objects.equals(pierwsza.GetWartosc(), druga.GetWartosc())) return WariantyWojny.Wojna;
        else if(pierwsza.getStandardowa()==0 && druga.getStandardowa()==0){
            if (Objects.equals(pierwsza.GetWartosc(), "As")) return WariantyWojny.Silniejsza;
            else if (Objects.equals(pierwsza.GetWartosc(), "Krol") && !Objects.equals(druga.GetWartosc(), "As")) return WariantyWojny.Silniejsza;
            else if (Objects.equals(pierwsza.GetWartosc(), "Dama") && !Objects.equals(druga.GetWartosc(), "As") && !Objects.equals(druga.GetWartosc(), "Krol")) return WariantyWojny.Silniejsza;
            else return WariantyWojny.Slabsza;
        }
        else if (pierwsza.getStandardowa()!=0 && druga.getStandardowa()!=0){
            if(pierwsza.getStandardowa()>druga.getStandardowa()) return WariantyWojny.Silniejsza;
            else return WariantyWojny.Slabsza;
        }
        else if(pierwsza.getStandardowa()==0 && druga.getStandardowa()!=0) return WariantyWojny.Silniejsza;
        else return WariantyWojny.Slabsza;
    }


}