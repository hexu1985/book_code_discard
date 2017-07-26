all:
	echo ""; echo "Building sharedLib"; echo "";
	cd ./sharedLib; make deploy; cd ../;
	echo ""; echo "Building testApp"; echo "";
	cd ./testApp; make deploy; cd ../;
	
clean:
	cd ./sharedLib; make clean; cd ../;
	cd ./testApp; make clean; cd ../;
