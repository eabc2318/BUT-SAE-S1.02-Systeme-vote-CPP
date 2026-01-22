#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// convertit le long vecteur en sous vecteur associé a un candidat

vector<vector<int>> compterVoteCandidat(vector<int> votes_exprimes, int nb_candidats) {
    vector<vector<int>> resultats(nb_candidats, vector<int>(nb_candidats, 0));
    for(unsigned i = 0; i < votes_exprimes.size(); i = i + nb_candidats){
        for(unsigned j = i ; j < i + nb_candidats && j < votes_exprimes.size(); j = j + 1 ){
            int k = j - i;
            int val_candidat = votes_exprimes[j];
            resultats[val_candidat][k] += 1;
        }
    }
    return resultats;
}

// applique le borda amélioré

vector<int> vote_preferentiel(vector<vector<int>> resultats) {
    vector<int> total_candidat(resultats[0].size(), 0);
    for(unsigned i = 0; i < resultats.size(); i = i + 1){
        for(unsigned j = 0 ; j < resultats[0].size(); j = j + 1){
            total_candidat[i]= total_candidat[i] + pow(resultats.size()-j,2)*resultats[i][j];
            cout<< total_candidat[i] << endl ;
        }
        cout << endl;
    }
    return total_candidat;

}

// trouver le rang du gagnant

int score_premier(vector<int> resultats){
    int score_max;
    int indice_max;
    score_max = resultats[0];
    indice_max = 0;
    for(unsigned i = 1; i < resultats.size(); i++){
        if(resultats[i] > score_max) {
            score_max = resultats[i];
            indice_max = i;
        }
    }
    return indice_max;
}

vector<int> chercheUnEntier (vector<int> scores){
    string chaine;
    while (true){
        getline (cin, chaine);
        if (chaine == "//") break;
        getline (cin, chaine);
        if (chaine == "//") break;
        for (int var = 0; var < 5; ++var) {
            getline (cin, chaine);
            if (chaine != "//") {
                scores.push_back(stoi(chaine)-1);
            }
        }
    }
    return scores;
}

void vote() {

    int nb_candidats = 5;

    vector<int> voteAttribue = {};
    voteAttribue = chercheUnEntier(voteAttribue);

    vector<vector<int>> resultats = compterVoteCandidat(voteAttribue, nb_candidats);

    vector<int> total_candidat= vote_preferentiel(resultats);

    int premier= score_premier(total_candidat);


    for (unsigned i = 0; i < resultats.size(); i=i+1) {
        cout << "cand " << i+1 << " ";


        for (unsigned k = 0; k < resultats[i].size(); k=k+1) {
            cout << resultats[i][k] ;
        }
        cout << endl;
    }

    for (unsigned i =0; i< total_candidat.size(); i=i+1){
        cout << "Le score de : " << i+1 << " vaut "<< total_candidat[i] << endl;
    }


    cout << "Le gagnant est : " << premier+1 << endl;

}



int main()
{
    vote();
    return 0;
}
