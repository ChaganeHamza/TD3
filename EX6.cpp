#include "vect.h"

class vectok : public vect
{
public:
    vectok (int n) : vect(n) {} 

    vectok () : vectok(0) {}

    vectok (const vectok & v) : vectok(v.nelem)
    {
        for (int i = 0; i < nelem; i++)
            adr[i] = v.adr[i];
    }

    vectok & operator = (const vectok & v)
    {
        if (this != &v)
        {
            vectok temp(v);
            std::swap(temp.nelem, nelem);
            std::swap(temp.adr, adr);
        }
        return *this;
    }

    int taille () const { return nelem; }
};

//petit programme d'essai
// fichier main.cpp
#include "vectok.h"

int main ()
{
    vectok v1(10);
    for (int i = 0; i < v1.taille(); i++)
        v1[i] = i;

    vectok v2 = v1;
    for (int i = 0; i < v2.taille(); i++)
        cout << v2[i] << endl;

    return 0;
}