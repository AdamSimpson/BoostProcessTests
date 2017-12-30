#include <iostream>
#include "boost/process.hpp"
#include "boost/asio.hpp"
#include "boost/asio/spawn.hpp"

namespace bp = boost::process;
namespace asio = boost::asio;

int main() {
    std::error_code build_ec;
    asio::io_context io_context;
    bp::async_pipe pipe(io_context);

    bp::child build_child("/usr/bin/printenv", (bp::std_out & bp::std_err) > pipe, build_ec);
    if (build_ec)
        std::cout << "child error" << std::endl;

    asio::spawn(io_context, [&](asio::yield_context yield) {
        boost::system::error_code read_ec;
        std::array<char, 4096> buffer;
        do {
            auto read_bytes = pipe.async_read_some(asio::buffer(buffer), yield[read_ec]);
            if (read_ec)
                std::cout << "read_some error: " << read_ec.message() << std::endl;

            std::cout.write(buffer.data(), read_bytes);
        } while (read_ec != asio::error::eof);
    });

    io_context.run();

    build_child.wait();

    return 0;
}