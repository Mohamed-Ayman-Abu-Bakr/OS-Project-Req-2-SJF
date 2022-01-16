# OS-Project-Req-2-SJF

You can use this link to setup MINIX 3.2.1 and 3.3: http://homepages.cs.ncl.ac.uk/nick.cook/csc2025/minix/createvm.html 

To run the source code while running the MINIX 3.3.0 virtual machine, type the following:
1. cd /usr/src/releasetools
2. make clean
3. make hdboot
4. shutdown

To Test the algorithm type this is the MINIX 3.3.0 virtual machine:
1. cd /usr/src/test
2. cc test.c -o test
3. cc longrun.c -o long
4. ./test
You will then be able to find the test results in test.txt in the same directory
