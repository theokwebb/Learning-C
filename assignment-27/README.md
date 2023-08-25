Solution to h0mbre's [assignment 27](https://github.com/h0mbre/Learning-C/tree/master/Assignment-27).

Compile with:

`gcc helloworld.c -o helloworld`

`gcc hook.c -o libhook.so -fPIC -shared -ldl`

Set the `LD_PRELOAD` environment variable to point to the location of the newly created shared library:

`export LD_PRELOAD="/home/...../libhook.so"`
