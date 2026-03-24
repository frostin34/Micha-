#include <iostream>
#include <filesystem>
#include <fstream>

int main() {
    std::filesystem::path sciezka("test.txt");

    // Zapis danych do pliku
    std::ofstream plik(sciezka);
    if (!plik) {
        std::cerr << "Nie mozna utworzyc pliku!" << std::endl;
        return 1;
    }
    plik << "Linia pierwsza: Hello, World!\n";
    plik << "Linia druga: std::filesystem jest swietne.\n";
    plik << "Linia trzecia: C++17 wprowadzil wiele przydatnych funkcji.\n";
    plik.close();

    // Odczyt rozmiaru
    std::uintmax_t rozmiar = std::filesystem::file_size(sciezka);
    std::cout << "Plik \"" << sciezka.string() << "\" zostal utworzony." << std::endl;
    std::cout << "Rozmiar pliku: " << rozmiar << " bajtow" << std::endl;

    return 0;
}
