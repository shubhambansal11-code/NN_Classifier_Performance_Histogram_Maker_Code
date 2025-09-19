// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME Dictionary_mc
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// The generated code does not explicitly qualifies STL entities
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "../MyAnalysis/fatjet.h"
#include "../MyAnalysis/trackjet.h"
#include "../MyAnalysis/photon.h"
#include "../MyAnalysis/muon.h"
#include "../MyAnalysis/Nominal.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_trackjet(void *p = 0);
   static void *newArray_trackjet(Long_t size, void *p);
   static void delete_trackjet(void *p);
   static void deleteArray_trackjet(void *p);
   static void destruct_trackjet(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::trackjet*)
   {
      ::trackjet *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::trackjet >(0);
      static ::ROOT::TGenericClassInfo 
         instance("trackjet", ::trackjet::Class_Version(), "../MyAnalysis/trackjet.h", 12,
                  typeid(::trackjet), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::trackjet::Dictionary, isa_proxy, 4,
                  sizeof(::trackjet) );
      instance.SetNew(&new_trackjet);
      instance.SetNewArray(&newArray_trackjet);
      instance.SetDelete(&delete_trackjet);
      instance.SetDeleteArray(&deleteArray_trackjet);
      instance.SetDestructor(&destruct_trackjet);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::trackjet*)
   {
      return GenerateInitInstanceLocal((::trackjet*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::trackjet*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_muon(void *p = 0);
   static void *newArray_muon(Long_t size, void *p);
   static void delete_muon(void *p);
   static void deleteArray_muon(void *p);
   static void destruct_muon(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::muon*)
   {
      ::muon *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::muon >(0);
      static ::ROOT::TGenericClassInfo 
         instance("muon", ::muon::Class_Version(), "../MyAnalysis/muon.h", 8,
                  typeid(::muon), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::muon::Dictionary, isa_proxy, 4,
                  sizeof(::muon) );
      instance.SetNew(&new_muon);
      instance.SetNewArray(&newArray_muon);
      instance.SetDelete(&delete_muon);
      instance.SetDeleteArray(&deleteArray_muon);
      instance.SetDestructor(&destruct_muon);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::muon*)
   {
      return GenerateInitInstanceLocal((::muon*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::muon*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_photon(void *p = 0);
   static void *newArray_photon(Long_t size, void *p);
   static void delete_photon(void *p);
   static void deleteArray_photon(void *p);
   static void destruct_photon(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::photon*)
   {
      ::photon *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::photon >(0);
      static ::ROOT::TGenericClassInfo 
         instance("photon", ::photon::Class_Version(), "../MyAnalysis/photon.h", 8,
                  typeid(::photon), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::photon::Dictionary, isa_proxy, 4,
                  sizeof(::photon) );
      instance.SetNew(&new_photon);
      instance.SetNewArray(&newArray_photon);
      instance.SetDelete(&delete_photon);
      instance.SetDeleteArray(&deleteArray_photon);
      instance.SetDestructor(&destruct_photon);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::photon*)
   {
      return GenerateInitInstanceLocal((::photon*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::photon*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_fatjet(void *p = 0);
   static void *newArray_fatjet(Long_t size, void *p);
   static void delete_fatjet(void *p);
   static void deleteArray_fatjet(void *p);
   static void destruct_fatjet(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fatjet*)
   {
      ::fatjet *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::fatjet >(0);
      static ::ROOT::TGenericClassInfo 
         instance("fatjet", ::fatjet::Class_Version(), "../MyAnalysis/fatjet.h", 13,
                  typeid(::fatjet), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::fatjet::Dictionary, isa_proxy, 4,
                  sizeof(::fatjet) );
      instance.SetNew(&new_fatjet);
      instance.SetNewArray(&newArray_fatjet);
      instance.SetDelete(&delete_fatjet);
      instance.SetDeleteArray(&deleteArray_fatjet);
      instance.SetDestructor(&destruct_fatjet);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fatjet*)
   {
      return GenerateInitInstanceLocal((::fatjet*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::fatjet*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_Nominal(void *p = 0);
   static void *newArray_Nominal(Long_t size, void *p);
   static void delete_Nominal(void *p);
   static void deleteArray_Nominal(void *p);
   static void destruct_Nominal(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Nominal*)
   {
      ::Nominal *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Nominal >(0);
      static ::ROOT::TGenericClassInfo 
         instance("Nominal", ::Nominal::Class_Version(), "../MyAnalysis/Nominal.h", 28,
                  typeid(::Nominal), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Nominal::Dictionary, isa_proxy, 4,
                  sizeof(::Nominal) );
      instance.SetNew(&new_Nominal);
      instance.SetNewArray(&newArray_Nominal);
      instance.SetDelete(&delete_Nominal);
      instance.SetDeleteArray(&deleteArray_Nominal);
      instance.SetDestructor(&destruct_Nominal);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Nominal*)
   {
      return GenerateInitInstanceLocal((::Nominal*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Nominal*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr trackjet::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *trackjet::Class_Name()
{
   return "trackjet";
}

//______________________________________________________________________________
const char *trackjet::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::trackjet*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int trackjet::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::trackjet*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *trackjet::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::trackjet*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *trackjet::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::trackjet*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr muon::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *muon::Class_Name()
{
   return "muon";
}

//______________________________________________________________________________
const char *muon::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::muon*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int muon::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::muon*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *muon::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::muon*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *muon::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::muon*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr photon::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *photon::Class_Name()
{
   return "photon";
}

//______________________________________________________________________________
const char *photon::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::photon*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int photon::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::photon*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *photon::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::photon*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *photon::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::photon*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr fatjet::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *fatjet::Class_Name()
{
   return "fatjet";
}

//______________________________________________________________________________
const char *fatjet::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::fatjet*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int fatjet::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::fatjet*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *fatjet::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::fatjet*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *fatjet::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::fatjet*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr Nominal::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *Nominal::Class_Name()
{
   return "Nominal";
}

//______________________________________________________________________________
const char *Nominal::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Nominal*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int Nominal::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Nominal*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Nominal::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Nominal*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Nominal::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Nominal*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void trackjet::Streamer(TBuffer &R__b)
{
   // Stream an object of class trackjet.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(trackjet::Class(),this);
   } else {
      R__b.WriteClassBuffer(trackjet::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_trackjet(void *p) {
      return  p ? new(p) ::trackjet : new ::trackjet;
   }
   static void *newArray_trackjet(Long_t nElements, void *p) {
      return p ? new(p) ::trackjet[nElements] : new ::trackjet[nElements];
   }
   // Wrapper around operator delete
   static void delete_trackjet(void *p) {
      delete ((::trackjet*)p);
   }
   static void deleteArray_trackjet(void *p) {
      delete [] ((::trackjet*)p);
   }
   static void destruct_trackjet(void *p) {
      typedef ::trackjet current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::trackjet

//______________________________________________________________________________
void muon::Streamer(TBuffer &R__b)
{
   // Stream an object of class muon.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(muon::Class(),this);
   } else {
      R__b.WriteClassBuffer(muon::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_muon(void *p) {
      return  p ? new(p) ::muon : new ::muon;
   }
   static void *newArray_muon(Long_t nElements, void *p) {
      return p ? new(p) ::muon[nElements] : new ::muon[nElements];
   }
   // Wrapper around operator delete
   static void delete_muon(void *p) {
      delete ((::muon*)p);
   }
   static void deleteArray_muon(void *p) {
      delete [] ((::muon*)p);
   }
   static void destruct_muon(void *p) {
      typedef ::muon current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::muon

//______________________________________________________________________________
void photon::Streamer(TBuffer &R__b)
{
   // Stream an object of class photon.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(photon::Class(),this);
   } else {
      R__b.WriteClassBuffer(photon::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_photon(void *p) {
      return  p ? new(p) ::photon : new ::photon;
   }
   static void *newArray_photon(Long_t nElements, void *p) {
      return p ? new(p) ::photon[nElements] : new ::photon[nElements];
   }
   // Wrapper around operator delete
   static void delete_photon(void *p) {
      delete ((::photon*)p);
   }
   static void deleteArray_photon(void *p) {
      delete [] ((::photon*)p);
   }
   static void destruct_photon(void *p) {
      typedef ::photon current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::photon

//______________________________________________________________________________
void fatjet::Streamer(TBuffer &R__b)
{
   // Stream an object of class fatjet.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(fatjet::Class(),this);
   } else {
      R__b.WriteClassBuffer(fatjet::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_fatjet(void *p) {
      return  p ? new(p) ::fatjet : new ::fatjet;
   }
   static void *newArray_fatjet(Long_t nElements, void *p) {
      return p ? new(p) ::fatjet[nElements] : new ::fatjet[nElements];
   }
   // Wrapper around operator delete
   static void delete_fatjet(void *p) {
      delete ((::fatjet*)p);
   }
   static void deleteArray_fatjet(void *p) {
      delete [] ((::fatjet*)p);
   }
   static void destruct_fatjet(void *p) {
      typedef ::fatjet current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fatjet

//______________________________________________________________________________
void Nominal::Streamer(TBuffer &R__b)
{
   // Stream an object of class Nominal.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Nominal::Class(),this);
   } else {
      R__b.WriteClassBuffer(Nominal::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Nominal(void *p) {
      return  p ? new(p) ::Nominal : new ::Nominal;
   }
   static void *newArray_Nominal(Long_t nElements, void *p) {
      return p ? new(p) ::Nominal[nElements] : new ::Nominal[nElements];
   }
   // Wrapper around operator delete
   static void delete_Nominal(void *p) {
      delete ((::Nominal*)p);
   }
   static void deleteArray_Nominal(void *p) {
      delete [] ((::Nominal*)p);
   }
   static void destruct_Nominal(void *p) {
      typedef ::Nominal current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Nominal

namespace {
  void TriggerDictionaryInitialization_libMyAnalysis_Impl() {
    static const char* headers[] = {
"../MyAnalysis/fatjet.h",
"../MyAnalysis/trackjet.h",
"../MyAnalysis/photon.h",
"../MyAnalysis/muon.h",
"../MyAnalysis/Nominal.h",
0
    };
    static const char* includePaths[] = {
"/cvmfs/sft.cern.ch/lcg/releases/ROOT/6.18.04-c767d/x86_64-centos7-gcc8-opt/include",
"/cephfs/user/s6subans/QT_2020/qt-2019-2020/qt-2019-2020/run/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libMyAnalysis dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$../MyAnalysis/fatjet.h")))  trackjet;
class __attribute__((annotate("$clingAutoload$../MyAnalysis/fatjet.h")))  muon;
class __attribute__((annotate("$clingAutoload$../MyAnalysis/fatjet.h")))  photon;
class __attribute__((annotate("$clingAutoload$../MyAnalysis/fatjet.h")))  fatjet;
class __attribute__((annotate("$clingAutoload$../MyAnalysis/Nominal.h")))  Nominal;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libMyAnalysis dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "../MyAnalysis/fatjet.h"
#include "../MyAnalysis/trackjet.h"
#include "../MyAnalysis/photon.h"
#include "../MyAnalysis/muon.h"
#include "../MyAnalysis/Nominal.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"Nominal", payloadCode, "@",
"fatjet", payloadCode, "@",
"muon", payloadCode, "@",
"photon", payloadCode, "@",
"trackjet", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libMyAnalysis",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libMyAnalysis_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libMyAnalysis_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libMyAnalysis() {
  TriggerDictionaryInitialization_libMyAnalysis_Impl();
}
