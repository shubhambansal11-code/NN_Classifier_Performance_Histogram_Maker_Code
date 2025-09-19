#define fatjet_cxx

#include "fatjet.h"
#include <iostream>

fatjet::fatjet() : bstatus(-1) {
}

fatjet::~fatjet() {
}

void fatjet::AddTrackJetPointer(trackjet * next) {
  trackJetPointers.push_back(next);  
}

void fatjet::AddPhotonPointer(photon * next) {
  photonPointers.push_back(next);  
}

void fatjet::AddMuonPointer(muon * next) {
  muonPointers.push_back(next);
}

trackjet * fatjet::GetTrackVector(uint i) {
  if (  i >= trackJetPointers.size()) {
    std::cout<<"fatjet::GetTrackVector asked for pointer "<<i<<"; size is "<<trackJetPointers.size()<<std::endl;
    return 0;
  }
  return trackJetPointers[i];
}

int  fatjet::GetNumTrackVectors() {
  return trackJetPointers.size();
}

photon * fatjet::GetPhotonVector(uint i) {
  if (i >= photonPointers.size()) {
    return 0;
  }
  return photonPointers[i];
}

int fatjet::GetNumPhotonVectors() {
  return photonPointers.size();
}

muon * fatjet::GetMuonVector(uint i) {
  if (i >= muonPointers.size()) {
    return 0;
  }
  return muonPointers[i];
}

int fatjet::GetNumMuonVectors() {
  return muonPointers.size();
}

int  fatjet::GetBStatus() {
  // 1: 0 b-tags; 2: 1 85% b-tag; 3: 1 77% b-tag; 4: 1 70% b-tag; 5: 1 60% b-tag; 6: 2 85% b-tags; 7: 2 77% b-tags; 8: 2 70% b-tags; 9: 2 60% b-tags
 
  if (bstatus < 0 && trackJetPointers.size() > 1) {
    trackjet * leadingtj = 0;
    trackjet * secondtj = 0;
    double highestPt = 0;
    double secondPt = 0;

    for (auto itj = trackJetPointers.begin();itj != trackJetPointers.end();++itj) {
      trackjet * tj = (*itj);
      if (tj->Pt() > highestPt) {
	secondPt = highestPt;
	secondtj = leadingtj;
	leadingtj = tj;
	highestPt = tj->Pt();
      } else if (tj->Pt() > secondPt) {
	secondtj = tj;
	secondPt = tj->Pt();
      } else continue;
    }

    /*if (leadingtj->TrackJetIsBTagged_MV2c10_FixedCutBEff_60 && secondtj->TrackJetIsBTagged_MV2c10_FixedCutBEff_60) bstatus = 9;

    else if (leadingtj->TrackJetIsBTagged_MV2c10_FixedCutBEff_70 && secondtj->TrackJetIsBTagged_MV2c10_FixedCutBEff_70) bstatus = 8;

    else if (leadingtj->TrackJetIsBTagged_MV2c10_FixedCutBEff_77 && secondtj->TrackJetIsBTagged_MV2c10_FixedCutBEff_77) bstatus = 7;

    else if (leadingtj->TrackJetIsBTagged_MV2c10_FixedCutBEff_85 && secondtj->TrackJetIsBTagged_MV2c10_FixedCutBEff_85) bstatus = 6;

    else if ((leadingtj->TrackJetIsBTagged_MV2c10_FixedCutBEff_60 && ! secondtj->TrackJetIsBTagged_MV2c10_FixedCutBEff_85) || (! leadingtj->TrackJetIsBTagged_MV2c10_FixedCutBEff_85 && secondtj->TrackJetIsBTagged_MV2c10_FixedCutBEff_60)) bstatus = 5;

    else if ((leadingtj->TrackJetIsBTagged_MV2c10_FixedCutBEff_70 && ! secondtj->TrackJetIsBTagged_MV2c10_FixedCutBEff_85) || (!leadingtj->TrackJetIsBTagged_MV2c10_FixedCutBEff_85 && secondtj->TrackJetIsBTagged_MV2c10_FixedCutBEff_70)) bstatus = 4;

    else if ((leadingtj->TrackJetIsBTagged_MV2c10_FixedCutBEff_77 && ! secondtj->TrackJetIsBTagged_MV2c10_FixedCutBEff_85) || (! leadingtj->TrackJetIsBTagged_MV2c10_FixedCutBEff_85 && secondtj->TrackJetIsBTagged_MV2c10_FixedCutBEff_77)) bstatus = 3;

    else if ((leadingtj->TrackJetIsBTagged_MV2c10_FixedCutBEff_85 && ! secondtj->TrackJetIsBTagged_MV2c10_FixedCutBEff_85) || (! leadingtj->TrackJetIsBTagged_MV2c10_FixedCutBEff_85 && secondtj->TrackJetIsBTagged_MV2c10_FixedCutBEff_85)) bstatus = 2;

    else if (! leadingtj->TrackJetIsBTagged_MV2c10_FixedCutBEff_85 && ! secondtj->TrackJetIsBTagged_MV2c10_FixedCutBEff_85) bstatus = 1;*/

     if (leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_60 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_60) bstatus = 9;

    else if (leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_70 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_70) bstatus = 8;

    else if (leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_77 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_77) bstatus = 7;

    else if (leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85) bstatus = 6;

    else if ((leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_60 && ! secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85) || (! leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_60)) bstatus = 5;

    else if ((leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_70 && ! secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85) || (!leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_70)) bstatus = 4;

    else if ((leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_77 && ! secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85) || (! leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_77)) bstatus = 3;

    else if ((leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && ! secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85) || (! leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85)) bstatus = 2;

    else if (! leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && ! secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85) bstatus = 1;
   
  }
    return bstatus;
}


