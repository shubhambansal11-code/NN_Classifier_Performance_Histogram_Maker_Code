#define trackjet_cxx
// The trackjet handler wrtten Bill Murray 5th April 2018

#include "trackjet.h"
#include "fatjet.h"

trackjet::trackjet() : fatjetPointer(0) {
}

 trackjet::~trackjet() {
}

void trackjet::AddFatJetPointer(fatjet * next) {
  fatjetPointer = next;
}
