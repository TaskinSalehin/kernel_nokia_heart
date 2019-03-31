git clone https://github.com/ChalapathiRevanth/Toolchain ~/Toolchain
export ARCH=arm64
export CROSS_COMPILE=~/Toolchain/bin/aarch64-linux-android-
export KBUILD_BUILD_USER=RevanthTolety
export KBUILD_BUILD_HOST=thunderstorm-buildserver
mkdir output
make -C $(pwd) O=output k37mv1_64_defconfig
make -j32 -C $(pwd) O=output
