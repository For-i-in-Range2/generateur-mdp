#include "c_generateur_mdp.h"
#include <cstdlib>
#include <string> 
#include<math.h>
#include <cmath>
#include<iostream>
using namespace std;
c_generateur_mdp::c_generateur_mdp(string &alpha, unsigned short nbmin, unsigned short nbmax)
{
	m_alphabet=alpha;
	m_nbMin=nbmin;
	m_nbMax=nbmax;
}

bool c_generateur_mdp::verifierAlphabet()
{
	// Code vérifiant la validité de l'alphabet, retourne vrai si c'est bon
	char chiffre[10]={'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'}; 
	char MAJ[26]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 
	'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	auto espa = m_alphabet.find(' ');
	//si longueur de mdp compris entre 8 et 15
	if (m_nbMin >=8 && m_nbMax<=15) {
		
		//on recherche les potentiels espaces
		if (espa != string::npos){
		
			cout << "PAS D'ESPACE!" <<endl;
			return false;
		}
		
		// on vérifie s'il y a bien des chiffres et des majuscules
        	bool contientChiffre = false;
        	bool contientMajuscule = false;
        
        	for (int i = 0; i < 10; ++i) {
            	    if (m_alphabet.find(chiffre[i]) != string::npos) {
                        contientChiffre = true;
                        break;  // On a trouvé un chiffre, on peut sortir de la boucle
                    }
                }
        
        	for (int i = 0; i < 26; ++i) {
            		if (m_alphabet.find(MAJ[i]) != string::npos) {
                	    contientMajuscule = true;
                	    break;  // On a trouvé une majuscule, on peut sortir de la boucle
            		}
        	}
        return contientChiffre && contientMajuscule;
        
	} else if(m_nbMin >15){
		if (espa != string::npos){
			cout << "PAS D'ESPACE!" <<endl;
			return false;}
		else {
			return true;}
	}
return false;}

string c_generateur_mdp::genererMDP()
{
	// Code générant le mot de passe aléatoirement en fonction de l'alphabet fourni et des nombre min et max de caractères
	srand (time(NULL));
	int max = m_alphabet.size()-1;
	int min = 0;
	int taille_mdp = rand() % 8+max;
	for (int i=0; i<taille_mdp; ++i) {
		int alea = (rand() % (max - min + 1)) + min;
		m_mdp=m_mdp+m_alphabet[alea];
	}
	cout << m_mdp << endl;
	return m_mdp;
}

bool c_generateur_mdp::verifierNbLettres()
{
	// Code vérifiant que le max est supérieur au min, retourne vrai si c'est bon
	if (m_nbMin <8 or m_nbMax > 30){
		return false;
	}
	else {
		return true;
	}
return true;}

void c_generateur_mdp::nb_posi() {
    int posi = m_alphabet.size();
    int nb_posibilite = 0;
    for (int i = 2; i <= 30; ++i) {
        nb_posibilite = nb_posibilite + std::pow(posi, i);
    }
    std::cout << "On peut faire: " << nb_posibilite << " combinaisons de 2 à 30 caractères" << std::endl;
}

void c_generateur_mdp::generateCombinations(std::string mdp_actu) {
    if (mdp_actu.length() >= m_nbMin && mdp_actu.length() <= m_nbMax) {
        std::cout << mdp_actu << std::endl;
    }

    if (mdp_actu.length() < m_nbMax) {
        for (char c : m_alphabet) {
            generateCombinations(mdp_actu + c);
        }
    }
}




















