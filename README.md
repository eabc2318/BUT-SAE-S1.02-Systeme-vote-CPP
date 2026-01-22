# BUT-SAE-1.02-Systeme-vote-CPP

# mathias.m2502@gmail.com
# mankaiadam145@gmail.com
# bouyaninho@gmail.com
# aurele.jambert0@gmail.com

Projet pédagogique de système de vote en C++































#include <iostream>
#include <vector>
#include <string>

using namespace std;

string litUneString (){
    string uneChaine;
    while (true){
        getline (cin, uneChaine);
        if ((!cin) || (uneChaine.substr(0,2) != "//")) break;
    }
    return uneChaine;
}

int litUnEntier (){
    string uneChaine;
    while (true){
        getline (cin, uneChaine);
        if ((!cin) || (uneChaine.substr(0,2) != "//")) {
             try {
                return stoi(uneChaine);
             } catch (...) {
                return 0;
             }
        }
    }
    return 0;
}

struct participant {
    string nom;
    string prenom;
    int glacePref;
};

bool compare2part (const participant & p1, const participant & p2){
    return p1.prenom < p2.prenom;
}

void affichVectString (const vector<string> & v){
    for (const string & val : v)
        cout << val << '\t';
    cout << endl;
}

void affichVectParticipants (const vector<participant> & vPart){
    for (const participant & part : vPart){
        cout << part.nom << endl;
        cout << part.prenom << endl;
        cout << part.glacePref << endl;
    }
}

// sert a dire quel quandidiat a combien de voix

vector<int> compterVoteCandidat(vector<int> votes_exprimes, int nb_candidats) {
    vector<int> resultats(nb_candidats, 0);
   
    for(int i = 0; i < votes_exprimes.size(); i++) {
        int id_candidat = votes_exprimes[i];
        if(id_candidat >= 0 && id_candidat < resultats.size()) {
            resultats[id_candidat] = resultats[id_candidat] + 1;
        }
    }
    return resultats;
}

// parcourir un vecteur et trouver le plus grand 

/*vector<int> premierEtDeuxieme(vector<int> vote){

    vector<int> vote_max[0] = vote[0, ];
    vector<int> vote_max[0] = vote[0, ];
    for(int i = 1; i < vote.size(); i++){
        if(vote[i] > vote_max) {
            vote_max[1] = vote[0];
            vote_max[0] = vote[i];           
        }
    }
    return vote_max; 
}*/


vector<int> premierEtDeuxieme(vector<int> vote){
    vector<int> vote_max;
    if(vote[0]>vote[1]){
        vote_max[0] = vote[0]
        vote_max[1] = vote[1]
    } else {
        vote_max[0] = vote[1]
        vote_max[1] = vote[0]
    }
    for(int i = 2; i < vote.size()-1; i++){
        if(vote[i] > vote_max[0]) {
            vote_max[1] = vote[0];
            vote_max[0] = vote[i];           
        } else if (vote[i] > vote_max[1]) {
            vote_max[1] = vote[i]
        }
    }
    return vote_max;
}

// vérifier si un deuxième tour est nécéssaire 

bool verifierSiDeuxiemeTour(int total_vote, int score){
    int majorite = total_vote / 2 + 1;
    if (score >= majorite) {
        return false;
    }
    else {
        return true;
    }
}


vector<int> tab_id(int nb_candidats){
    vector<int> tableau_id;
    for(int i = 0; i < nb_candidats; i++) {
        tableau_id.push_back(i);
    }
    return tableau_id;
}



void vote() {
    int nb_candidats = 5;
   
   
    vector<int> voteAttribue = {0, 0, 1, 1, 0, 1, 0, 1, 2, 4};

    vector<int> voteAttribue2 = {0, 0, 1, 1, 0, 1, 0, 0, 0, 0};

    vector<int> resultats = compterVoteCandidat(voteAttribue, nb_candidats);
   
   
    for(int i=0; i<resultats.size(); i++) {
        cout << "Candidat " << i << " a : " << resultats[i] << " voix." << endl;
    }
   
   
    int score_max = premier(resultats);
   
   
    bool deuxieme_tour = verifierSiDeuxiemeTour(voteAttribue.size(), score_max);
   
    if (deuxieme_tour) {
        cout << "Resultat : pas de majorité, deuxième tour" << endl;
    } else {
        cout << "Resultat : majorité au premier tour" << endl;
    }
}

int main()
{
    vote();
   
    return 0;
}
