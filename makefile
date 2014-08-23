#****************************************************************
#
# Name: Christopher Vaughn
# SL ID: cdv5673
# Date: 10/06/02
# Project: #3 Maze
#
# Filename: makefile
#
# Certificate of Authenticity:
#	I Christopher Vaughn hereby state the following code is
#	entirely my own work.
#
#****************************************************************

all: disjsets.o driver.o mazegen.o
	g++ -o mazegen driver.o mazegen.o disjsets.o

disjsets.o: disjsets.cpp
	g++ -c disjsets.cpp

mazegen.o: mazegen.cpp
	g++ -c mazegen.cpp

driver.o: driver.cpp
	g++ -c driver.cpp

