# [LBYARCH] MC02

This repository contains requirements for our LBYARCH MC02

## Requirements
Write the kernel in (1) C program and (2) an x86-64 assembly language.  The kernel is to perform a dot product between vector *A* and vector *B* and place the result in *sdot*.

## Analysis
Found below are the average corresponding times the C and x86-64 program was run. In each iteration, we ran a vector size of 2^20 until 2^30 with an increment of 2 in the exponent. 
On our first attempt, we decided to run until exponent of 30.  As the vector size increased to 2^30, our machine froze and never recovered from the program. Same goes with 2^29.

Found below is our run time for debug: (non opti)
![alt text](image.png)

Found below is our run time for release: (opti)