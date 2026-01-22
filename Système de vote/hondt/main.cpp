#include <iostream>
#include <vector>
#include <string>

using namespace std;



//tri modifié pour comparer le second élément de chaque liste traitée dans la liste triée
vector<vector<int>> TriBullesParSecondIndice (vector<vector<int>> tab) {
    bool estTrie = false;
    while (not estTrie) {
        estTrie = true;
        for (unsigned indice = 0; indice < tab.size()-1; indice++) {
            if (tab[indice][1] < tab[indice+1][1]) {
                swap(tab[indice], tab[indice+1]);
                estTrie = false;
            }

        }
    }
    return tab;
}


vector<int> systemeDeHondt (vector<string> candidats, vector<int> scores_candidats, int sieges) {
    vector<vector<int>> divisions;
    vector<vector<int>> divisions_par_index;
    vector<int> sieges_attribues(candidats.size(), 0);


    //creation d'une liste de listes des résultats des divisions du score de chaque candidat
    for (unsigned i = 0; i < candidats.size(); i++) {
        divisions.push_back(vector<int>{});
        for (int j = 1; j <= sieges; j++) {
            divisions[i].push_back(scores_candidats[i]/j);
        }
    }


    //on récupere les index de chaque valeur présente dans la liste "division" pour les mettre sous la forme {{i, valeur}, {i, valeur}}
    for (unsigned k = 0; k < divisions.size(); k++) {
        for (unsigned l = 0; l < divisions[k].size(); l++) {
            divisions_par_index.push_back({k, divisions[k][l]});
        }
    }
    divisions_par_index = TriBullesParSecondIndice(divisions_par_index); //on trie de manière décroissante à partir du second élément de chaque couple


    //on calcule les nombre de sièges de chacuns en fonction du nombre d'apparitions de leurs index dans la liste triée
    for (int q = 0; q < sieges; q++)
    {
        int candidat = divisions_par_index[q][0];
        sieges_attribues[candidat] += 1;
    }
    return sieges_attribues;
}

//on utilise une fonction pour incrémenter chaque candidat en fonction du vote dans le fichier
vector<int> chercheUnEntier (vector<int> scores){
    string chaine;
    while (true){
        getline (cin, chaine);
        if (chaine == "//") break;
        getline (cin, chaine);
        if (chaine == "//") break;
        getline (cin, chaine);
        if (chaine != "//") {
            scores[stoi(chaine)-1] += 1;
        }
    }
    return scores;
}

int main(){

    vector<string> liste_candidats = {}; //on insère les 4 candidats depuis le fichier (ils correspondent aux 4 premières lignes)
    string donnee = "";
    for (unsigned i (0); i < 4; ++i){
        getline(cin, donnee);
        liste_candidats.push_back(donnee);}

    vector<int> liste_scores(liste_candidats.size(), 0); //création d'une liste des scores de chaque candidats de "liste_candidats"
    liste_scores = chercheUnEntier(liste_scores);

    vector<int> resultat = systemeDeHondt(liste_candidats, liste_scores, 10); //liste qui contient les sièges de chaque candidat par index

    cout << "~ Liste des candidats et leurs nombre de sièges ~" << endl; //affichage des résultats par candidat
    for (unsigned numero = 0; numero < resultat.size(); numero++)
    {
        cout << liste_candidats[numero] << " : " << resultat[numero] << endl;
    }
}
