cp -f build/GuitarFineTune deb/GuitarFineTune/usr/local/bin/
cd deb
rm -f ./GuitarFineTune.deb
dpkg-deb --build GuitarFineTune
dpkg -i ./GuitarFineTune.deb
