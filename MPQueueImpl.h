// SOLUTION

#ifndef MPQueueImpl_h
#define MPQueueImpl_h

#include "MPQueue.h" // Inutile mais simplifie le travail à l'IDE.
#include <iostream>  // std::cerr
#include <algorithm> // iter_swap

template < typename T, typename U >
MPQueue<T,U>::MPQueue(size_t capacity) {
  data.reserve(capacity);
}

template < typename T, typename U >
template<typename ForwardIterator>
MPQueue<T,U>::MPQueue(ForwardIterator first, ForwardIterator last) {
  data.reserve(std::distance(first,last));
  index_type index = 0;
  for(ForwardIterator it = first; it!=last; ++it, ++index)
  {
    data.push_back(std::make_pair((distortion_type)(-(*it)),
                                  (index_type)index));
  }
  std::make_heap(data.begin(), data.end());

  for(unsigned i = 0; i < heapIndex.size(); i++) {
      for(unsigned j = 0; j < data.size(); j++) {
         if(data[j].second == i) {
            heapIndex[i] = data[j].second;
            break ;
         }
      }
   }
}

template < typename T, typename U >
void MPQueue<T,U>::push(index_type val, distortion_type distortion) {

}

template < typename T, typename U >
void MPQueue<T,U>::pop() {
   std::pop_heap(data.begin(),data.end());
   heapIndex.at(data[data.size()-1].second) = -1;
   data.pop_back();
   
   // Mise à jour de heapIndex
   for(unsigned i = 0; i < heapIndex.size(); i++)
   {
      for(unsigned j = 0; j < data.size(); j++)
      {
         if(data[j].second == i)
         {
            heapIndex[i] = data[j].second;
            break;
         }
      }
   }
}

template < typename T, typename U >
T MPQueue<T,U>::get_top_index() const

{
   return data.front().second;
}

template < typename T, typename U >
U MPQueue<T,U>::get_top_distortion() const {
   return data.at(heapIndex.at((index_type) 0)).first;
}

template < typename T, typename U >
size_t MPQueue<T,U>::size() const {
   return data.size();
}

template < typename T, typename U >
bool MPQueue<T,U>::empty() const {
   return data.size();
}

template < typename T, typename U >
U MPQueue<T,U>::get_distortion(index_type val) {
   return data.at(heapIndex.at(val)).first;
}

template < typename T, typename U >
bool MPQueue<T,U>::is_in_queue(index_type val) {
   return (heapIndex.at(val) >= 0);
}

template < typename T, typename U >
void MPQueue<T,U>::change_distortion(index_type val, distortion_type distortion) {
   
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
    swap(data.at(pos).second, data.at(c)).second;
    pos = c;
  }
}

template < typename T, typename U >
void MPQueue<T,U>::swim(index_type pos) {
   while(pos > 1 && data.at(pos).second > data.at(pos / 2).second) {
      data.iter_swap(data.begin() + pos, data.begin() + (pos / 2));
      pos /= 2;
   }
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