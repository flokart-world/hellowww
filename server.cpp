/*
 * Copyright (c) 2016 Flokart World, Inc.
 * All rights reserved.
 */

#include "server.hpp"

#include <iostream>
#include <boost/bind.hpp>
#include <pion/http/response.hpp>
#include <pion/http/response_writer.hpp>
#include <pion/http/server.hpp>
#include "wwwmain.hpp"

namespace hello {

namespace {

class response_processing {
private:
    typedef response_processing self_type;

    pion::tcp::connection_ptr M_communication;
    pion::http::response_ptr M_output;

    boost::shared_ptr<pion::http::response_writer> M_writer;

    void finish(const boost::system::error_code &result);

public:
    response_processing(const pion::tcp::connection_ptr &communication,
                        const pion::http::response_ptr &output);

    void start();
};

void response_processing
     ::finish(const boost::system::error_code & /* result */) {

    delete this;
}

response_processing
::response_processing(const pion::tcp::connection_ptr &communication,
                      const pion::http::response_ptr &output) :
        M_communication(communication),
        M_output(output),
        M_writer(pion::http::response_writer::create(
                         M_communication,
                         M_output,
                         boost::bind(&self_type::finish, this, _1))) {
}

void response_processing::start() {
    M_writer->send();
}

void run_main(const pion::http::request_ptr &input,
              const pion::tcp::connection_ptr &communication) {

    pion::http::response_ptr output(new pion::http::response);

    wwwmain(*output, *input);
    (new response_processing(communication, output))->start();
}

} // namespace

void run_service(unsigned int port) {
    char end;

    pion::http::server main_server(port);

    main_server.add_resource("/", run_main);
    main_server.start();

    std::cout << "Started HTTP server on port "
              << main_server.get_port()
              << "."
              << std::endl
              << "Enter any text to stop the server."
              << std::endl;

    std::cin >> end;

    main_server.stop();
    main_server.join();
}

} // namespace hello
