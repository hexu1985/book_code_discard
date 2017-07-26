all:
	echo ""; echo "Building staticLib"; echo "";
	cd ./staticLib; make deploy; cd ../;
	echo ""; echo "Building sharedLib"; echo "";
	cd ./sharedLib; make deploy; cd ../;
	echo ""; echo "Building testApp"; echo "";
	cd ./testApp; make deploy; cd ../;
	
clean:
	cd ./staticLib; make clean; cd ../;
	cd ./sharedLib; make clean; cd ../;
	cd ./testApp; make clean; cd ../;
	rm -rf ./demoApp
