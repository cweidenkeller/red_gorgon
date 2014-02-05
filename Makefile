all: redis.h  redis_constants.h  connection.h  test.cpp 
	g++ redis.h  redis_constants.h  connection.h  test.cpp -o out
