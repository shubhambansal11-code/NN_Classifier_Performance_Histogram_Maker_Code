#define muon_cxx

#include "muon.h"
#include "fatjet.h"

muon::muon() : fatjetPointer(0) {
}

muon::~muon() {
}

void muon::AddFatJetPointer(fatjet * next) {
  fatjetPointer = next;
}
