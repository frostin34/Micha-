#include <iostream>
#include <filesystem>

int main() {
    std::filesystem::path sciezka("dane/plik.txt");

    std::cout << "=== Informacje o sciezce ===" << std::endl;
    std::cout << "Pelna sciezka:    " << sciezka          << std::endl;
    std::cout << "Nazwa pliku:      " << sciezka.filename()  << std::endl;
    std::cout << "Rozszerzenie:     " << sciezka.extension() << std::endl;
    std::cout << "Katalog nadrzedny:" << sciezka.parent_path() << std::endl;
    std::cout << "Czy absolutna:    " << (sciezka.is_absolute() ? "tak" : "nie") << std::endl;
    std::cout << "Czy wzgledna:     " << (sciezka.is_relative() ? "tak" : "nie") << std::endl;

    return 0;
}
