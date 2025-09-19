source /etc/profile

HOMEDIR="/cephfs/user/s6subans/QT_2020/qt-2019-2020/qt-2019-2020/run/"

cd ${HOMEDIR}
#export ATLAS_LOCAL_ROOT_BASE=/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase
#. ${ATLAS_LOCAL_ROOT_BASE}/user/atlasLocalSetup.sh
setupATLAS

lsetup  "root 6.18.04-x86_64-centos7-gcc8-opt"


OPDIR=${1}
INFILE=${2}
OPFILE=${3}
SYST=${4}
BASE=${5}
Cluster=${6}
Process=${7}


echo "${OPDIR}"
echo "${INFILE}"
echo "${OPFILE}"
echo "${BASE}"
echo "${SYST}"
#echo $5

./Nominal.exe ${OPDIR} ${INFILE} ${OPFILE} ${SYST} ${BASE}

echo "Write Output File to: ${OUTDIR} ....."
