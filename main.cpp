#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    std::ifstream fichier("liste.txt");
    if (!fichier) {
        std::cerr << "Erreur d'ouverture du fichier liste.txt" << std::endl;
        return 1;
    }

    std::vector<std::string> lignes;
    std::string ligne;
    while (std::getline(fichier, ligne)) {
        lignes.push_back(ligne);
    }

    fichier.close();

    if (lignes.empty()) {
        std::cerr << "Le fichier est vide." << std::endl;
        return 1;
    }

    std::srand(static_cast<unsigned int>(std::time(0))); // Initialisation du générateur de nombres aléatoires

    while (true) {
        int nombre_lignes = 0;
        std::cout << "Nombre de générations aléatoires désirées : ";
        std::cin >> nombre_lignes;

        if (nombre_lignes <= 0) {
            std::cerr << "Le nombre de lignes doit être supérieur à 0." << std::endl;
            continue; // Retourne au début de la boucle
        }

        std::cout << std::endl;

        for (int i = 0; i < nombre_lignes; ++i) {
            int index_aleatoire = std::rand() % lignes.size();
            std::cout << "Génération " << i + 1 << " : " << lignes[index_aleatoire] << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}

