all:
	echo ""; echo "Building sharedLib"; echo "";
	cd ./sharedLib; make deploy; cd ../;
	echo ""; echo "Building testApp with minus L"; echo "";
	cd ./testApp_withMinusL; make deploy; cd ../;
	echo ""; echo "Building testApp without minus L"; echo "";
	cd ./testApp_withoutMinusL; make deploy; cd ../;
	
clean:
	cd ./sharedLib; make clean; cd ../;
	cd ./testApp_withMinusL; make clean; cd ../;
	cd ./testApp_withoutMinusL; make clean; cd ../;
	rm -rf ./demoApp
