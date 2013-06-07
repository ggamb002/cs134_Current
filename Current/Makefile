CC=g++

#/home/isaac/.polycode/Release/Linux/Framework

CFLAGS=-I/home/isaac/.polycode/Release/Linux/Framework/Core/Dependencies/include -I/home/isaac/.polycode/Release/Linux/Framework/Core/Dependencies/include/AL -I/home/isaac/.polycode/Release/Linux/Framework/Core/include -I/home/isaac/.polycode/Release/Linux/Framework/Modules/include -I/home/isaac/.polycode/Release/Linux/Framework/Modules/Dependencies/include -I/home/isaac/.polycode/Release/Linux/Framework/Modules/Dependencies/include/bullet

LDFLAGS=-lrt -ldl -lpthread /home/isaac/.polycode/Release/Linux/Framework/Core/lib/libPolycore.a /home/isaac/.polycode/Release/Linux/Framework/Core/Dependencies/lib/libfreetype.a /home/isaac/.polycode/Release/Linux/Framework/Core/Dependencies/lib/liblibvorbisfile.a /home/isaac/.polycode/Release/Linux/Framework/Core/Dependencies/lib/liblibvorbis.a /home/isaac/.polycode/Release/Linux/Framework/Core/Dependencies/lib/liblibogg.a /home/isaac/.polycode/Release/Linux/Framework/Core/Dependencies/lib/libopenal.so /home/isaac/.polycode/Release/Linux/Framework/Core/Dependencies/lib/libphysfs.a /home/isaac/.polycode/Release/Linux/Framework/Core/Dependencies/lib/libpng15.a /home/isaac/.polycode/Release/Linux/Framework/Core/Dependencies/lib/libz.a -lGL -lGLU -lSDL /home/isaac/.polycode/Release/Linux/Framework/Modules/lib/libPolycode2DPhysics.a /home/isaac/.polycode/Release/Linux/Framework/Modules/Dependencies/lib/libBox2D.a /home/isaac/.polycode/Release/Linux/Framework/Modules/lib/libPolycode3DPhysics.a /home/isaac/.polycode/Release/Linux/Framework/Modules/Dependencies/lib/libBulletDynamics.a /home/isaac/.polycode/Release/Linux/Framework/Modules/Dependencies/lib/libBulletCollision.a /home/isaac/.polycode/Release/Linux/Framework/Modules/Dependencies/lib/libLinearMath.a


default:
	$(CC) $(CFLAGS) main.cpp HelloPolycodeApp.cpp -o PolycodeTemplate $(LDFLAGS)
	cp /home/isaac/.polycode/Release/Linux/Framework/Core/Assets/default.pak .
clean:
	rm PolycodeTemplate
	rm default.pak

