//
// Created by PAUL on 20.04.2020.
//

#include "exceptions.h"
using namespace std;

IndiceNonValide::IndiceNonValide(const std::string& s) : logic_error(s){}
IndiceNonValide::IndiceNonValide(const char* s) : logic_error(s) {}

PrixNonValide::PrixNonValide(const std::string& s) : logic_error(s){}
PrixNonValide::PrixNonValide(const char* s) : logic_error(s) {}