#include <iostream>
#include <thread>
#include "cinatra.hpp"

using namespace std;
//using namespace cinatra;
void test() {
    cout << "my begin" << endl;
    cout << "my end" << endl;
}

void myprint(const int &i, const char* pmybuf){
   cout << i << endl;
   cout << *pmybuf <<endl;
}
class TA {
public:
    int &m_i;

    explicit TA(int &i) : m_i(i) {
        cout << "constructor run ... finish" <<endl;
    }

    TA(const TA &ta) : m_i(ta.m_i) {
        cout << "copy run ... finish" << endl;
    }

    ~TA(){
        cout << "deconstruction run ... finish " << endl;
    }

    void operator()() {
        cout << "ta begin" << endl;
        cout << "ta end" << endl;
    }
};

int main() {
//    thread mytest(test);
//    mytest.join();
//    std::cout << "Hello, World!" << std::endl;

//    int mi = 3;
//    TA ta(mi);
//    thread myobj3(ta);
//    myobj3.join();
//    TA ta1 = ta;
//    int a = 1;
//    int *b = &a;
//    char mybuf[] = "this is a test";
//    thread myobj(myprint, a, mybuf);
//    myobj.join();

    cinatra::http_server server(std::thread::hardware_concurrency());
    server.listen("0.0.0.0", "8080");
    server.set_http_handler<cinatra::GET, cinatra::POST>("/test", [](cinatra::request& req, cinatra::response& res) {
        auto name = req.get_header_value("name");
        if (name.empty()) {
            res.set_status_and_content(cinatra::status_type::bad_request, "no name");
            return;
        }

        auto id = req.get_query_value("id");
        if (id.empty()) {
            res.set_status_and_content(cinatra::status_type::bad_request);
            return;
        }

        res.set_status_and_content(cinatra::status_type::ok, "hello world");
    });

    server.run();
    return 0;
}
