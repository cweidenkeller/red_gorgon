OBJS = \
	client.h commands.h \
	common.h common.cc \
	config.h \
	connection.h connection.cc \
	constants.h control.h \
	response.h test_client.cpp
all: $(OBJS)
	mkdir bin/
	g++ -Wall test_client.cpp -o bin/test_client
	g++ -Wall test_config.cpp -o bin/test_config
	g++ -Wall test_constants.cpp -o bin/test_constants
	g++ -Wall test_control.cpp -o bin/test_control
	cp etc/test_redis.conf bin/test_redis.conf
clean:
	rm -rf bin/
