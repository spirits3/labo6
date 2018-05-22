#include <iostream>
#include <vector>
#include <algorithm>
#include "MPQueue.h"

using namespace std;

double aleatoire() {
  return double(rand())/RAND_MAX;
}

int main() {
  
  size_t N;
  unsigned seed;
  
  cin >> N >> seed;
  srand(seed);
  
  cout << "Remplissage de la PQ" << endl << endl;
  
  MPQueue<size_t> pq(N);
  for(size_t i = 0; i < N; ++i) {
    double p = double(rand())/RAND_MAX;
    cout << fixed << i << " " << p << endl;
    pq.push(i,p);
  }
  
  cout << endl;
  cout << "Affichage des distortions stockees" << endl << endl;

  for(size_t i = 0; i < N; ++i)
    cout << i << " " <<  pq.get_distortion(i) << endl;
  
  cout << endl;
  cout << "Modification des distortions" << endl << endl;

  for(size_t i = 0; i < N; ++i) {
    double p = double(rand())/RAND_MAX;
    size_t j = rand() % N;
    cout << j << " " << p << endl;
    pq.change_distortion(j,p);
  }
  
  cout << endl;
  cout << "Affichage des distortions stockees" << endl << endl;

  for(size_t i = 0; i < N; ++i)
    cout << i << " " <<  pq.get_distortion(i) << endl;

  cout << endl;
  cout << "Suppression des elements par ordre croissant de distortions" << endl << endl;

  while(!pq.empty()) {
    cout << fixed << pq.get_top_index() << " - " << pq.get_top_distortion() << endl;
    pq.pop();
  }
  
  cout << endl;
  cout << "Initialisation d'une nouvelle PQ a partir d'un tableau de distortions" << endl << endl;

  vector<double> errors(N);
  generate(errors.begin(),errors.end(),aleatoire);
  MPQueue<int,float> pq2(errors.begin(),errors.end());
  
  cout << endl;
  cout << "Affichage des distortions stockees" << endl << endl;
  
  for(size_t i = 0; i < N; ++i)
    cout << i << " - " <<  pq2.get_distortion(int(i)) << " == " << errors.at(i) << endl;
  
  cout << endl;
  cout << "Suppression des elements par ordre croissant de distortions" << endl << endl;
  
  while(!pq2.empty()) {
    cout << fixed << pq2.get_top_index()<< " - " << pq2.get_top_distortion() << endl;
    int neighbor = pq2.get_top_index()+1;
    pq2.pop();

    if(pq2.is_in_queue(neighbor)) {
      cout << neighbor << " change de " << pq2.get_distortion(neighbor) << " a ";
      pq2.change_distortion(neighbor,aleatoire());
      cout << pq2.get_distortion(neighbor) << endl;
    }
  }
}