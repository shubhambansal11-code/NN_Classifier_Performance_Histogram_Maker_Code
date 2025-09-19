# -NN_Classifier_Performance_Histogram_Maker_Code-
**Introduction**

This repository contains the main analysis code to create histograms for the Xbb Calibration using Z->bb+Jet event topology. These histograms are then fed to the fit mechanism (Binned Template fit [zjet_dxbb_templatefit](https://gitlab.cern.ch/shbansal/zjet_dxbb_templatefit)) to extract the Z->bb signal strength.

**Set-up and run details**

After cloning the git repository, do :

```  
1. setupATLAS
2. lsetup "root 6.18.04-x86_64-centos7-gcc8-opt" 
3. cd run 
4. make 

```

One can run the ntuples locally via using this command line in the run-directory:
```
./{EXE from MakeProcess}.exe {opdir} {input file} {output file} {systematic name} {base directory}
```
**Additional Information for running jobs via Condor**

The ntuples can be also simply ran via the Condor, after running "make" in run directory one can simply do:
```
source submit_jobs.sh
```
_The word of caution_ here is that the set-up for submitting jobs via Condor is according to the Local Cluster I use(Uni-Bonn), but they can be adapted to one's own cluster requirement with changes in path/directory, as far as my understanding.

**For Plotting**: Data/MC Comparison plots can be plotted via a simple script in MyAnalysis folder, named as datavmc.C

