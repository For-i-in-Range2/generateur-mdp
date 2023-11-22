#include <iostream>
#include "c_generateur_mdp.h"
using namespace std;
int main(){
    string alpha = "";
    cout << "Fournir un alphabet : " << std::endl;
    getline(std::cin, alpha);
    unsigned short a = 0;
    unsigned short b = 0;
    cout << "Taille min de votre mdp?" << std::endl;
    cin >> a;
    cout << "Taille max de votre mdp?" << std::endl;
    cin >> b;
    c_generateur_mdp mdp1(alpha, a, b);
    
    bool verifNb = mdp1.verifierNbLettres();
    bool verifAl = mdp1.verifierAlphabet();
    
    if (verifNb) { 
        cout << "Vérif taille ok début phase2" << std::endl;
        if (verifAl){
            cout << "Vérif alphabet ok début phase3" << std::endl;
            mdp1.genererMDP();
        }
        else{
            cout << "Majuscules et chiffres obligatoires si longueur 8-15 caractères | Pas d'espace autorisé " << std::endl;
        }
    }
    else{
        cout << "Mot de passe trop court ou trop long" <<std::endl;
    }

    mdp1.nb_posi(); 
    mdp1.generateCombinations("");

    return 0;
}
