#include<iostream>
#include<string.h> 
using namespace std;

int main()
{
    
    char word[30];
    
    cout << "\t ==============Membalikkan kata============== \n\n";
    cout << "Masukkan kata : ";
    cin.getline (word , sizeof (word) );
    
    cout << "Setelah dibalik : ";
    
    for(int i = strlen(word) - 1; i >= 0; i--){
        
        cout << word[i]<<"";}
}
