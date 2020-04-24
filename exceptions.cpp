/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : exception.cpp
 Auteur(s)   : Paul Reeve, Maxime Scharwath, Thibault Seem
 Date        : 20.04.2020
 But         : Implémentation des classes d'exception
 Remarque(s) : -
 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include "exceptions.h"
using namespace std;

IndiceNonValide::IndiceNonValide(const std::string& s) : logic_error(s){}
IndiceNonValide::IndiceNonValide(const char* s) : logic_error(s) {}

PrixNonValide::PrixNonValide(const std::string& s) : logic_error(s){}
PrixNonValide::PrixNonValide(const char* s) : logic_error(s) {}