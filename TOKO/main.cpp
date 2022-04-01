// Ghofar (448)
// Dea (445)
// Aziz (442)

#include <iostream>
#include <streambuf>
#include <exception>
#include <fstream>
#include <vector>

class Toko {
    const int HargaAyamGeprek = 21000;
    const int HargaAyamGoreng = 17000;
    const int HargaUdangGoreng = 19000;
    const int HargaCumiGoreng = 20000; // cumi mahal bnr
    const int HargaAyamBakar = 25000; // ini juga
    
    struct Item {
        int nomor;
        int jumlah;
    };

public:
    int totalOnkir;
    int totalHarga;
    int totalHargaMakanan;
    int jarak_destinasi;
    std::vector<Item> menu_yg_dipilih;
    
    Toko() {
        std::cout << "=================================================" << std::endl;
        std::cout << "Rumah makan gorengan yang bikin kaleng" << std::endl;
        std::cout << "Daftar Harga: " << std::endl;
        std::cout << "1. Ayam Geprek    : " << HargaAyamGeprek << std::endl;
        std::cout << "2. Ayam Goreng    : " << HargaAyamGoreng << std::endl;
        std::cout << "3. Udang Goreng   : " << HargaUdangGoreng << std::endl;
        std::cout << "4. Cumi Goreng    : " << HargaCumiGoreng << std::endl;
        std::cout << "5. Ayam Bakar     : " << HargaAyamBakar << std::endl;
        std::cout << "=================================================" << std::endl;
    }
    
    bool BeganInput() {
        menu_yg_dipilih = std::vector<Item>(5);
        std::cout << "Masukan nomor makanan yang akan di pesan (ketik 0 untuk keluar)" << std::endl;
        
        while (true) {
            std::cout << "Masukan nomor makanan: ";
            int nomor;
            std::cin >> nomor;
            if (nomor == 0) {
                break;
            }

            if (nomor < 1 || nomor > 5) {
                std::cout << "Nomor makanan tidak ada" << std::endl;
                continue;
            }

            // check if any index contain number from nomor
            bool found = false;
            for (int i = 0; i < menu_yg_dipilih.size(); i++) {
                if (menu_yg_dipilih[i].nomor == nomor) {
                    found = true;
                    break;
                }
            }

            if (found) {
                std::cout << "Nomor makanan sudah dipilih" << std::endl;
                continue;
            }
            
            int jumlah;
            std::cout << "Masukan jumlah makanan: ";
            std::cin >> jumlah;
            
            Item item = {
                nomor,
                jumlah
            };
            
            menu_yg_dipilih.push_back(item);
        }
        
        // check if input is complete empty
        bool isEmpty = true;
        for (int i = 0; i < menu_yg_dipilih.size(); i++) {
            if (menu_yg_dipilih[i].jumlah != 0) {
                isEmpty = false;
                break;
            }
        }
        
        // debug purpose, leave this commented if not in use
        //__asm__("int3");
        
        if (isEmpty) {
            return false;
        }
        
        std::cout << "Masukan jarak rumah anda: "; std::cin >> jarak_destinasi;
        
        std::cout << "=================================================" << std::endl;
        std::cout << "Daftar makanan yang dipesan: " << std::endl;
        for (int i = 0; i < menu_yg_dipilih.size(); i++) {
            switch (menu_yg_dipilih[i].nomor) {
                case 1:
                    std::cout << "Ayam Geprek   : " << menu_yg_dipilih[i].jumlah << std::endl;
                    break;
                case 2:
                    std::cout << "Ayam Goreng   : " << menu_yg_dipilih[i].jumlah << std::endl;
                    break;
                case 3:
                    std::cout << "Udang Goreng  : " << menu_yg_dipilih[i].jumlah << std::endl;
                    break;
                case 4:
                    std::cout << "Cumi Goreng   : " << menu_yg_dipilih[i].jumlah << std::endl;
                    break;
                case 5:
                    std::cout << "Ayam Bakar    : " << menu_yg_dipilih[i].jumlah << std::endl;
                    break;
            }
        }
        
        std::cout << "=================================================" << std::endl;
        
        return !isEmpty ? true : false;
    }
    
