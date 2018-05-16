// SOLUTION

#ifndef MPQueueImpl_h
#define MPQueueImpl_h

#include "MPQueue.h" // Inutile mais simplifie le travail à l'IDE.
#include <iostream>  // std::cerr

template < typename T, typename U >
MPQueue<T,U>::MPQueue(size_t capacity) {

}

template < typename T, typename U >
template<typename ForwardIterator>
MPQueue<T,U>::MPQueue(ForwardIterator first, ForwardIterator last) {

}


template < typename T, typename U >
void MPQueue<T,U>::push(index_type val, distortion_type distortion) {

}

template < typename T, typename U >
void MPQueue<T,U>::pop() {

}

template < typename T, typename U >
index_type MPQueue<T,U>::get_top_index() const
{
   
   
}

template < typename T, typename U >
distortion_type MPQueue<T,U>::get_top_distortion() const {
   
}

template < typename T, typename U >
size_t MPQueue<T,U>::size() const {
   
}

template < typename T, typename U >
bool MPQueue<T,U>::empty() const {
   
}

template < typename T, typename U >
distortion_type MPQueue<T,U>::get_distortion(index_type val) {
   
}

template < typename T, typename U >
bool MPQueue<T,U>::is_in_queue(index_type val) {
   
}

template < typename T, typename U >
void MPQueue<T,U>::change_distortion(index_type val, distortion_type distortion) {
   
}

template < typename T, typename U >
void MPQueue<T,U>::sink(index_type pos, index_type heapsize) {
   
}

template < typename T, typename U >
void MPQueue<T,U>::swim(index_type pos) {
   
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