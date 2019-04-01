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

```sh
g++ -O3 -std=c++11 main.cpp -lboost_thread -lboost_system -pthread

g++ -O3 -std=c++11 main.cpp -lboost_thread_mt -lboost_system_mt -pthread # if linker cannot find boost_system, try this
```

Run with following command:

```sh
./a.out
(2015-01-08 13:37:43) [INFO    ] Crow/0.1 server is running, local port 8080
```


# Docker
```
docker build -t crow .

docker run -ti -p 8084:8084 --rm --network="host" --cpus=3 --name="crow" crow bash start.sh

```

# Links Importantes:

[link1](https://dev.mysql.com/doc/connector-cpp/1.1/en/connector-cpp-examples-prepared-statements.html)
[link2](https://www.codesynthesis.com/products/odb/)
[link3](https://dev.mysql.com/doc/connector-cpp/1.1/en/connector-cpp-tutorials-background.html)
[link4](https://dev.mysql.com/doc/connector-cpp/1.1/en/connector-cpp-examples-complete-example-2.html)
[link5](https://dev.mysql.com/doc/connector-cpp/8.0/en/connector-cpp-apps-make.html)
[link6 - Doc oficial](https://github.com/ipkn/crow)
[link7 -exemplo web](https://github.com/ipkn/crow/wiki/Quickstart)
[link8](https://devhub.io/repos/chansuke-crow)
