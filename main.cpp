#include <algorithm>
#include <boost/context/continuation.hpp>
#include <iostream>
#include <iterator>

int main() {
    namespace ctx = boost::context;
    int a;
    ctx::continuation source = ctx::callcc([&a](ctx::continuation &&sink) {
        a = 0;
        int b = 1;
        for (;;) {
            sink = sink.resume();
            int next = a + b;
            a = b;
            b = next;
        }
        return std::move(sink);
    });
    for (int j = 0; j < 10; ++j) {
        std::cout << a << " ";
        source = source.resume();
    }
}