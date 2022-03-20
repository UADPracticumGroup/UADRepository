#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main() {
    int pilihan;
    // use double instead since we need to handle fraction input too like phi
    double bil1, bil2;
    double hasil;
    char ulang;
    string operasi;

    // Help message
    string helpMessage = "=================================\n";
    helpMessage.append(" 	PROGRAM KALKULATOR\n");
    helpMessage.append("=================================\n");
    helpMessage.append("1. Penjumlahan\n");
    helpMessage.append("2. Pengurangan\n");
    helpMessage.append("3. Perkalian\n");
    helpMessage.append("4. Pembagian\n");
    helpMessage.append("5. Modulus\n");
    helpMessage.append("6. Exit\n");
    helpMessage.append("=================================\n");
    helpMessage.append("Masukan pilihan anda: ");
    
    // main loop
    do {
        cout << helpMessage;
        cin >> pilihan;
        if (pilihan == 6) {
            ulang = 't';
            break;
        }

        cout << endl;
        cout << "Bilangan Pertama: ";
        cin >> bil1;
        cout << "Bilangan Kedua: ";
        cin >> bil2;
        switch (pilihan) {
        case 1:
            hasil = bil1 + bil2;
            operasi = '+';
            break;
        case 2:
            hasil = bil1 - bil2;
            operasi = '-';
            break;
        case 3:
            hasil = bil1 * bil2;
            operasi = '*';
            break;
        case 4:
            if (bil1 == 0 || bil2 == 0) {
                cout << "Error: Bilangan tidak boleh 0" << endl;
                break;
            }
            hasil = bil1 / bil2;
            operasi = '/';
            break;
        case 5:
            // fmod = float modulus
            hasil = fmod(bil1, bil2);
            operasi = '%';
            break;
        default:
            cout << "Error: Salah Memasukkan Pilihan" << endl;
            break;
        }
        
        cout << endl;
        cout << "Hasil " << bil1 << operasi << bil2 << " = " << hasil << endl;
        cout << "=================================" << endl;
    }

    while (ulang != 't');
    cout << "Terima Kasih ";
    cout << endl;
}