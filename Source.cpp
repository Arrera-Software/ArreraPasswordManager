#include "CGestionFichier.h"

int main() 
{
    char reponse;
    CGestionFichier gestionnaire;
    do
    {
        cout << "Que voulez vous faire ?" << endl;
        cout << "Ecrire dans le fichier (e)" << endl;
        cout << "Lire le contenue du fichier (l)" << endl;
        cout << "Rechercher un mot (r)" << endl;
        cout << "Effacer le fichier (f)" << endl;
        cout << "Quitter (q)" << endl;
        cin >> reponse;

        switch (reponse)
        {
        case 'e':
        {
            cin.ignore();
            string app, mdp;
            cout << "Pour quelle app/site est votre mot de passe ? :";
            getline(cin, app);
            cout << "Quelle est votre mot de passe ? :";
            getline(cin, mdp);
            gestionnaire.ecriture(app, mdp);
            break;
        }

        case 'l':
        {
            gestionnaire.lecture();
            break;
        }

        case 'r':
        {
            string mot;
            cout << "Entrez le mot a rechercher dans le fichier : ";
            cin >> mot;
            gestionnaire.rechercheMot(mot);
            break;
        }

        case 'f':
        {
            gestionnaire.effacer();
            break;
        }

        case 'q':
        {
            cout << "Aurevoir !";
            break;
        }

        default:
            cout << "Choix invalide." << endl;
        }
    } while (reponse != 'q');
}