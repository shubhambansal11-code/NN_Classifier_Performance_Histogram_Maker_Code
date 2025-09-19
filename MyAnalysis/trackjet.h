//////////////////////////////////////////////////////////
// This class has been written by Bill Murray    6th April 2018
//////////////////////////////////////////////////////////

#ifndef trackjet_h
#define trackjet_h

#include <TLorentzVector.h>
////#include "fatjet.h"
class fatjet;

class trackjet : public TLorentzVector {
 public :
  fatjet * fatjetPointer;
  bool TrackJetPassDR;
  int  TrackJetHadronConeExclTruthLabelID;
  
  int TrackJetIsBTagged_DL1r_FixedCutBEff_85;
  int TrackJetIsBTagged_DL1r_FixedCutBEff_77;
  int TrackJetIsBTagged_DL1r_FixedCutBEff_70;
  int TrackJetIsBTagged_DL1r_FixedCutBEff_60;
    
  trackjet();
  ~trackjet();
  void AddFatJetPointer(fatjet * next);

  ClassDef(trackjet,0);
};

#endif // #ifdef trackjet_h
