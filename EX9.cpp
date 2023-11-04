// a 
std::cout << "Coordonnees : " << static_cast<int>(p.x) << " " << static_cast<int>(p.y) << "\n";

//b
template <class T> class point
{ int x, y ; // coordonnees
public :
point (T abs, T ord) { x = abs ; y = ord ; }
void affiche () ;
} ;