CC=g++ -g

#/home/teddybomber/.Polycode/Polycode-master/Release/Linux/Framework

CFLAGS=-I/home/teddybomber/.Polycode/Polycode-master/Release/Linux/Framework/Core/Dependencies/include -I/home/teddybomber/.Polycode/Polycode-master/Release/Linux/Framework/Core/Dependencies/include/AL -I/home/teddybomber/.Polycode/Polycode-master/Release/Linux/Framework/Core/include -I/home/teddybomber/.Polycode/Polycode-master/Release/Linux/Framework/Modules/include -I/home/teddybomber/.Polycode/Polycode-master/Release/Linux/Framework/Modules/Dependencies/include -I/home/teddybomber/.Polycode/Polycode-master/Release/Linux/Framework/Modules/Dependencies/include/bullet

LDFLAGS=-lrt -ldl -lpthread /home/teddybomber/.Polycode/Polycode-master/Release/Linux/Framework/Core/lib/libPolycore.a /home/teddybomber/.Polycode/Polycode-master/Release/Linux/Framework/Core/Dependencies/lib/libfreetype.a /home/teddybomber/.Polycode/Polycode-master/Release/Linux/Framework/Core/Dependencies/lib/liblibvorbisfile.a /home/teddybomber/.Polycode/Polycode-master/Release/Linux/Framework/Core/Dependencies/lib/liblibvorbis.a /home/teddybomber/.Polycode/Polycode-master/Release/Linux/Framework/Core/Dependencies/lib/liblibogg.a /home/teddybomber/.Polycode/Polycode-master/Release/Linux/Framework/Core/Dependencies/lib/libopenal.so /home/teddybomber/.Polycode/Polycode-master/Release/Linux/Framework/Core/Dependencies/lib/libphysfs.a /home/teddybomber/.Polycode/Polycode-master/Release/Linux/Framework/Core/Dependencies/lib/libpng15.a /home/teddybomber/.Polycode/Polycode-master/Release/Linux/Framework/Core/Dependencies/lib/libz.a -lGL -lGLU -lSDL /home/teddybomber/.Polycode/Polycode-master/Release/Linux/Framework/Modules/lib/libPolycode2DPhysics.a /home/teddybomber/.Polycode/Polycode-master/Release/Linux/Framework/Modules/Dependencies/lib/libBox2D.a /home/teddybomber/.Polycode/Polycode-master/Release/Linux/Framework/Modules/lib/libPolycode3DPhysics.a /home/teddybomber/.Polycode/Polycode-master/Release/Linux/Framework/Modules/Dependencies/lib/libBulletDynamics.a /home/teddybomber/.Polycode/Polycode-master/Release/Linux/Framework/Modules/Dependencies/lib/libBulletCollision.a /home/teddybomber/.Polycode/Polycode-master/Release/Linux/Framework/Modules/Dependencies/lib/libLinearMath.a


default:
	$(CC) $(CFLAGS) main.cpp HelloPolycodeApp.cpp -o PolycodeTemplate $(LDFLAGS)
	cp /home/teddybomber/.Polycode/Polycode-master/Release/Linux/Framework/Core/Assets/default.pak .
clean:
	rm PolycodeTemplate
	rm default.pak
	
