#include <iostream>
#include <stdexcept>
using namespace std;

class Test{
    public:
    static int tableau[] ;
    public:
    static int division(int indice, int diviseur){
        if(diviseur == 0){
            throw invalid_argument("Le diviseur ne peut pas être égal à zéro.");
        }
        if(indice < 0 || indice >= sizeof(tableau) / sizeof(tableau[0])){
            throw out_of_range("L'indice est hors des limites du tableau.");
        }
        return tableau[indice]/diviseur;
    }
};

int Test::tableau[] = {17, 12, 15, 38, 29, 157, 89, -22, 0, 5} ;

int main() {
    int x, y;
    cout << "Entrez l’indice de l’entier à diviser: " << endl;
    cin >> x ;
    cout << "Entrez le diviseur: " << endl;
    cin >> y ;
    try {
        cout << "Le résultat de la division est: "<< endl;
        cout <<Test::division(x,y) << endl;
    } catch (const invalid_argument& e) {
        cerr << "Erreur: " << e.what() << endl;
        return 1;
    } catch (const out_of_range& e) {
        cerr << "Erreur: " << e.what() << endl;
        return 1;
    }
    return 0;
}
