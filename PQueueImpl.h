#ifndef PQueueImpl_h
#define PQueueImpl_h

#include "PQueue.h" // inutile mais aide l'IDE à s'y retrouver.

#include <algorithm>
#include <utility>

template < typename T, typename U >
PQueue<T,U>::PQueue(size_t capacity)
{
  data.reserve(capacity);
}

template <typename T, typename U>
template <typename ForwardIterator>
PQueue<T,U>::PQueue(ForwardIterator first,
                  ForwardIterator last)
{
  data.reserve(std::distance(first,last));
  index_type index = 0;
  for(ForwardIterator it = first; it!=last; ++it, ++index)
  {
    data.push_back(std::make_pair((distortion_type)(-(*it)),
                                  (index_type)index));
  }
  std::make_heap(data.begin(), data.end());
}

template < typename T, typename U >
void PQueue<T,U>::push(const index_type& val,
                       const distortion_type& distortion) {
  data.push_back(std::make_pair(-distortion,val));
  std::push_heap(data.begin(),data.end());
}

template < typename T, typename U >
void PQueue<T,U>::pop()
{
  std::pop_heap(data.begin(),data.end());
  data.pop_back();
}

template < typename T, typename U >
const typename PQueue<T,U>::index_type& PQueue<T,U>::top_index() const
{
  return data.at(0).second;
}

template < typename T, typename U >
typename PQueue<T,U>::distortion_type PQueue<T,U>::top_distortion() const
{
  return -(data.at(0).first);
}

template < typename T, typename U >
size_t PQueue<T,U>::size() const
{
  return data.size();
}

template < typename T, typename U >
bool PQueue<T,U>::empty() const
{
  return data.empty();
}

#endif /* PQueueImpl_h */
