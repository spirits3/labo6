#ifndef PQueue_h
#define PQueue_h

#include <vector>
#include <utility>

template < typename T = size_t , typename U = double >
class PQueue {
public:
  using index_type = T;
  using distortion_type = U;
  using data_type = std::pair<distortion_type,index_type>;
  
private:
  std::vector<data_type> data;
  
public:
  /**
   Constructeur
   @param capacity capacité du vecteur contenant le tas
   */
  PQueue(size_t capacity = 0);
  
  /**
   Constructeur a partir d'une séquence de distortions
   
   @param first iterateur sur le debut de la sequence
   @param last iterateur apres la fin de la sequence
   */
  template<typename ForwardIterator>
  PQueue(ForwardIterator first, ForwardIterator last);
  
  /**
   Ajoute un indice associé à une distortion dans la
   queue de priorite

   @param index indice
   @param distortion distortion
   */
  void push(const index_type& index, const distortion_type& distortion);
  
  /**
   Retire l'élément le plus prioritaire (distortion la plus petite)
   */
  void pop();

  /**
   Accède a l'élément au sommet.

   @return retourne l'indice / la distortion au sommet du tas
   */
  const index_type& top_index() const;
  distortion_type top_distortion() const;

  /**
   Taille de la PQueue

   @return nombre d'éléments
   */
  size_t size() const;
  
  /**
   La PQueue est-elle vide ?

   @return booléen vide (true) ou pas (false).
   */
  bool empty() const;
};

#include "PQueueImpl.h"

#endif /* PQueue_h */
