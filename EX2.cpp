#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void tri_a_bulle(list<int> &liste) {
    bool echange;
    do {
        echange = false;
        for (auto it = liste.begin(); it != prev(liste.end()); ++it) {
            auto nextIt = next(it);
            if (*nextIt < *it) {
                swap(*nextIt, *it);
                echange = true;
            }
        }
    } while (echange);
}

void tri_par_selection(list<int> &liste) {
    for (auto it = liste.begin(); it != liste.end(); ++it) {
        auto minElement = min_element(it, liste.end());
        swap(*it, *minElement);
    }
}

void tri_par_insertion(list<int> &liste) {
    for (auto it = next(liste.begin()); it != liste.end(); ++it) {
        auto valeur = *it;
        auto j = prev(it);
        while (j != liste.begin() && *j > valeur) {
            *next(j) = *j;
            j = prev(j);
        }
        *next(j) = valeur;
    }
}

int main() {
    list<int> entiers;
    int entree;
    char continuer;

    do {
        cout << "Entrez un entier : ";
        cin >> entree;
        entiers.push_back(entree);

        cout << "Voulez-vous entrer un autre entier ? (o/n) ";
        cin >> continuer;
    } while (continuer == 'o' || continuer == 'O');

    cout << "Liste non triée : ";
    for (const auto &element : entiers) {
        cout << element << " ";
    }
    cout << endl;

    list<int> copie_bulle = entiers;
    tri_a_bulle(copie_bulle);
    cout << "Liste triée par tri à bulle : ";
    for (const auto &element : copie_bulle) {
        cout << element << " ";
    }
    cout << endl;

    list<int> copie_selection = entiers;
    tri_par_selection(copie_selection);
    cout << "Liste triée par tri par sélection : ";
    for (const auto &element : copie_selection) {
        cout << element << " ";
    }
    cout << endl;

    list<int> copie_insertion = entiers;
    tri_par_insertion(copie_insertion);
    cout << "Liste triée par tri par insertion : ";
    for (const auto &element : copie_insertion) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
