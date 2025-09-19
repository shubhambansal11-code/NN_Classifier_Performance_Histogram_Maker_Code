#ifndef photon_h
#define photon_h

#include <TLorentzVector.h>

class fatjet;

class photon : public TLorentzVector {
 public :
  fatjet * fatjetPointer;

  photon();
  ~photon();
  void AddFatJetPointer(fatjet * next);
  
  ClassDef(photon,0);
};

#endif // #ifdef photon_h
