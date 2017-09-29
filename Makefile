carrier.so: carrier.c
	gcc -shared -fPIC carrier.c -o carrier.so -ldl
