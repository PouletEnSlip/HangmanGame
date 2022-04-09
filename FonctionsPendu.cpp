#include <iostream>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include "FonctionsPendu.h"

using namespace std;

CJeuPendu::CJeuPendu()
{
    tentative = 0;
    strcpy(mot7lettres[0],"CARREAU");
    strcpy(mot7lettres[1],"COULOIR");
    strcpy(mot7lettres[2],"DOSSIER");
    strcpy(mot7lettres[3],"FENETRE");
    strcpy(mot7lettres[4],"MATELAS");
    strcpy(mot7lettres[5],"PELUCHE");
    strcpy(mot7lettres[6],"ADOPTER");
    strcpy(mot7lettres[7],"ALIMENT");
    strcpy(mot7lettres[8],"BLANCHI");
    strcpy(mot7lettres[9],"BRILLER");
    strcpy(mot7lettres[10],"CAILLOU");
    strcpy(mot7lettres[11],"CACHETE");
    strcpy(mot7lettres[12],"DESIRER");
    strcpy(mot7lettres[13],"DILATER");
    strcpy(mot7lettres[14],"ECHOPPE");
    strcpy(mot7lettres[15],"FEVRIER");
    strcpy(mot7lettres[16],"GAUCHER");
    strcpy(mot7lettres[17],"GLUCIDE");
    strcpy(mot7lettres[18],"GONFLER");
    strcpy(mot7lettres[19],"HONORER");
    strcpy(mot7lettres[20],"INERTIE");
    strcpy(mot7lettres[21],"JAVELOT");
    strcpy(mot7lettres[22],"LAVANDE");
    strcpy(mot7lettres[23],"MONNAIE");
    strcpy(mot7lettres[24],"NATUREL");
    strcpy(mot7lettres[25],"REBELLE");
    strcpy(mot7lettres[26],"SCINDER");
    strcpy(mot7lettres[27],"SERVICE");
    strcpy(mot7lettres[28],"VOYAGER");
    strcpy(mot7lettres[29],"ZEZETTE");
    strcpy(mot7lettres[30],"MARTEAU");
}

CJeuPendu::~CJeuPendu()
{
}

unsigned short CJeuPendu::getTentative()
{
    return tentative;
}

void CJeuPendu::setTentative(unsigned short essai)
{
    tentative = essai;
}

char* CJeuPendu::motSecret()
{
    srand(time(NULL));
    short i = rand() %31;
    strcpy (secretWord, mot7lettres[i]);
}

char* CJeuPendu::motATrouver()
{
    strcpy(motATrouve,"*******");
    return motATrouve;
}

bool CJeuPendu::Proposer(char letter)
{
    bool present = false;
    for (short i = 0; i <= 7; i++)
    {
        if (secretWord[i] == letter)
        {
            motATrouve[i] = letter;
            present = true;
        }
    }

    if (present == false)
    {
        cout << "La lettre : " << letter << " n'est pas dans le mot !" << endl;
    }
    else
    {
        cout << "La lettre : " << letter << " est dans le mot !" << endl;
    }
    Sleep(1500);
    return letter;
}

char* CJeuPendu::getMotSecret()
{
    return secretWord;
}

char* CJeuPendu::getMotATrouve()
{
    return motATrouve;
}
