// SOLUTION

#ifndef MPQueueImpl_h
#define MPQueueImpl_h

#include "MPQueue.h" // Inutile mais simplifie le travail à l'IDE.
#include <iostream>  // std::cerr
#include <algorithm> // iter_swap

template < typename T, typename U >
MPQueue<T,U>::MPQueue(size_t capacity) {
  data.reserve(capacity);
  heapIndex.reserve(capacity);
}

template < typename T, typename U >
template<typename ForwardIterator>
MPQueue<T,U>::MPQueue(ForwardIterator first, ForwardIterator last) {
  data.reserve(std::distance(first,last));
  heapIndex.reserve(std::distance(first,last));
  index_type index = 0;
  for(ForwardIterator it = first; it!=last; ++it, ++index)
  {
    data.push_back(std::make_pair((distortion_type)(-(*it)),
                                  (index_type)index));
  }
  std::make_heap(data.begin(), data.end());

   // Mise à jour heapIndex
   for(unsigned i = 0; i < data.size(); i++)
   {
      heapIndex[data[i].second] = i;
   }
   
  check_if_is_internally_consistent();
}

template < typename T, typename U >
void MPQueue<T,U>::push(index_type val, distortion_type distortion) {
   data.push_back(std::make_pair(-distortion, val));
   std::push_heap(data.begin(),data.end());
   heapIndex.push_back(-1);
   
   // Mise à jour de heapIndex
   for(unsigned i = 0; i < data.size(); i++)
   {
      heapIndex[data[i].second] = i;
   }
   
   check_if_is_internally_consistent();
}

template < typename T, typename U >
void MPQueue<T,U>::pop() {
   heapIndex.at(data[0].second) = -1;
   std::pop_heap(data.begin(),data.end());
   data.pop_back();
   
   // Mise à jour de heapIndex
   for(unsigned i = 0; i < data.size(); i++)
   {
      heapIndex[data[i].second] = i;
   }
   
   check_if_is_internally_consistent();
}

template < typename T, typename U >
typename MPQueue<T, U>::index_type MPQueue<T,U>::get_top_index() const {
   return data.front().second;
}

template < typename T, typename U >
typename MPQueue<T, U>::distortion_type MPQueue<T,U>::get_top_distortion() const {
   return -data.front().first;
}

template < typename T, typename U >
size_t MPQueue<T,U>::size() const {
   return data.size();
}

template < typename T, typename U >
bool MPQueue<T,U>::empty() const {
   return data.empty();
}

template < typename T, typename U >
typename MPQueue<T, U>::distortion_type MPQueue<T,U>::get_distortion(index_type val) {
   return -data.at(heapIndex.at(val)).first;
}

template < typename T, typename U >
bool MPQueue<T,U>::is_in_queue(index_type val) {
   return (heapIndex.at(val) >= 0);
}

template < typename T, typename U >
void MPQueue<T,U>::change_distortion(index_type val, distortion_type distortion) {
   data.at(heapIndex.at(val)).first = -distortion;
   std::make_heap(data.begin(), data.end());

   // Mise à jour heapIndex
   for(unsigned i = 0; i < data.size(); i++)
   {
      heapIndex[data[i].second] = i;
   }

   check_if_is_internally_consistent();
}

template < typename T, typename U >
void MPQueue<T,U>::sink(index_type pos, index_type heapsize) {
   
  while(2 * pos <= heapsize){
    index_type c = 2 * pos;
    if(c < heapsize && data.at(c).second < data.at(c + 1).second){
      c = c + 1;
    }
    if(data.at(pos).second >= data.at(c).second){
      break;
    }
    std::swap(data.at(pos).second, data.at(c).second);
    pos = c;
  }
   // Mise à jour de heapIndex
   for(unsigned i = 0; i < data.size(); i++)
   {
      heapIndex[data[i].second] = i;
   }
  check_if_is_internally_consistent();
}

template < typename T, typename U >
void MPQueue<T,U>::swim(index_type pos) {
   while(pos > 1 && data.at(pos).second > data.at(pos / 2).second) {
      std::iter_swap(data.begin() + pos, data.begin() + (pos / 2));
      pos /= 2;
   }
   // Mise à jour de heapIndex
   for(unsigned i = 0; i < data.size(); i++)
   {
      heapIndex[data[i].second] = i;
   }
   check_if_is_internally_consistent();
}

template < typename T, typename U >
void MPQueue<T,U>::check_if_is_internally_consistent()
{
  for(size_t i = 0; i < data.size(); ++i) {
    if(heapIndex.at(data[i].second) != i) {
      std::cerr << "error at" << i << " " << data[i].second << " " << heapIndex.at(data[i].second) << std::endl;
    }
  }
  
  for(size_t i = 0; i < heapIndex.size(); ++i) {
    auto j = heapIndex.at(i);
    if(j != -1 and data.at(j).second != i) {
      std::cerr << "error at" << i << " " << data[i].second << " " << j << std::endl;
    }
  }
}

#endif /* MPQueueImpl_h */