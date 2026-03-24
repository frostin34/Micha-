#include <iostream>
#include <filesystem>
#include <fstream>

int main() {
    std::filesystem::path zrodlo("plik.txt");
    std::filesystem::path cel("kopia.txt");

    // Tworzenie pliku źródłowego
    std::ofstream plik(zrodlo);
    if (!plik) {
        std::cerr << "Nie mozna utworzyc pliku zrodlowego!" << std::endl;
        return 1;
    }
    plik << "To jest zawartosc pliku zrodlowego.\n";
    plik << "Ten tekst zostanie skopiowany do nowego pliku.\n";
    plik.close();
    std::cout << "Utworzono plik: " << zrodlo << std::endl;

    // Kopiowanie pliku
    std::filesystem::copy(zrodlo, cel, std::filesystem::copy_options::overwrite_existing);
    std::cout << "Skopiowano do:  " << cel << std::endl;

    // Weryfikacja
    std::cout << "\nRozmiar zrodla: " << std::filesystem::file_size(zrodlo) << " bajtow" << std::endl;
    std::cout << "Rozmiar kopii:  " << std::filesystem::file_size(cel)    << " bajtow" << std::endl;

    return 0;
}
