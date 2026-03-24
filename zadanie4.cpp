#include <iostream>
#include <filesystem>
#include <fstream>

int main() {
    std::filesystem::path katalog("moj_folder");

    // Tworzenie katalogu (create_directories nie zgłasza błędu, jeśli już istnieje)
    std::filesystem::create_directories(katalog);
    std::cout << "Utworzono katalog: " << katalog << "\n\n";

    // Tworzenie przykładowych plików w katalogu
    for (const auto& nazwa : {"plik1.txt", "plik2.txt", "plik3.txt"}) {
        std::ofstream plik(katalog / nazwa);
        plik << "Zawartosc pliku: " << nazwa << "\n";
        std::cout << "Utworzono plik: " << (katalog / nazwa) << std::endl;
    }

    // Iteracja po zawartości katalogu
    std::cout << "\n=== Zawartosc katalogu \"" << katalog.string() << "\" ===" << std::endl;
    for (const auto& wpis : std::filesystem::directory_iterator(katalog)) {
        std::cout << "  " << wpis.path();
        if (wpis.is_regular_file())
            std::cout << "  [plik, " << wpis.file_size() << " B]";
        else if (wpis.is_directory())
            std::cout << "  [katalog]";
        std::cout << std::endl;
    }

    return 0;
}
