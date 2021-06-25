#include "pl.hpp"

string domain;
static size_t cb(void * data, size_t size, size_t nmemb, void * userp) { //setting callback

    //data contains data from url. size is always 1 (?)
    //nmemb is size of data. userp is for WRITEDATA(to write data in FILE??)
    size_t realsize = size * nmemb;
    string result = string((char * ) data);
    pars(result, domain);
    //cout<<domain<<endl;
    return realsize; //callback must return size*nmemb(?)

};

void Load(const string link) {
    domain = get_domain(link);
    long http;
    CURL * curl = curl_easy_init(); //stats easy session

    //setting options
    curl_easy_setopt(curl, CURLOPT_URL, link.c_str()); //for getting "html code"
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    //	curl_easy_setopt(curl, CURLOPT_HEADER, 1L); //for getting metadata
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, cb); //for callback 

    CURLcode res = curl_easy_perform(curl); // performing transfer as described in options
    //requesting information from session
    curl_easy_getinfo(curl, CURLINFO_HTTP_CODE, & http); // same as CURLINFO_RESPONSE_CODE
    //cout<<page.data<<endl;
    //pars(result);
    curl_easy_cleanup(curl); //ends easy session

};