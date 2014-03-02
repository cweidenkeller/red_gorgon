OBJS = client.h commands.h \
       common.h common.cc \
	   config.h \
	   connection.h connection.cc \
	   constants.h control.h \
	   response.h test.cpp 
all: $(OBJS) 
	g++ -Wall test.cpp -o out
