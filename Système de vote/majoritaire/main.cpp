#include <iostream>
#include <vector>
#include <string>

using namespace std;


// sert a dire quel candidiat a combien de voix

vector<int> compterVoteCandidat(vector<int> votes_exprimes, int nb_candidats) {
    vector<int> resultats(nb_candidats, 0);
    for(unsigned i = 0; i < votes_exprimes.size(); i++) {
        unsigned id_candidat = votes_exprimes[i];
        resultats[id_candidat] = resultats[id_candidat] + 1;
    }
    return resultats;
}

// parcourir un vecteur et trouver le premier et le second candidiat au second tour

vector<int> premierEtDeuxieme(vector<int> vote){
    vector<int> vote_max(2);
    vector<int> numero_participant(2);
    if(vote[0]>vote[1]){
        vote_max[0] = vote[0];
        vote_max[1] = vote[1];
        numero_participant[0]=0;
        numero_participant[1]=1;
    } else {
        vote_max[0] = vote[1];
        vote_max[1] = vote[0];
        numero_participant[0]=1;
        numero_participant[1]=0;
    }
    for(unsigned i = 2; i < vote.size(); i++){
        if(vote[i] > vote_max[0]) {
            vote_max[1] = vote_max[0];
            numero_participant[1]=numero_participant[0];
            vote_max[0] = vote[i];
            numero_participant[0]=i;
        } else if (vote[i] > vote_max[1]) {
            vote_max[1] = vote[i];
            numero_participant[1] = i;
        }
    }
    return numero_participant;
}

//trouver la plus grosse valeur dans une liste

int score_premier(vector<int> vote){
    int vote_max;
    vote_max = vote[0];
    for(unsigned i = 1; i < vote.size(); i++){
        if(vote[i] > vote_max) {
            vote_max = vote[i];
        }
    }
    return vote_max;
}



// vérifier si un deuxième tour est nécéssaire

bool verifierSiDeuxiemeTour(int total_vote,int score_max){
    int majorite = total_vote / 2 + 1;
    if (score_max >= majorite) {
        return false;
    }
    else {
        return true;
    }
}



// premier au deuxieme tour

int compterVoteCandidat2(vector<int> votes_exprimes, vector<int> gagnants_du_premier_et_deuxieme) {
    vector<int> resultats(2, 0);

    for(unsigned i = 1; i < votes_exprimes.size(); i = i + 1) {

        if(votes_exprimes[i] == gagnants_du_premier_et_deuxieme[0]){
            resultats[0]= resultats[0] + 1;
        }
        else if(votes_exprimes[i] == gagnants_du_premier_et_deuxieme[1]){
            resultats[1]= resultats[1] + 1;
        }
    }
    if(resultats[0]>resultats[1]){
        return gagnants_du_premier_et_deuxieme[0];
    }else{
        return gagnants_du_premier_et_deuxieme[1];
    }
}


vector<int> chercheUnEntier (vector<int> scores){
    string chaine;
    while (true){
        getline (cin, chaine);
        if (chaine == "//") break;
        getline (cin, chaine);
        if (chaine == "//") break;
        getline (cin, chaine);
        if (chaine != "//") {
            scores.push_back(stoi(chaine)-1);
        }
    }
    return scores;
}

void vote() {

    int nb_candidats = 5;

    string poubelle;
    for (unsigned i (0); i < 4; ++i){
        getline(cin, poubelle);}

    vector<int> voteAttribue = {};
    voteAttribue = chercheUnEntier(voteAttribue);

    vector<int> voteAttribue2 = {};
    voteAttribue2 = chercheUnEntier(voteAttribue);

    vector<int> resultats = compterVoteCandidat(voteAttribue, nb_candidats);

    vector<int> score_du_premier_et_deuxieme = premierEtDeuxieme(resultats);


    for(unsigned i=0; i<resultats.size()-1; i++) {
        cout << "Candidat " << i+1 << " a : " << resultats[i] << " voix." << endl;
    }



    int score_max = score_premier(resultats);

    bool deuxieme_tour = verifierSiDeuxiemeTour(voteAttribue.size(), score_max);

    if (deuxieme_tour) {
        cout << "Resultat : pas de majorité, deuxième tour" << endl;
        for(int i=0; i<2; i++) {
            cout << "gagnant du premier tour : " << score_du_premier_et_deuxieme[i]+1 <<endl ;
        }
    } else {
        cout << "Resultat : majorité au premier tour" << endl;
        cout << "gagnant du vote par majorité :  " <<score_du_premier_et_deuxieme[0] <<endl;

    }


    if (deuxieme_tour){
        int resultats2 = compterVoteCandidat2(voteAttribue2, score_du_premier_et_deuxieme);
        cout << "gagnant du vote :  " <<resultats2+1 <<endl;
    }
}

int main()
{
    vote();
    return 0;
}
