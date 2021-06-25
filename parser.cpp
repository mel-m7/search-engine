#include "parser.hpp"

vector < string > urls;

void pars(string html, string domain) {
    HTML::ParserDom parser;
    tree < HTML::Node > dom = parser.parseTree(html);
    tree < HTML::Node > ::iterator it = dom.begin();
    tree < HTML::Node > ::iterator end = dom.end();

    for (; it != end; ++it) {
        if (strcasecmp(it -> tagName().c_str(), "a") == 0) {
            it -> parseAttributes();
            string a = it -> attribute("href").second;
            if (!a.empty()) {
                if (a[0] == '.') {
                    a.erase(0, 2);
                    a.insert(0, domain);
                } else if (a[0] == '/') {
                    a.erase(0, 1);
                    a.insert(0, domain);
                } else if (!(regex_match(a, regex("((http|https)://)(www.)?[a-zA-Z0-9@:%._\\+~#?&//=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%._\\+~#?&//=]*)")))) {
                    a.insert(0, domain);
                }
                if (a.find(domain) != string::npos) {
                    cout << a << endl;
                }
            }
        }
    }
    it = dom.begin();
    end = dom.end();
    for (; it != end; ++it) {
        if (strcasecmp(it -> tagName().c_str(), "img") == 0) {
            it -> parseAttributes();
            string a = it -> attribute("src").second;
            if (!a.empty()) {
                if (a[0] == '.') {
                    a.erase(0, 2);
                    a.insert(0, domain);
                } else if (a[0] == '/') {
                    a.erase(0, 1);
                    a.insert(0, domain);
                } else if (!(regex_match(a, regex("((http|https)://)(www.)?[a-zA-Z0-9@:%._\\+~#?&//=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%._\\+~#?&//=]*)")))) {
                    a.insert(0, domain);
                }
                if (a.find(domain) != string::npos) {
                    cout << a << "  |";
                    cout << it -> attribute("alt").second << endl;
                }
            }
        }
    }

}