#include<iostream>
using namespace std;

struct singlelinklist{ //struct
    
    int angka;
    singlelinklist* next; 
};
singlelinklist *awal, *akhir, *cur ,*tambah, *del,*tambahaffirst,*after;

//membuat node awal
void singlelinkedlist (int Num){
    awal = new singlelinklist;   
    awal->angka = Num;
    awal->next = NULL;
    akhir = awal;
}
//membuat fungsi insert first
void tambahawal (int Num){
    tambah = new singlelinklist;
    tambah->angka = Num;
    tambah->next = awal;
    awal = tambah;
} 
//membuat fungsi insert last
void tambahakhir (int Num){
    tambah = new singlelinklist;
    tambah->angka= Num;
    tambah->next = NULL;
    akhir->next = tambah;
}
//membuat fungsi insert after first
void tambahsetelahawal(int Num){
    tambahaffirst = new singlelinklist;
    tambahaffirst->angka = Num;

    cur = awal;
    Num = 1 ;
    while (Num < -1 ){
        cur = cur->next;
        Num++;       
    }
    tambahaffirst->next = cur->next;
    cur->next = tambahaffirst;   
}
//membuat fungsi delete first
void hapusawal (){
    del = awal;
    awal = awal->next;
    delete del;   
}
//membuat fungsi delete last
void hapusakhir (){ 
    singlelinklist* second_akhir = awal;
    while (second_akhir->next->next != NULL){
        second_akhir = second_akhir->next;  
    }    
    delete (second_akhir->next);
    second_akhir->next = NULL;
}
//membuat fungsi delet after first
void hapussetelahawal(int poss){
 int nomor = 1;
    cur = awal;
    while( nomor <= poss ){
      if( nomor == poss-1 ){
        after = cur;
      }
      if( nomor == poss ){
        del = cur;
      }
      cur = cur->next;
      nomor++;
    }
    after->next = cur;
    delete del;
  }
//membuat fungsi search sequential
int cariangka(int key){
    singlelinklist* p = awal;
    int i = 1;
    while (p->angka != key){
        p = p->next;
        i++;
    }
    return i;
}
//untuk print data
void printdatalinkedlist(){ 
    cur = awal;
    while (cur != NULL){
        cout << cur-> angka << " ";
        cur = cur->next;
    }
    cout<<endl;
}

int main(){
    
    singlelinkedlist(3); // untuk deklarasi node awal
    printdatalinkedlist(); 
    //print data
   
    tambahawal(1); //insert atau tambah awal
    printdatalinkedlist();
    //print data

    tambahawal(5);//insert atau tambah first
    printdatalinkedlist();
    //print data
    
    tambahsetelahawal(2);//insert atau tambah after first
    printdatalinkedlist();
    //print data

    tambahsetelahawal(11);//insert atau tambah before
    printdatalinkedlist();
    //print data

    tambahakhir(6);//insert atau tambah akhir
    printdatalinkedlist();
    //print data
    
    hapusawal();//delete fisrt
    printdatalinkedlist();
    //print data

    hapusakhir();//delete akhir
    printdatalinkedlist();
    //print data

    hapussetelahawal(2);//delete after
    printdatalinkedlist();
    //print data

    int key = 11; //key search
    cout<<"Data " << key << " ditemukan pada urutan ke- "<< cariangka(key); //search
}   