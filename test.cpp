#include "redis.h"
#include <string>
#include <iostream>
#include <unistd.h>
using namespace std;
using namespace redis;
int main(int argc, char* argv[])
{
    RedisClient client = RedisClient("localhost", "6379", "conrad");
    redis_response res = client.ping();
    cout << res.status << endl<< res.data << endl;
    res = client.bgsave();
    cout << res.status << endl<< res.data << endl;
    res = client.save();
    cout << res.status << endl<< res.data << endl;
    res = client.last_save();
    cout << res.status << endl<< res.data << endl;
    res = client.config_get("requirepass");
    cout << res.status << endl<< res.data << endl;
    res = client.config_set("requirepass", "password");
    cout << res.status << endl<< res.data << endl;
    res = client.config_rewrite();
    cout << res.status << endl<< res.data << endl;
}
