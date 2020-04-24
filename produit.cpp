/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : produit.cpp
 Auteur(s)   : Paul Reeve, Maxime Scharwath, Thibault Seem
 Date        : 20.04.2020
 But         : Implémentation de la classe Produit, et de ses différentes fonctions.
 Remarque(s) : -
 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#include "produit.h"
#include "exceptions.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Constructeur de la classe Produit
Produit::Produit(size_t numero, const std::string& libelle, double prix) {
   if (prix < 0.05) {
      throw PrixNonValide("Erreur dans Produit::Produit : "
                          "\nle prix doit etre >= 5 cts !");
   }
   this->numero = numero;
   this->libelle = libelle;
   this->prix = prix;
}

// Surcharge de l'opérateur sur un flux "<<" afin d'afficher le numéro, le libellé
// et le prix du produit
std::ostream& operator<<(std::ostream& lhs, const Produit& rhs) {
   lhs << "(" << rhs.numero << ", \""
       << rhs.libelle << "\", "
       << fixed << setprecision(2) << rhs.prix << ")";
   return lhs;
}


//Opérateur de compraison " == " afin de tester si deux produits sont identiques
bool operator==(const Produit& lhs, const Produit& rhs) {
   return lhs.numero == rhs.numero
          && lhs.libelle == rhs.libelle
          && lhs.prix == rhs.prix;
}

// Méthode permettant de définir une nouvelle valeur pour le prix.
void Produit::setPrix(double nouveauPrix) {
   if (nouveauPrix < 0.05) {
      throw PrixNonValide("Erreur dans Produit::setPrix : "
                          "\nle prix doit etre >= 5 cts !");
   }
   prix = nouveauPrix;
}

// Méthode permettant de calculer une majoration sur le prix du produit
void Produit::majoration(double pourcent) {
   prix += prix * (pourcent / 100.0);
}