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
    sleep(2);
    cout << res.status << endl<< res.data << endl;
    res = client.bgsave();
    sleep(2);
    cout << res.status << endl<< res.data << endl;
    res = client.save();
    sleep(2);
    cout << res.status << endl<< res.data << endl;
    sleep(2);
    res = client.last_save();
    cout << res.status << endl<< res.data << endl;
    sleep(2);
    res = client.config_get("requirepass");
    cout << res.status << endl<< res.data << endl;
    sleep(2);
    res = client.config_set("requirepass", "foo");
    cout << res.status << endl<< res.data << endl;
    sleep(2);
    res = client.config_rewrite();
    cout << res.status << endl<< res.data << endl;
}
