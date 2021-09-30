cp -f build/GuitarFineTune deb/GuitarFineTune/usr/local/bin/
cd deb
dpkg-buildpackage
dpkg -i GuitarFineTune.deb
