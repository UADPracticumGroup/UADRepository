// Ghofar (448)
// Dea (445)
// Aziz (442)

#include <iostream>
#include <fstream>

class SPBU {
    const int harga_pertalite = 7000;
    const int harga_pertamax = 9000;
public:
    std::string nama;
    int jenis_bensin;
    int liter;
    int total_harga;
    
    void kalkulasi() {
        total_harga = jenis_bensin == 1 ? liter * harga_pertalite : liter * harga_pertamax;
    }
    
    void print_struk() {
        std::string output;
        output.append("=======================\n");
        output.append("STRUK SPBU\n");
        output.append("=======================\n");
        output.append("Nama Pelanggan: " + nama + "\n");
        std::string jenis = jenis_bensin == 1 ? "Pertalite (Harga per-liter: " + std::to_string(harga_pertalite) + ")" : "Pertamax (Harga per-liter: " + std::to_string(harga_pertamax) + ")";
        output.append("Jenis Besin: " + jenis + "\n");
        output.append("Total Liter: " + std::to_string(liter) + "\n");
        output.append("Total Harga: Rp " + std::to_string(total_harga) + "\n");
        output.append("=======================\n");
        
        // Write struk to file
        std::fstream file_stream("struk.txt", std::ios::out | std::ios::trunc);
        file_stream << output;
        file_stream.close();
        
        std::cout << output;
    }
};

int main() {
    SPBU spbu;
    
    std::cout << "SPBU kalengan" << std::endl;
    std::cout << "Jenis bensin: " << std::endl;
    std::cout << "1. Pertalite" << std::endl;
    std::cout << "2. Pertamax" << std::endl;
    std::cout << std::endl;
    std::cout << "Masukan nama pelanggan: "; std::getline(std::cin, spbu.nama);
    std::cout << "Masukan jenis bensin: "; std::cin >> spbu.jenis_bensin;
    if (spbu.jenis_bensin != 1 && spbu.jenis_bensin != 2) {
        std::cout << "Jenis bensin tidak tersedia" << std::endl;
        return 0;
    }
    
    std::cout << "Masukan jumlah liter: "; std::cin >> spbu.liter;
    spbu.kalkulasi();
    spbu.print_struk();
    
    return 0;
}