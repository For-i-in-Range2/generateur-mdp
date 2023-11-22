#ifndef C_GENERATEUR_MDP_H
#define C_GENERATEUR_MDP_H
#include <iostream>
#include <string>
using namespace std;

class c_generateur_mdp {
private:
    std::string m_alphabet;
    std::string m_mdp;
    unsigned short m_nbMin;
    unsigned short m_nbMax;
    std::string mdp_actu; 

public:
    c_generateur_mdp(std::string &alpha, unsigned short nbmin, unsigned short nbmax);
    bool verifierAlphabet();
    std::string genererMDP();
    bool verifierNbLettres();
    
    void nb_posi(); 
    void generateCombinations(std::string mdp_actu); 
};

#endif

