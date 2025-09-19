#!/bin/bash

#Submit script for gbb Tuple Ana
echo "Submit jobs for Zbb Calibration Analysis......"

#OUTPATH="/afs/cern.ch/work/s/shbansal/chargedHiggs_Ana/MockOutput"
LOG_FOLDER="/cephfs/user/s6subans/QT_2020/qt-2019-2020/qt-2019-2020/"

echo "Logs in: ${LOG_FOLDER}"
echo "Output in: ${OUTPATH}"

OPDIR="/cephfs/user/s6subans/QT_2020/qt-2019-2020/qt-2019-2020/run/output_t7XbbDL1r_2010/"
#OPDIR="/cephfs/user/s6subans/QT_2020/qt-2019-2020/qt-2019-2020/run/output_t7Xbb_0408/"
#USE_BATCH_MODE=1

#INFILE="410471_MC16a"
echo "reading files !!! "
INFILE=(
    #"410466_MC16a"
   # "364375_MC16e"
   # "364376_MC16e"
   # "364377_MC16e"
   #  "364378_MC16e"
   #  "364379_MC16e"
    # "364380_MC16e"
    "700040_MC16a_DL1r"
    "700041_MC16a"
    "700042_MC16a_DL1r"                 
    "700043_MC16a"      
    "700044_MC16a"   
    "700045_MC16a"
    #"410471_MC16a"
    "364703_MC16a" 
    "364704_MC16a"   
    "364705_MC16a" 
    "364706_MC16a" 
    "364707_MC16a" 
    "364708_MC16a"     
    "364709_MC16a" 
    "364710_MC16a"
    "364711_MC16a" 
    "364712_MC16a"
    "410471_MC16a")
         #"data15"
         #"data16"
         #"data17")
         #"data18" )
   # "700043_MC16a"            
   # "700044_MC16a")
#export EOS_MGM_URL=root://eosuser.cern.ch
SYST=( 
     "nominal")

BASE="/cephfs/user/s6subans/QT_2020/qt-2019-2020/qt-2019-2020/samples_t7Vq/"
#SYST="nominal"

#echo "sucessfuly opened tar files"
for infile in "${INFILE[@]}"
do	    
 for syst in "${SYST[@]}"
 do
 echo "${OPDIR}, ${INFILE}, ${BASE}, ${syst}"	  
      #./execute.exe $path $file $wp $OUTDIR       
 condor_submit OPDIR="${OPDIR}" INFILE="${infile}" OPFILE="${infile}"_"${syst}" SYST="${syst}" BASE="${BASE}" /cephfs/user/s6subans/QT_2020/qt-2019-2020/qt-2019-2020/run/run_Nominal.sub  
      #condor_submit $path $file $wp $OUTDIR /cephfs/user/s6subans/ChargedHiggsAna/Code/run_Hplus.sub	
      #sbatch  /cephfs/user/s6subans/ChargedHiggsAna/Code/RunJob.sh  
 done
done

echo "all done !!! "
