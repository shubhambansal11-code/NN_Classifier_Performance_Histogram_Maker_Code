# The name of the produced library
EXE = Nominal.exe
#EXE = Nominal_data.exe
# The name of the produced library
SHAREDLIB = libMyAnalysis.so
# The name of the produced rootmap file
ROOTMAP = libMyAnalysis.rootmap
# The name of the root flags
ROOT_CFLAGS := $(shell root-config --cflags)
ROOT_GLIBS := $(shell root-config --glibs)
# The name of the python flags
PY_CFLAGS := $(shell python2.7-config --cflags)
PY_LDFLAGS := $(shell python2.7-config --ldflags)
LIBS    = $(shell root-config --libs) -lGui -lCore -lImt -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lROOTVecOps -lTree -lTreePlayer -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -lMultiProc -pthread -lm -ldl -rdynamic

all: ${EXE}

# Rule for buildin the exe:
#Below for MC:
${EXE}: ../MyAnalysis/fatjet.cxx ../MyAnalysis/trackjet.cxx ../MyAnalysis/photon.cxx ../MyAnalysis/muon.cxx ../MyAnalysis/Nominal.cxx Dictionary_mc.cxx
#Below for data:
#${EXE}: ../MyAnalysis/fatjet.cxx ../MyAnalysis/trackjet.cxx ../MyAnalysis/photon.cxx ../MyAnalysis/muon.cxx ../MyAnalysis/Nominal_data.cxx Dictionary_data.cxx
	`root-config --cxx` -o $@ $^ ${ROOT_CFLAGS} ${LIBS} ${PY_CFLAGS} -L/afs/cern.ch/work/s/shbansal/python2.7/lib ${PY_LDFLAGS}

#-L/home/yhe/python2.7/lib

# Rule for making a single dictionary for the sources:
#Below for mc:
Dictionary_mc.cxx: ../MyAnalysis/fatjet.h ../MyAnalysis/trackjet.h ../MyAnalysis/photon.h ../MyAnalysis/muon.h ../MyAnalysis/Nominal.h ../MyAnalysis/LinkDef.h
#Below for data:
#Dictionary_data.cxx: ../MyAnalysis/fatjet.h ../MyAnalysis/trackjet.h ../MyAnalysis/photon.h ../MyAnalysis/muon.h ../MyAnalysis/Nominal_data.h ../MyAnalysis/LinkDef.h
	rootcint -f $@ -s ${SHAREDLIB} -rml ${SHAREDLIB} -rmf ${ROOTMAP} $^

# Cleaning rule(s):
clean:
	rm -f *.o	
	rm -f Dictionary*
	rm -f libMyAnalysis*
	rm -f Nominal #for mc only Nominal

distclean: clean
	rm -f *~

#General build rules:
.SUFFIXES: .cxx .o

# Rule for making an object file out of a source file:
.cxx.o:
	`root-config --cxx` -c -g -02 -fPIC -o $@ `root-config --cflags`$<


#-L/home/yhe/python2.7/lib ${PY_LDFLAGS}
