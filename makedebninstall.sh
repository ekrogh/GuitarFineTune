cp -f build/GuitarFineTune deb/GuitarFineTune/usr/local/bin/
cd deb
pwd
rm -f ./GuitarFineTune.deb
dpkg-deb --build GuitarFineTune
dpkg -i ./GuitarFineTune.deb
cd
pwd
mkdir -p local/bin
cp /usr/local/bin/GuitarFineTune local/bin/
