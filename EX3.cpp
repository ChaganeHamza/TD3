#include <iostream>
#include <list>
#include <algorithm>

struct Person {
    std::string nom;
    std::string prenom;
    int age;

    Person(std::string nom, std::string prenom, int age) : nom(nom), prenom(prenom), age(age) {}

    friend std::ostream& operator<<(std::ostream& os, const Person& p) {
        return os << p.nom << " " << p.prenom << " " << p.age;
    }
};

struct Comparaison {
    bool operator()(const Person& p1, const Person& p2) const {
        int nom_cmp = p1.nom.compare(p2.nom);
        if (nom_cmp != 0) {
            return nom_cmp < 0;
        }
        return p1.prenom.compare(p2.prenom) < 0;
    }
};

int main() {
    std::list<Person> personnes;
    std::string nom, prenom;
    int age;

    while (true) {
        std::cout << "Entrez le nom, prénom et âge (ou entrez 'q' pour quitter) : ";
        std::cin >> nom;
        if (nom == "q") {
            break;
        }
        std::cin >> prenom >> age;
        personnes.push_back(Person(nom, prenom, age));
    }

    personnes.sort(Comparaison());

    std::cout << "Après tri :" << std::endl;
    for (const auto& p : personnes) {
        std::cout << p << std::endl;
    }

    return 0;
}