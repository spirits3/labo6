#include <iostream>
#include <algorithm>
#include <vector>
#include "PQueue.h"

using namespace std;

double aleatoire() {
  return double(rand())/RAND_MAX;
}

int main() {
 
  size_t N;
  unsigned seed;
  cin >> N >> seed;
  srand(seed);
  
  PQueue<size_t> pq(N);
  for(size_t i = 0; i < N; ++i)
    pq.push(i,aleatoire());
  
  while(!pq.empty()) {
    cout << fixed << pq.top_index() << " - "
         << pq.top_distortion() << endl;
    pq.pop();
  }
  
  cout << endl;
  
  vector<double> priorities(N);
  generate(priorities.begin(),priorities.end(),aleatoire);
  PQueue<size_t> pq2(priorities.begin(),priorities.end());
  
  while(!pq2.empty()) {
    cout << fixed << pq2.top_index() << " - "
         << pq2.top_distortion() << endl;
    pq2.pop();
  }
}
