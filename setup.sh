setupATLAS
lsetup "root 6.18.04-x86_64-centos7-gcc8-opt"
export RUCIO_ACCOUNT=shbansal
lsetup rucio
voms-proxy-init -voms atlas
