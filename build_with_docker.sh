alias dkrun="docker run -v `pwd`:/work/ -w /work/ -i cmptech/docker_tinycc_dev $*"
alias dkrunt="docker run -v `pwd`:/work/ -w /work/ -it cmptech/docker_tinycc_dev $*"

echo 'pwd
ls -al
rm -Rf build_docker
mkdir build_docker
cd build_docker
ls -al
export CC=tcc
cmake -D CROSS=lnx ..
make
upx dukluv
make install
' | dkrun

#dkrunt build_docker/dukluv unit-tests.js
dkrunt build_docker/dukluv unit-tests.js
