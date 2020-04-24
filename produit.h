/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : produit.h
 Auteur(s)   : Paul Reeve, Maxime Scharwath, Thibault Seem
 Date        : 20.04.2020
 But         : La classe Produit regroupe les fonctions suivantes :
               -  std::ostream& operator<<(std::ostream& lhs, const Produit& rhs) :
                  Surcharge de l'opérateur de flux "<<" pour afficher
                  les informations du produit sous la forme suivante :
                  (n°, "libellé", prix)
               -  bool operator==(const Produit& lhs, const Produit& rhs);
                  Opérateur de comparaison "==" afin de voir si deux produits sont
                  identiques.
               -  Produit(size_t numero, std::string libelle, double prix) :
                  Un constructeur prenant 3 paramètres en entrée : un entier pour le
                  numéro du produit, un string pour le libbelé et un double pour
                  le prix. Si le prix reçu en paramètre est inférieur à 5cts,
                  une exception PrixNonValide est lancée (cf. exceptions.h)
               -  void setPrix(double nouveauPrix) : accesseur permettant de définir
                  le prix du produit. Si le prix est inférieur à 5cts, une exception
                  de type PrixNonValide est lancée (cf. exceptions.h).
               -  void majoration(double pourcent) : Une méthode permettant de
                  majorer le prix de l'objet d'un certain pourcent.
 Remarque(s) : -
 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef INF_2_LABO_4_PRODUIT_H
#define INF_2_LABO_4_PRODUIT_H

#include <string>
#include <iostream>


class Produit {

   /**
    * Surcharge de l'opérateur sur un flux "<<" afin d'afficher le numéro, le libellé
    * et le prix du produit
    *
    * @param lhs  : Flux sur lequel on veut écrire
    * @param rhs  : Produit qu'on souhaite afficher
    * @return     : Flux sur lequel on écrit
    */
   friend std::ostream& operator<<(std::ostream& lhs, const Produit& rhs);

   /**
    * Opérateur de compraison " == " afin de tester si deux produits sont identiques
    *
    * @param lhs  : Premier produit à comparer
    * @param rhs  : Deuxième produit à comparer
    * @return     : Résultat de la comparaison : renvoie true si les deux produits
    *               sont identiques
    *               renvoie false si les deux produits sont différents
    */
   friend bool operator==(const Produit& lhs, const Produit& rhs);


public:
   /**
    * Constructeur de la classe Produit
    *
    * @param numero  : Numéro du produit créé
    * @param libelle : Libellé attaché au produit.
    * @throws        : PrixNonValide::PrixNonValide si le prix est inférieur ou égal
    *                  à 5cts
    * @param prix    : Prix du produit
    */
   Produit(size_t numero, const std::string& libelle, double prix);

   /**
    * Méthode permettant de définir une nouvelle valeur pour le prix.
    *
    * @param nouveauPrix   : Nouveau prix à pour le produit
    * @throws              : PrixNonValide::PrixNonValide si le prix est inférieur
    *                        ou égal à 5cts
    */
   void setPrix(double nouveauPrix);

   /**
    * Méthode permettant de calculer une majoration sur le prix du produit
    *
    * @param pourcent   : Pourcentage dont on veut majorer le prix
    */
   void majoration(double pourcent);

private:
   size_t numero;
   std::string libelle;
   double prix;
};

#endif //INF_2_LABO_4_PRODUIT_H


