# Sae_C-

https://prod.liveshare.vsengsaas.visualstudio.com/join?BE86D8DEBB8D3423EECF9FB52336A8798251

https://prod.liveshare.vsengsaas.visualstudio.com/join?500628F6E93942BBA150C365174263CCAA7A

mathias.m2502@gmail.com
mankaiadam145@gmail.com
bouyaninho@gmail.com

sudo apt-get update && sudo apt-get install build-essential

g++ programme.cpp -o programme

./programme

./programme < vote.txt > sortie.txt


vector<int> lireQueLesVotes() {
    vector<int> lesVotes;

    while (true) {
        // 1. On lit le NOM pour le "consommer" (on l'ignore)
        string poubelle = litUneString();

        // Si le fichier est fini ou qu'il n'y a plus de nom, on arrête
        if (!cin || poubelle.empty()) break;

        // 2. On lit le PRENOM pour le "consommer" (on l'ignore)
        litUneString();

        // 3. On lit le VOTE (C'est la seule chose qu'on garde)
        int leVote = litUnEntier();
        lesVotes.push_back(leVote);
    }

    return lesVotes;
}



#include <iostream>
#include <vector>

void saucisse() {
    std::vector<std::vector<int>> m = {{1, 2, 3, 4}, {4, 3, 2, 1}};
    vector<string> cars = {0, 0, 0, 0,};
    for (int i = 0; i <2; i++) {
        for (int j = 0; j <5; j++) {
            std::cout << m[i][j];
        }
    }
}

int main() {
    std::cout << "Try programiz.pro\n";
    saucisse();
    return 0;
}

