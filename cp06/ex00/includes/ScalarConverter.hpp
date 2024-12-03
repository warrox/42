

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
private:
    // Constructeurs et destructeurs privés pour empêcher l'instanciation
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter&);
    ScalarConverter& operator=(const ScalarConverter&);

public:
    // Méthode publique statique
    static void convert(const std::string& literal);

private:
    // Fonctions utilitaires
    static void printChar(char value);
    static void printInt(int value);
    static void printFloat(float value);
    static void printDouble(double value);
    static void printPseudoLiteral(const std::string& pseudoLiteral);
};

#endif
