OBJS = redis.h redis_constants.h redis_commands.h redis_response.h \
       connection.h connection.cc common.h test.cpp
all: $(OBJS) 
	g++ -Wall test.cpp -o out
