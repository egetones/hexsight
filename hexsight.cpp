#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip> // Hex formatlama için gerekli

using namespace std;

// Yazdırılamayan karakterler için nokta (.) koyar
char filter(char c) {
    if (c >= 32 && c <= 126) {
        return c;
    }
    return '.';
}

void printHexDump(const string& filePath) {
    ifstream file(filePath, ios::binary);
    
    if (!file) {
        cerr << "\033[1;31m[!] Hata: Dosya açılamadı: " << filePath << "\033[0m" << endl;
        return;
    }

    // Dosya işaretçisi (offset)
    size_t offset = 0;
    vector<unsigned char> buffer(16); // Her satırda 16 byte okuyacağız

    cout << "\033[1;36m[*] Analiz Başlıyor: " << filePath << "\033[0m" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "OFFSET    | HEX BYTES                                       | ASCII" << endl;
    cout << "-----------------------------------------------------------------" << endl;

    while (file.read((char*)buffer.data(), 16) || file.gcount() > 0) {
        size_t bytesRead = file.gcount();

        // 1. Adres (Offset) Yazdır (Örn: 00000010)
        cout << "\033[1;33m" << setfill('0') << setw(8) << hex << offset << "\033[0m  ";

        // 2. Hex Değerlerini Yazdır (Örn: 41 42 43...)
        for (size_t i = 0; i < 16; ++i) {
            if (i < bytesRead) {
                cout << setfill('0') << setw(2) << hex << (int)buffer[i] << " ";
            } else {
                cout << "   "; // Boşluk doldur (dosya sonu için)
            }
            if (i == 7) cout << " "; // Ortaya ekstra boşluk görsellik için
        }

        cout << " |";

        // 3. ASCII Karşılıklarını Yazdır (Örn: |ABC.....|)
        for (size_t i = 0; i < bytesRead; ++i) {
            cout << "\033[1;32m" << filter((char)buffer[i]) << "\033[0m";
        }

        cout << "|" << endl;
        offset += 16;
    }
    
    cout << "-----------------------------------------------------------------" << endl;
    cout << "\033[1;36m[+] Analiz Tamamlandı.\033[0m" << endl;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Kullanım: ./hexsight <dosya_yolu>" << endl;
        return 1;
    }

    printHexDump(argv[1]);
    return 0;
}