    void PrintStruk() {
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        
        totalOnkir = 0;
        if (jarak_destinasi < 3) {
            totalOnkir += 15000;
        } else {
            totalOnkir += 25000;
        }
        
        totalHargaMakanan = 0;
        for (int i = 0; i < menu_yg_dipilih.size(); i++) {
            switch (menu_yg_dipilih[i].nomor) {
                case 1:
                    totalHargaMakanan += HargaAyamGeprek * menu_yg_dipilih[i].jumlah;
                    break;
                case 2:
                    totalHargaMakanan += HargaAyamGoreng * menu_yg_dipilih[i].jumlah;
                    break;
                case 3:
                    totalHargaMakanan += HargaUdangGoreng * menu_yg_dipilih[i].jumlah;
                    break;
                case 4:
                    totalHargaMakanan += HargaCumiGoreng * menu_yg_dipilih[i].jumlah;
                    break;
                case 5:
                    totalHargaMakanan += HargaAyamBakar * menu_yg_dipilih[i].jumlah;
                    break;
            }
        }
        
        int hargaSblmDiskon = totalHargaMakanan + totalOnkir;
        
        // note: not accurate for some reason
        if (totalHargaMakanan > 25000) {
            totalOnkir -= 3000;
        } else if (totalHargaMakanan > 50000) {
            totalOnkir -= 5000;
            totalHargaMakanan -= (totalHargaMakanan) * (15 / 100);
        } else if (totalHargaMakanan > 150000) {
            totalOnkir -= 8000;
            totalHargaMakanan -= (totalHargaMakanan) * (35 / 100);
        }
        
        totalHarga = totalHargaMakanan + totalOnkir;
        
        std::string output;
        output.append("======================================\n");
        output.append("Rumah makan gorengan yang bikin kaleng\n");
        output.append("======================================\n");
        output.append("Menu yang di pesan:\n");
        for (int i = 1; i <= menu_yg_dipilih.size(); i++) {
            switch (menu_yg_dipilih[i].nomor) {
                case 1: {
                    output.append(" - Ayam Geprek   : ");
                    output.append(std::to_string(menu_yg_dipilih[i].jumlah) + " (Total harga: " + std::to_string(HargaAyamGeprek * menu_yg_dipilih[i].jumlah) + ")\n");
                    break;
                }
                
                case 2: {
                    output.append(" - Ayam Goreng   : ");
                    output.append(std::to_string(menu_yg_dipilih[i].jumlah) + " (Total harga: " + std::to_string(HargaAyamGoreng * menu_yg_dipilih[i].jumlah) + ")\n");
                    break;
                }
                
                case 3: {
                    output.append(" - Udang Goreng  : ");
                    output.append(std::to_string(menu_yg_dipilih[i].jumlah) + " (Total harga: " + std::to_string(HargaUdangGoreng * menu_yg_dipilih[i].jumlah) + ")\n");
                    break;
                }
                
                case 4: {
                    output.append(" - Cumi Goreng   : ");
                    output.append(std::to_string(menu_yg_dipilih[i].jumlah) + " (Total harga: " + std::to_string(HargaCumiGoreng * menu_yg_dipilih[i].jumlah) + ")\n");
                    break;
                }
                
                case 5: {
                    output.append(" - Ayam Bakar    : ");
                    output.append(std::to_string(menu_yg_dipilih[i].jumlah) + " (Total harga: " + std::to_string(HargaAyamBakar * menu_yg_dipilih[i].jumlah) + ")\n");
                    break;
                }
            }
        }
        
        output.append("\n");
        output.append("Biaya onkir  : " + std::to_string(totalOnkir) + " (jarak dari rumah anda ke rumah makan: " + std::to_string(jarak_destinasi) + ")\n");
        output.append("Sebelum diskon: " + std::to_string(hargaSblmDiskon) + "\n");
        output.append("Total harga  : " + std::to_string(totalHarga) + "\n");
        output.append("======================================\n");
        
        std::fstream file_stream("struk.txt", std::ios::out | std::ios::trunc);
        file_stream << output;
        file_stream.close();
        
        std::cout << output;
    }
};

int main() {
    Toko* toko = new Toko;
    if (toko->BeganInput()) {
        toko->PrintStruk();
    } else {
        std::cout << "Anda keluar dari program!" << std::endl;
    }
}
