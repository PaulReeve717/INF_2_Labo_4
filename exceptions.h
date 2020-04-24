/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : exception.h
 Auteur(s)   : Paul Reeve, Maxime Scharwath, Thibault Seem
 Date        : 20.04.2020
 But         : Implémentation des classes d'exception pour les classes Collections et
               Produit qui héritent de std::logic_error.
               La classe IndiceNonValide contient les méthode suivantes :
               -  IndiceNonValide(const char* s) : Constructeur pour sa classe.
                  Ce constructeur ne fait qu'appeler logic_error de la libraire
                  stdexept, en lui passant un caratère qu'on souhaite remonter
                  avec l'exception.
               -  ndiceNonValde(const std::string& s) : Surcharge du constructeur.
                  Permet de passer un string à la place d'un caractère simple.

               La classe PrixNonValide contient les méthodes suivantes :
               -  PrixNonValide(const char* s) : Constructeur pour sa classe.
                  Ce constructeur ne fait qu'appeler logic_error de la libraire
                  stdexept, en lui passant un caratère qu'on souhaite remonter
                  avec l'exception.
               -  PrixNonValide(const std::string& s) : Surcharge du constructeur.
                  Permet de passer un string à la place d'un caractère simple.

 Remarque(s) : Les constructeurs de la classe IndiceNonValide sont utilisés dans la
               classe Collection lorsque l'indice que l'on passe à une méthode se
               trouve hors de la taille de la table.

               Les constructeurs de la classe PrixNonValide sont utilisés dans la
               classe Produit lorsque le prix d'un produit est mis à une valeur
               inférieur à 5cts.

               Dans le cadre de ce labo, on utilise que le constructeur const char*
               Mais nous avons decidé de garder quand même le constructeur
               const string*

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef INF_2_LABO_4_EXCEPTIONS_H
#define INF_2_LABO_4_EXCEPTIONS_H

#include <string>
#include <stdexcept> // logic_error

class IndiceNonValide : public std::logic_error {
public:
   explicit IndiceNonValide(const std::string& s);

   explicit IndiceNonValide(const char* s);
};

class PrixNonValide : public std::logic_error {
public:
   explicit PrixNonValide(const std::string& s);

   explicit PrixNonValide(const char* s);
};

#endif //INF_2_LABO_4_EXCEPTIONS_H
