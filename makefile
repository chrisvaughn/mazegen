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

run: disjsets.o driver.o mazegen.o
	CC -o run driver.o mazegen.o disjsets.o

disjsets.o: disjsets.cpp
	CC -c disjsets.cpp

mazegen.o: mazegen.cpp
	CC -c mazegen.cpp

driver.o: driver.cpp
	CC -c driver.cpp

