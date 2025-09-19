#define photon_cxx

#include "photon.h"
#include "fatjet.h"

photon::photon() : fatjetPointer(0) {
}

photon::~photon() {
}

void photon::AddFatJetPointer(fatjet * next) {
  fatjetPointer = next;
}
