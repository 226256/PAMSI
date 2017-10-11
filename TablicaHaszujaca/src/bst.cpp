//
// Created by maciek on 18.05.17.
//

#include "../inc/bst.hh"



bst::bst() {
    this->rozmiar=0;
    this->root= nullptr;
}

bst::~bst() {
    this->rozmiar=0;
    delete this->root;
}

TreeNode *bst::getRoot() const {
    return root;
}

void bst::setRoot(TreeNode *root) {
    bst::root = root;
}


int bst::size() {
    return this->rozmiar;
}

bool bst::isEmpty() {
    return this->rozmiar == 0;
}


/*
 * Dodawanie nowego wezla do bst
 *
 * Parametry:
 *  -referencja do klucza w postaci int
 *  -referencja do wartosci jaka ma zostac zapisana w wezle
 *
 * Zwraca:
 *  -void
 */
void bst::TreeAdd(int &klucz, Wartosc& Dane) {
    TreeNode* obecny=this->root;
    TreeNode* wczesniejszy=obecny;
    TreeNode* nowy=new TreeNode(klucz,Dane);
    if(this->rozmiar==0){
        this->root=nowy;
        this->rozmiar++;
    }
    else{
        while(obecny!= nullptr){
            wczesniejszy=obecny;
            if(obecny->Key()>klucz) obecny=obecny->LeftSon();
            else obecny=obecny->RightSon();
        }
        nowy->setAncestor(wczesniejszy);
        if(klucz<wczesniejszy->Key()){
            wczesniejszy->setLeftSon(nowy);
        }
        else wczesniejszy->setRightSon(nowy);
        this->rozmiar++;
    }
}

//przeciazenie metody dodawania wezla gdyby podawano tylko klucz ktory
//mialby byc jednoczesnie takze danymi w wezle
void bst::TreeAdd(int &klucz) {
    TreeNode* obecny=this->root;
    TreeNode* wczesniejszy=obecny;
    TreeNode* nowy=new TreeNode(klucz,klucz);
    if(this->rozmiar==0){
        this->root=nowy;
        this->rozmiar=1;
    }
    else{
        while(obecny!= nullptr){
            wczesniejszy=obecny;
            if(obecny->Key()>klucz) obecny=obecny->LeftSon();
            else obecny=obecny->RightSon();
        }
        nowy->setAncestor(wczesniejszy);
        if(klucz<wczesniejszy->Key()){
            wczesniejszy->setLeftSon(nowy);
        }
        else wczesniejszy->setRightSon(nowy);
        this->rozmiar++;
    }
}


//usuwanie na razie niepotrzebne wiec z braku czasu wstrzymam sie z implementacja
void bst::TreeRemove(TreeNode* wezel) {
//    TreeNode* wyzszy=wezel->Ancestor();
//    TreeNode* lewy=wezel->LeftSon();
//    TreeNode* prawy=wezel->RightSon();
//    if(lewy== nullptr && prawy== nullptr){
//        if(wyzszy->RightSon()==wezel) wyzszy->setRightSon(nullptr);
//        else wyzszy->setLeftSon(nullptr);
//    }
//

}


/*
 * Wyszukiwanie w  bst
 *
 * Parametry:
 *  -klucz w postaci int
 *
 * Zwraca:
 *  -wskaznik do wezla o takim samym kluczu jesli jest
 *  -nullptr jesli nie znaleziony
 *
 */
TreeNode* bst::TreeSearch(int &klucz) {
    TreeNode* temp=this->root;
    while(temp != nullptr && temp->Key()!=klucz){
        if(temp->Key()>klucz) temp=temp->LeftSon();
        else temp=temp->RightSon();
    }
    return temp;
}





//---------metody potrzebne do testowania zlozonosci obliczeniowej-----------
void bst::zbuduj(std::string string, int wartosc, Wariant hasz) {
    int dane=0;
    if(hasz==poczatekdrzewa)this->TreeAdd(wartosc);

    for(int i=0;i<wartosc-1;++i){
        dane=rand()%wartosc;
        if(hasz==srodekdrzewa){if(i==wartosc/2)this->TreeAdd(wartosc);}
        this->TreeAdd(dane);
    }
    if(hasz==koniecdrzewa)this->TreeAdd(wartosc);
    //------------------------------------------------
    std::cout << "Wielkosc drzewa: " << this->size() << std::endl;
}

void bst::zadanie(std::string string,int wart) {
    TreeNode* temp = nullptr;
    temp=this->TreeSearch(wart);
    if(temp== nullptr) std::cerr << "Powinien znalezc a nie znalazl" << std::endl;
    else std::cout << temp->Key() << std::endl;
}
//--------------------------------------------------------------------------