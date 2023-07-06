# DANTE
## Table of Contents
1. [General Info](#general-info)
2. [Technologies](#technologies)
3. [Installation](#installation)
4. [Overview](#Overview)
### General Info
***
Dante is a project where we need to generate a maze that can be perfect or not, and resolve this latter.
## Technologies
***
A list of technologies used within the project:
* C
* Makefile
## Installation
***
How to install our dante. 
```
$ git clone B-CPE-200-BDX-2-1-dante-killian.trouve
$ cd PATH_NAME
$ make
$ ./PROJECT_NAME/generator   or   ./PROJECT_NAME/solver
```
## Overview
***
Some exemples :
```
./generator/generator 29 6
***** XX **** X ******** XXXX
XX ****** XX *** XXXXX *** XXX
XX *** XXXX ** XXXXX **** XXXX
XX *** XXXXXXXXXXXXXX **** X
***** XXXXXX **** XX *** XXXX
XX ************* XXXX *****
```

```
./solver/solver maze.txt
o o oo o X X oo o o X oo o o o oo o X X XX
XX ** ooooXXoooXXXXX * o * XXX
XX *** XXXX ** XXXXX *** oXXXX
XX *** XXXXXXXXXXXXXXo *** X
***** XXXXXX **** XX ** oXXXX
XX ************* XXXXooooo
```