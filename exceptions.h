//
// Created by PAUL on 20.04.2020.
//

#ifndef INF_2_LABO_4_EXCEPTIONS_H
#define INF_2_LABO_4_EXCEPTIONS_H

#include <string>
#include <stdexcept> // logic_error

class IndiceNonValide : public std::logic_error
{
public:
   explicit IndiceNonValide(const std::string& s);
   explicit IndiceNonValide(const char* s);
};

class PrixNonValide : public std::logic_error
{
public:
   explicit PrixNonValide(const std::string& s);
   explicit PrixNonValide(const char* s);
};
#endif //INF_2_LABO_4_EXCEPTIONS_H
