/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : collection_g.h
 Auteur(s)   : Paul Reeve, Maxime Scharwath, Thibault Seem
 Date        : 20.04.2020
 But         : Déclaration et implémentation de la classe collection permettant
               de stocker des élément génériques sous forme de table.
               La classe Collection contient les méthodes suivantes :
               -  std::ostream &operator<<
                  (std::ostream &os, const Collection<T, Container> &c) :
                  Surcharge de l'opérateur d'écriture sur un flux "<<" afin de
                  pouvoir écrire une table générique sur le flux sous la forme :
                  [element1, element2, ...]
               -  void ajouter(const T &valeur) : Permet d'ajouter un élément de
                  type T à la table de l'objet de type Collection.
               -  size_t taille() const : retourne la taille de la table contenue
                  dans l'objet de type Collection.
               -  T &get(size_t index) : Retourne l'élément à l'emplacement indiqué
                  par size_t index. Si l'index fournit en paramètre est supérieur à
                  la taille de la table, une exception de type IndiceNonValide est
                  lancée (cf. exception.h).
               -  bool contient(const T &valeur) const : Retourne true si l'élément
                  valeur est présent dans la table de l'objet de type Collection,
                  et true si l'élément n'est pas présent.
               -  void vider() : Supprime tous les éléments dans la table de l'objet.
               -  void parcourir(std::function<void(T&)> fn) : Applique la fonction
                  fn à tous les éléments de la table de l'objet.
 Remarque(s) : -
 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef INF_2_LABO_4_COLLECTION_G_H
#define INF_2_LABO_4_COLLECTION_G_H

#include <algorithm>
#include <iterator>
#include <functional>
#include <iostream>
#include "exceptions.h"

template <typename T, template <typename, typename=std::allocator<T>> class Container>
class Collection;

template <typename T, template <typename, typename=std::allocator<T>> class Container>
std::ostream& operator<<(std::ostream& os, const Collection<T, Container>& c) {
   os << '[';
   for (auto i = c.data.begin(); i != c.data.end(); ++i) {
      if (i != c.data.begin()) {
         os << ", ";
      }
      os << *i;
   }
   os << ']';
   return os;
}

template <typename T, template <typename, typename=std::allocator<T>> class Container>
class Collection {
   friend std::ostream& operator<< <>(
         std::ostream& os,
         const Collection<T, Container>& c
   );

public:
   void ajouter(const T& valeur) {
      data.push_back(valeur);
   }

   size_t taille() const {
      return (size_t) distance(data.begin(), data.end());
   }

   T& get(size_t index) {
      if (index >= taille()) {
         throw IndiceNonValide(
               "Erreur dans Collection::get : \n"
               "n doit etre strictement plus petit que collection.size()"
               );
      }

      auto it = data.begin();
      for (size_t i = 0; i != index && it != data.end(); ++i, ++it);
      return *it;
   }

   bool contient(const T& valeur) const {
      return find(data.begin(), data.end(), valeur) != data.end();
   }

   void vider() {
      data.clear();
   }

   void parcourir(std::function<void(T&)> fn) {
      std::for_each(data.begin(), data.end(), fn);
   }

private:
   Container<T> data;
};

#endif //INF_2_LABO_4_COLLECTION_G_H
