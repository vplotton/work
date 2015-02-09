curl http://www.libsdl.org/release/SDL-1.2.15.tar.gz > SDL-1.2.15.tar.gz

mkdir SDL-1.2.15
tar xzf SDL-1.2.15.tar.gz
curl ftp://ftp.mirrorservice.org/sites/rsync.macports.org/release/ports/devel/libsdl/files/no-CGDirectPaletteRef.patch > no-CGDirectPaletteRef.patch 
mv no-CGDirectPaletteRef.patch SDL-1.2.15/src/video/quartz/
cd SDL-1.2.15/src/video/quartz/
patch -p1 < no-CGDirectPaletteRef.patch
patch -p1 < sdl--patch-3137feb503a89a8d606405373905b92dcf7e293b.cgi
cd ../../../
./configure OBJC=clang CC=clang CLFAGS=-w --prefix=`pwd` --without-x ; make ; make install
-sdltest ; make ; make install
cd ..
gcc -Werror -Wall -Wextra main.c cmd.c ft_display_ground.c ft_init.c init.c interface.c map.c ressource.c $(SDL-1.2.15/bin/sdl-config --cflags --libs) SDL-1.2.15/lib/*.dylib libft/libft.a
