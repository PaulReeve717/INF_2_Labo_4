//
// Created by PAUL on 20.04.2020.
//

#ifndef INF_2_LABO_4_COLLECTION_G_H
#define INF_2_LABO_4_COLLECTION_G_H

#include <algorithm>
#include <iostream>
#include "exceptions.h"
template<typename T, template<typename, typename=std::allocator<T>> class Container> class Collection;

template<typename T, template<typename, typename=std::allocator<T>> class Container>
std::ostream &operator<<(std::ostream &os, const Collection<T, Container>& c) {
   os << '[';
   for (size_t i = 0; i < c.data.size(); ++i) {
      if (i > 0) {
         os << ", ";
      }
      os << c.data[i];
   }
   os << ']';
   return os;
}

template<typename T, template<typename, typename=std::allocator<T>> class Container>
class Collection
{
   friend std::ostream &operator<< <>(std::ostream &os, const Collection<T, Container>& c);
public:


   void ajouter(const T& valeur)
   {
      data.push_back(valeur);
   }
   size_t taille() const
   {
      return data.size();
   }
   T& get(size_t index)
   {
      if(index >= data.size()){
         throw IndiceNonValide("Erreur dans Collection::get : "
                                  "n doit etre strictement plus petit que collection.size()");
      }
      return data.at(index);
   }

   bool contient(const T& valeur) const
   {
      return find(data.begin(), data.end(), valeur) != data.end();
   }

   void vider()
   {
      data.clear();
   }

   void parcourir() const
   {

   }//TODO: args


private:
   Container<T> data;
};





#endif //INF_2_LABO_4_COLLECTION_G_H
