#ifndef MPQueue_h
#define MPQueue_h

#include <cstddef>
#include <vector>

template < typename T = size_t , typename U = double >
class MPQueue {
public:
  using index_type = T;
  using distortion_type = U;
  using data_type = std::pair<distortion_type,index_type>;
  
private:
  std::vector<data_type> data;
  std::vector<index_type> heapIndex;

public:
  /**
   Constructeur
   @param capacity capacité du vecteur contenant le tas
   */
  MPQueue(size_t capacity = 0);
  
  /**
   Constructeur a partir d'une séquence de distortions
   
   @param first iterateur sur le debut de la sequence
   @param last iterateur apres la fin de la sequence
   */
  template<typename ForwardIterator>
  MPQueue(ForwardIterator first, ForwardIterator last);
  
  /**
   Ajoute un indice associée à une distortion dans la
   queue de priorite
   
   @param val indice
   @param distortion distortion
   */
  void push(index_type val, distortion_type distortion);
  
  /**
   Retire l'élément a la plus petite distortion
   */
  void pop();
  
  /**
   Accède a l'élément au sommet.
   
   @return retourne l'indice / la distortion au sommet du tas
   */
  index_type get_top_index() const;
  distortion_type get_top_distortion() const;
  
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
  
  /**
   Distortion d'une valeur entree

   @param val valeur dont on cherche la distortion
   @return distortion
   */
   distortion_type get_distortion(index_type val);
  
  /**
   L'indice est-il dans le tas ?

   @param val indice
   @return vrai si l'indice est dans le tas
   */
  bool is_in_queue(index_type val);
  
  /**
   Modifie la distortion d'une valeur

   @param val valeur dont on modifie la distortion
   @param distortion nouvelle distortion
   */
  void change_distortion(index_type val,
                         distortion_type distortion);
  
private:

  /**
   Fait descendre vers le bas du tas si nécessaire

   @param pos position de départ de l'élément à descendre
   */
  void sink(index_type pos, index_type heapsize);
  
  /**
   Fait remonter vers le sommet du tas si nécessaire
   
   @param pos position de départ de l'élément à remonter
   */
  void swim(index_type pos);
  
  void check_if_is_internally_consistent();
};

#include "MPQueueImpl.h"

#endif /* MPQueue_h */