#include <map>
#include <fsream>
namespace redis
{
    class RedisConfig
    {
        private:
            map<string, string>_options;
            vector<string> _include;
            string _get_string_value(string key)
            {
                if (options.count(key) > 0)
                {
                    return _options[key];
                }
                return NULL;
            }
            int _get_int_value(string key)
            {
                if (_options.count(key) > 0)
                {
                    return to_int(_options[key]);
                }
                return NULL;
            }
            bool _get_bool_value(string key)
            {
                if (_options.count(key) > 0)
                {
                    if (_options[key] == TYPE_TRUE)
                    {
                        return true;
                    }
                    if (_options[key] == TYPE_FALSE)
                    {
                        return false;
                    }
                }
                return NULL;
            }
        public:
            vector<string> get_include_files()
            {
                return _include;
            }
            void add_include_file(string value)
            {
                _include.append(value);
            }
        
    };
}
