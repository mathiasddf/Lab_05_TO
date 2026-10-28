#include <iostream>
using namespace std;

// Plantilla generica
template <class T>
class Contendor {
    T elemento;
public:
    Contendor(T arg) { elemento = arg; }
    T add() { return ++elemento; }
};

// Especializacion de plantilla para el tipo char
template <>
class Contendor <char> {
    char elemento;
public:
    Contendor(char arg) { elemento = arg; }
    char uppercase()
    {
        if ((elemento >= 'a') && (elemento <= 'z')) {
            elemento += 'A' - 'a';
        }
        return elemento;
    }
};

int main() {
    Contendor<int> cint(5);
    Contendor<char> cchar('t');
    std::cout << cint.add() << std::endl;
    std::cout << cchar.uppercase() << std::endl;
    return 0;
}