int  fatjet::GettrkJetBStatus() {
  // 1: 0 b-tags; 2: 1 85% b-tag; 3: 1 77% b-tag; 4: 1 70% b-tag; 5: 1 60% b-tag; 6: 2 85% b-tags; 7: 2 77% b-tags; 8: 2 70% b-tags; 9: 2 60% b-tags
  //tjbstatus = -999;
  if (tjbstatus < 0 && trackJetPointers.size() > 1) {
    trackjet * leadingtj = 0;
    trackjet * secondtj = 0;
    double highestPt = 0;
    double secondPt = 0;

    for (auto itj = trackJetPointers.begin();itj != trackJetPointers.end();++itj) {
      trackjet * tj = (*itj);
      if (tj->Pt() > highestPt) {
	secondPt = highestPt;
	secondtj = leadingtj;
	leadingtj = tj;
	highestPt = tj->Pt();
      } else if (tj->Pt() > secondPt) {
	secondtj = tj;
	secondPt = tj->Pt();
      } else continue;
    }
    if ( leadingtj->TrackJetHadronConeExclTruthLabelID == 0 &&  secondtj->TrackJetHadronConeExclTruthLabelID ==0){ //LL
       tjbstatus = 1; 
     }
    else if ( leadingtj->TrackJetHadronConeExclTruthLabelID == 0 &&  secondtj->TrackJetHadronConeExclTruthLabelID ==4){ //LC
         tjbstatus = 2;
     }
    else if ( leadingtj->TrackJetHadronConeExclTruthLabelID == 0 &&  secondtj->TrackJetHadronConeExclTruthLabelID ==5){ //LB
         tjbstatus = 3;
     }
     
    else if ( leadingtj->TrackJetHadronConeExclTruthLabelID == 4 &&  secondtj->TrackJetHadronConeExclTruthLabelID ==4){ //CC
         tjbstatus = 4;
     }
     
    else if ( leadingtj->TrackJetHadronConeExclTruthLabelID == 4 && secondtj->TrackJetHadronConeExclTruthLabelID ==0){ //CL
         tjbstatus = 5;
     }
    
    else if ( leadingtj->TrackJetHadronConeExclTruthLabelID == 5 && secondtj->TrackJetHadronConeExclTruthLabelID ==0){ //BL
         tjbstatus = 6;
     }

    else if ( leadingtj->TrackJetHadronConeExclTruthLabelID == 5 && secondtj->TrackJetHadronConeExclTruthLabelID ==5){ //BB
         tjbstatus = 7;
     }
    
    
    //LL
    /*
    if ( leadingtj->TrackJetTruthLabelId == 0 &&  secondtj->TrackJetTruthLabelId ==0){
   if (leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_60 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_60) tjbstatus = 19;

    else if (leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_70 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_70) tjbstatus = 18;

    else if (leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_77 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_77) tjbstatus = 17;

    else if (leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85) tjbstatus = 16;

    else if ((leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_60 && ! secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85) || (! leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_60)) tjbstatus = 15;

    else if ((leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_70 && ! secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85) || (!leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_70)) tjbstatus = 14;

    else if ((leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_77 && ! secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85) || (! leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_77)) tjbstatus = 13;

    else if ((leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && ! secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85) || (! leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85)) tjbstatus = 12;

    else if (! leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && ! secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85) tjbstatus = 11;

    }//Close LL
*/
    /*
    //CC
    if ( leadingtj->TrackJetTruthLabelId == 4 &&  secondtj->TrackJetTruthLabelId ==4){
   if (leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_60 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_60) tjbstatus = 29;

    else if (leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_70 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_70) tjbstatus = 28;

    else if (leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_77 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_77) tjbstatus = 27;

    else if (leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85) tjbstatus = 26;

    else if ((leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_60 && ! secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85) || (! leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_60)) tjbstatus = 25;

    else if ((leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_70 && ! secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85) || (!leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_70)) tjbstatus = 24;

    else if ((leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_77 && ! secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85) || (! leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_77)) tjbstatus = 23;

    else if ((leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && ! secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85) || (! leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85)) tjbstatus = 22;

    else if (! leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && ! secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85) tjbstatus = 21;
   }// close CC


//CL
    else if ( leadingtj->TrackJetTruthLabelId == 4 && secondtj->TrackJetTruthLabelId ==0){
   if (leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_60 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_60) tjbstatus = 39;

    else if (leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_70 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_70) tjbstatus = 38;

    else if (leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_77 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_77) tjbstatus = 37;

    else if (leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85) tjbstatus = 36;

    else if ((leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_60 && ! secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85) || (! leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_60)) tjbstatus = 35;

    else if ((leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_70 && ! secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85) || (!leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_70)) tjbstatus = 34;

    else if ((leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_77 && ! secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85) || (! leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_77)) tjbstatus = 33;

    else if ((leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && ! secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85) || (! leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85)) tjbstatus = 32;

    else if (! leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && ! secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85) tjbstatus = 31;
   }// close CL


//BC
    else if ( leadingtj->TrackJetTruthLabelId == 5 &&  secondtj->TrackJetTruthLabelId ==4){
   if (leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_60 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_60) tjbstatus = 49;

    else if (leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_70 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_70) tjbstatus = 48;

    else if (leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_77 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_77) tjbstatus = 47;

    else if (leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85) tjbstatus = 46;

    else if ((leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_60 && ! secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85) || (! leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_60)) tjbstatus = 45;

    else if ((leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_70 && ! secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85) || (!leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_70)) tjbstatus = 44;

    else if ((leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_77 && ! secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85) || (! leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_77)) tjbstatus = 43;

    else if ((leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && ! secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85) || (! leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85)) tjbstatus = 42;

    else if (! leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && ! secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85) tjbstatus = 41;
   }// close BC

*/
//BB
/*
     if ( leadingtj->TrackJetTruthLabelId == 5 && secondtj->TrackJetTruthLabelId ==5){
   if (leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_60 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_60) tjbstatus = 59;

    else if (leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_70 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_70) tjbstatus = 58;

    else if (leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_77 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_77) tjbstatus = 57;

    else if (leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85) tjbstatus = 56;

    else if ((leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_60 && ! secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85) || (! leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_60)) tjbstatus = 55;

    else if ((leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_70 && ! secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85) || (!leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_70)) tjbstatus = 54;

    else if ((leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_77 && ! secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85) || (! leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_77)) tjbstatus = 53;

    else if ((leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && ! secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85) || (! leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85)) tjbstatus = 52;

    else if (! leadingtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85 && ! secondtj->TrackJetIsBTagged_DL1r_FixedCutBEff_85) tjbstatus = 51;
   }// close BB
   */
  }
    return tjbstatus;
}


bool fatjet::isCand() {
  if(Pt() < 200.) return false;
  if (Eta() > 2. || Eta() < -2.) return false;
  if (M() < 30.) return false;
  //if (GetNumTrackVectors() < 2) return false;
 
  return true;
  }

/*bool fatjet::isTagged(){
  return false;
}

bool fatjet::isPassNtrk(){
  return false;
}

bool fatjet::isPassD2(){
  return false;
  }*/
