/*
 Aprischa Nauva
 140810180063
 A
*/

#include<iostream>
#include<string.h>

using namespace std;

void enc(){
    string plaintext, ciphertext;
    int i, k;
    char c;
    
    cout << "Masukan Plaintext : ";
    cin.ignore();
    getline (cin, plaintext);
    cout << "Masukan jumlah pergeseran (K): ";
    cin >> k;
    ciphertext = " ";
    
    for (i=0; i < plaintext.length(); i++) {
        c = plaintext[i];
        if (isalpha(c)){
            c = toupper(c);
            c = c - 65;
            c = (c + k) % 26;
            c = c + 65;
        }
        ciphertext = ciphertext + c;
    }
    cout << "Ciphertext: " << ciphertext << endl;
}

void dec(){
    string plaintext, ciphertext;
    int i, k;
    char c;
    
    cout << "Masukan Ciphertext: ";
    cin.ignore();
    getline (cin, ciphertext);
    cout << "Masukan jumlah pergeseran (K): ";
    cin >> k;
    plaintext = "";
    
    for (i=0; i <ciphertext.length(); i++){
        c = ciphertext[i];
        if (isalpha(c)){
            c = toupper(c);
            c = c - 65;
            if (c - k < 0)
                c = 26 + (c - k);
            else
                c = (c - k) % 26;
            c = c + 65;
            c = tolower(c);
        }
        plaintext = plaintext + c;
    }
    cout << "Plaintext: " << plaintext << endl;
}

int main (){
    int pilihan;
    bool stop;
    stop = false;
    
    while (!stop){
        cout << "Pilihan: " << endl;
        cout << "[1] Enkripsi" << endl;
        cout << "[2] Dekripsi" << endl;
        cout << "[3] Exit" << endl;
        cout << "Pilih: ";
        cin >> pilihan;
        switch(pilihan){
            case 1 :
                enc();
                break;
            case 2 :
                dec();
                break;
            case 3 :
                stop = true;
                break;
        }
    }
}
