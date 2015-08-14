#!/bin/sh
#
# build syslog-win32 setup from scratch
#
# optional environment variables:
# DISTFILES should point to the directory with packages listed below
# HOST may contain target triplet for cross-compilation
# ISCC should point to the Inno Setup Compiler
#

default_distfiles_dir=distfiles        # must be relative path
unpacked_packages_dir=packages         # must be relative path

#
# packages
#
libiconv=libiconv-1.9.1.bin.woe32.zip  # http://www.gimp.org/~tml/gimp/win32
gettext=gettext-runtime-0.13.1.zip     # http://www.gimp.org/~tml/gimp/win32
pkgconfig=pkgconfig-0.15.zip           # http://www.gimp.org/~tml/gimp/win32
glib=glib-2.8.0.zip                    # ftp://ftp.gtk.org/pub/gtk/v2.8/win32
glib_dev=glib-dev-2.8.0.zip            # ftp://ftp.gtk.org/pub/gtk/v2.8/win32

function packages()
{
	echo $libiconv
	echo $gettext
	echo $pkgconfig
	echo $glib
	echo $glib_dev
}

workdir=`pwd`
prefix=$workdir/$unpacked_packages_dir
bindir=$prefix/bin
export PATH=$bindir:$PATH

#
# clean up and create destination directory
#
[ -d $unpacked_packages_dir ] && rm -rf $unpacked_packages_dir
mkdir $unpacked_packages_dir

#
# unpack packages
#
cd $unpacked_packages_dir
[ -z $DISTFILES ] && DISTFILES=$workdir/$default_distfiles_dir
for file in `packages` ; do
	unzip $DISTFILES/$file || exit 1
done
cd $workdir

#
# fix prefix in *.pc files
#
export PKG_CONFIG_PATH=$workdir/$unpacked_packages_dir/lib/pkgconfig
for file in $PKG_CONFIG_PATH/*.pc ; do
	module=`basename $file`
	module=${module%.pc}
	old_prefix=`pkg-config --variable=prefix $module`
	# old versions of sed haven't -i option
	sed -e s:$old_prefix:$prefix:g $file >$file.tmp || exit 1
	mv -f $file.tmp $file
done

# set OBJDUMP for cross-compilation
[ -z $HOST ] || export OBJDUMP=$HOST-objdump

#
# build
#
[ -z $HOST ] || export __HOST__=--host=$HOST
./configure --prefix=$prefix --sysconfdir=/etc --enable-relocatable --enable-debug ${__HOST__} || exit 1
make
make install-strip

#
# strip dll(s)
#
if [ -z $HOST ] ; then
	STRIP=strip
else
	STRIP=$HOST-strip
fi
$STRIP -s $bindir/libsyslog*.dll

#
# create setup
# FIXME: Msys has troubles running Inno Setup
#
[ -z "$ISCC" ] && ISCC=iscc.exe
[ -z $HOST ] || __WINE__=wine
cat <<EOF >tmp.m4
changequote([, ])dnl
define([m4_define], [\$2])dnl
EOF
version=`cat tmp.m4 version.m4 | m4`
echo $version
rm tmp.m4
$__WINE__ "$ISCC" setup.iss /dversion=$version /dbindir=$unpacked_packages_dir\\bin
