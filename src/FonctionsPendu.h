#include <string>
#ifndef FONCTIONSPENDU_H
#define FONCTIONSPENDU_H

class CJeuPendu
{
    private:
        char mot7lettres[31][8];
        char secretWord[8];
        char motATrouve[8];
        unsigned short tentative;

    public:
        CJeuPendu();
        ~CJeuPendu();
        char* motSecret();
        char* motATrouver();
        char* getMotSecret();
        char* getMotATrouve();
        unsigned short getTentative();
        void setTentative(unsigned short essai);
        bool Proposer(char letter);
};

#endif // FONCTIONSPENDU_H
