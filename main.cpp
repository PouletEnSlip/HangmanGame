/*
    Nom : main.cpp
    Sujet : Jeu du pendu
    Créateur : Léo Seguin
    Date : 25/01/21
*/

#include <iostream>
#include <windows.h>
#include <string>
#include "FonctionsPendu.h"

using namespace std;

CJeuPendu pendu;

int main()
{
    string propLettre;

    string nom;
    char lettre;
    short tentatives;
    short countTentative = 0;

    system("CLS");

    cout << "Jeu du pendu" << endl;
    cout << "Saisissez votre prenom : ";
    cin >> nom;
    cout << "Saisissez le nombre de tentatives maximum : ";
    cin >> tentatives;
    propLettre.clear();
    pendu.setTentative(tentatives);
    pendu.motSecret();
    pendu.motATrouver();

    while (strcmp(pendu.getMotSecret(), pendu.getMotATrouve()))
    {
        replayLetter:

        system("CLS");
        cout << "Jeu du pendu" << endl;
        cout << "Le mot a trouver est : " << pendu.getMotATrouve() << endl;
        cout << "Lettres absentes : " << propLettre << endl;
        cout << "Tentatives : " << countTentative << "/" << pendu.getTentative() << endl;
        cout << "Proposez une lettre : ";
        cin >> lettre;

        for (short i = 0; i <= countTentative - 1; i++)
        {
            if (lettre == propLettre[i])
            {
                cout << "Vous avez deja joue cette lettre..." << endl;
                Sleep(2500);
                goto replayLetter;
            }
        }
        propLettre = propLettre + lettre;
        pendu.Proposer(lettre);
        countTentative++;

        if (countTentative >= pendu.getTentative())
        {
            system("CLS");
            cout << "Perdu ! Recomencez..." << endl;
            system("PAUSE");
            return main();
        }
    }
    system("CLS");
    cout << "Bravo " << nom << " !!!" << endl;
    system("PAUSE");
    return main();
}
