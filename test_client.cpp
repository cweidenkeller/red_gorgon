#include "client.h"
#include <string>
#include <iostream>
using namespace std;
using namespace nova::redis;
int main(int argc, char* argv[])
{
    Client client = Client("localhost", "6379", "conrad", "test_redis.conf");
    response res = client.ping();
    cout << res.status << " || "<< res.data << endl;
    res = client.bgsave();
    cout << res.status << " || "<< res.data << endl;
    res = client.save();
    cout << res.status << " || "<< res.data << endl;
    res = client.last_save();
    cout << res.status << " || " << res.data << endl;
    res = client.config_get("client-output-buffer-limit");
    cout << res.status << " || "<< res.data << endl;
    res = client.config_set("requirepass", "password");
    cout << res.status << " || " << res.data << endl;
    res = client.config_rewrite();
    cout << res.status << " || " << res.data << endl;
}
