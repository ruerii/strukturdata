#include <iostream>

using namespace std;

typedef struct mahasiswa
{
    char nama[30];
    char nim[10];
    char jurusan[10];
}
mhs;
main(){
    mhs isi[2];
    int i,x;
    for(i=0; i<=1; i++)
    {
        cout<<"====Daftar Mahasiswa ===="<<endl;
        cout<<"Nama     : ";cin>>isi[i].nama;
        cout<<"NIM      : ";cin>>isi[i].nim;
        cout<<"Jurusan  :";cin>>isi[i].jurusan;
        cout<<endl;
    }
   for(x=0; x<=1; x++)
   {
       
       cout<<"==== Data Mahasiswa ===="<<endl;
       cout<<"Data ke ["<<x<<"] "<<endl<<"Nama  :   "<<isi[x].nama<<endl<<"NIM  :  "<<isi[x].nim<<endl<<"Jurusan  : " <<isi[x].jurusan;
       cout<<endl;
   }
}
