configure_for_platform() {
	export PLATFORM=$1
	echo "Platform is ${PLATFORM}"

	if [ "$PLATFORM" == "iPhoneSimulator" ]; then
		export ARCHITECTURE=i386
		export ARCH=i686-apple-darwin
	fi

	if [ "$PLATFORM" == "iPhoneOS" ]; then
		export ARCHITECTURE=$2
		export ARCH=arm-apple-darwin 
	fi

	export ARCH_PREFIX=$ARCH- 
	export SDKVER="6.1" 
	export DEVROOT=/Applications/Xcode.app/Contents/Developer/Platforms/${PLATFORM}.platform/Developer 
	export SDKROOT="$DEVROOT/SDKs/${PLATFORM}$SDKVER.sdk" 
	export PKG_CONFIG_PATH="$SDKROOT/usr/lib/pkgconfig:$DEVROOT/usr/lib/pkgconfig" 
	export AS="$DEVROOT/usr/bin/as" 
	export ASCPP="$DEVROOT/usr/bin/as" 
	export AR="$DEVROOT/usr/bin/ar" 
	export RANLIB="$DEVROOT/usr/bin/ranlib" 
	export CC="$DEVROOT/usr/bin/gcc" 
	export CXX="$DEVROOT/usr/bin/g++" 
	export LD="$DEVROOT/usr/bin/ld" 
	export STRIP="$DEVROOT/usr/bin/strip" 
	export LIBRARY_PATH="$SDKROOT/usr/lib"

	export CPPFLAGS="" 
	export CFLAGS="-arch ${ARCHITECTURE} -O2 -fmessage-length=0 -pipe -fpascal-strings -miphoneos-version-min=4.0 -isysroot $SDKROOT -I$SDKROOT/usr/include -I$SDKROOT/usr/include/c++/4.2.1/" 
	export CXXFLAGS="$CFLAGS" 
	export LDFLAGS="-arch ${ARCHITECTURE} -isysroot $SDKROOT -L$SDKROOT/usr/lib/system -L$SDKROOT/usr/lib/"

	./configure --host=${ARCH} --enable-static --disable-shared 
}


mkdir ios-build

#build for iPhoneSimulator
configure_for_platform iPhoneSimulator
make clean
make
cp src/.libs/libprotobuf.a ios-build/libprotobuf-i386.a

#build for iPhoneOS armv7
configure_for_platform iPhoneOS armv7
make clean
make
cp src/.libs/libprotobuf.a ios-build/libprotobuf-armv7.a

#build for iPhoneOS armv7s
configure_for_platform iPhoneOS armv7s
make clean
make
cp src/.libs/libprotobuf.a ios-build/libprotobuf-armv7s.a

make clean

#cerate a fat library containing all achitectures in libprotobuf.a
xcrun -sdk iphoneos lipo -arch armv7 ios-build/libprotobuf-armv7.a -arch armv7s ios-build/libprotobuf-armv7s.a -arch i386 ios-build/libprotobuf-i386.a -create -output ios-build/libprotobuf.a
