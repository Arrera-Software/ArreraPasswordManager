#include "CGestionFichier.h"

CGestionFichier::CGestionFichier()
{

}

CGestionFichier::~CGestionFichier()
{

}

int CGestionFichier::ecriture(string app, string mdp)
{
    ofstream fichier(nomFichier, ios_base::app);

    if (!fichier.is_open()) 
    {
        cerr << "Erreur : Impossible d'ouvrir le fichier en ecriture." << endl;
        return 1;
    }

    fichier << app << '$' << mdp << endl;
    fichier.close();
    cout << "Ecriture dans le fichier terminee." << endl;
    return 0;
}

int CGestionFichier::lecture()
{
    ifstream fichier("output.txt");

    if (!fichier.is_open()) 
    {
        cerr << "Erreur : Impossible d'ouvrir le fichier en lecture." << endl;
        return 1;
    }

    string ligne;
    cout << "Contenu du fichier :" << endl;
    while (getline(fichier, ligne)) 
    {
        cout << ligne << endl;
    }

    fichier.close();
    return 0;
}

int CGestionFichier::rechercheMot(string mot)
{
    ifstream fichier(nomFichier);

    if (!fichier.is_open()) {
        cerr << "Erreur : Impossible d'ouvrir le fichier en lecture." << endl;
        return 1;
    }

    string ligne;
    bool trouve = false;
    while (getline(fichier, ligne)) {
        // Convertir la ligne en minuscules
        transform(ligne.begin(), ligne.end(), ligne.begin(), ::tolower);
        // Convertir le mot recherché en minuscules
        transform(mot.begin(), mot.end(), mot.begin(), ::tolower);
        if (ligne.find(mot) != string::npos) {
            cout << "Mot trouvé dans la ligne : " << ligne << endl;
            trouve = true;
        }
    }

    if (!trouve) {
        cout << "Le mot n'a pas été trouvé dans le fichier." << endl;
    }

    fichier.close();
    return 0;
}

int CGestionFichier::effacer()
{
    if (remove(nomFichier.c_str()) != 0) {
        cerr << "Erreur : Impossible de supprimer le fichier." << endl;
        return 1;
    }

    cout << "Le fichier a ete supprime avec succes." << endl;
    return 0;
}
