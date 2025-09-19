#ifndef fatjet_h
#define fatjet_h

#include "trackjet.h"
#include "muon.h"
#include "photon.h"
#include <TLorentzVector.h>

class fatjet : public TLorentzVector {
 public :
  std::vector<trackjet*> trackJetPointers;
  std::vector<photon*> photonPointers;
  std::vector<muon*> muonPointers;
  int bstatus ;
  int tjbstatus = -999;
  bool isTagged_50;
  bool isPassNtrk_50;
  bool isPassD2_50;
  bool isTagged_80;
  bool isPassNtrk_80;
  bool isPassD2_80;
  bool isMuonCorrection;
  float isXbbTagged;
  int isFatJetLabel;

  float PassMu12;
  float  PassD2;
  float PassTau21;
  float PassTmin;
  float isNtrk;
  //float PassPt;
  float PassPFlow;
  fatjet();
  ~fatjet();
  void AddTrackJetPointer(trackjet * next);
  void AddPhotonPointer(photon * next);
  void AddMuonPointer(muon * next);
  trackjet * GetTrackVector(uint i);
  int  GetNumTrackVectors();
  photon * GetPhotonVector(uint i);
  int GetNumPhotonVectors();
  muon * GetMuonVector(uint i);
  int GetNumMuonVectors();
  int  GetBStatus();
  int GettrkJetBStatus();
  //bool isSelected();
  bool isCand();
  ClassDef(fatjet,0);

};

#endif // #ifdef fatjet_h
