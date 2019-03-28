# api-rest-crow-docker
API exemplo com framework C++ de microserviços CROW, executando com docker.

# Intalation
If you want to use Crow, just download amalgamate/crow_all.h and include it at your source file.

You need to link with boost_thread and boost_system. Check Dependency section.

# Dependency
Crow dependes on boost library for asio and other utilities.

Use your package manager to install boost and don't forget to linking to boost-thread and boost-system.

`sudo apt install libboost-all-dev libssl-dev  # (Ubuntu)`

`brew install boost  # (Mac)`

Compile and run with following command:

```g++ -O3 -std=c++11 main.cpp -lboost_thread -lboost_system -pthread

g++ -O3 -std=c++11 main.cpp -lboost_thread_mt -lboost_system_mt -pthread # if linker cannot find boost_system, try this
```

Run with following command:

```sh
./a.out
(2015-01-08 13:37:43) [INFO    ] Crow/0.1 server is running, local port 8080
```
