#ifndef muon_h
#define muon_h

#include <TLorentzVector.h>

class fatjet;

class muon : public TLorentzVector {
 public :
  fatjet * fatjetPointer;
  char quality;
 
  muon();
  ~muon();
  void AddFatJetPointer(fatjet * next);
  
  ClassDef(muon,0);
};

#endif // #ifdef muon_h
