#include "pl.hpp"

string get_domain(string url) {
    boost::regex ex("(http|https)://([^/ :]+):?([^/ ]*)(/?[^ #?]*)\\x3f?([^ #]*)#?([^ ]*)");
    boost::cmatch what;
    if (regex_match(url.c_str(), what, ex)) {
        string result = string(what[1].first, what[1].second) + "://" + string(what[2].first, what[2].second) + "/";
        return result;
    }
}
