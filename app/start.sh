#!/bin/bash

g++ -O3 -std=c++11 -I/usr/local/include -I/usr/local/include/cppconn main.cpp -lboost_thread -lboost_system -pthread -lmysqlcppconn

./a.out