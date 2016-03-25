/*
 * Copyright (c) 2016 Flokart World, Inc.
 * All rights reserved.
 */

#include "wwwmain.hpp"

#include <sstream>

namespace hello {

void wwwmain(pion::http::response &output,
             const pion::http::request &input) {

    std::ostringstream content;

    content << "<!DOCTYPE html>"
            << "<html>"
            << "<h1>HelloWWW</h1>"
            << "<p>Hello, World!</p>"
            << "</html>";

    output.set_content_type("text/html; charset=utf-8");
    output.set_content(content.str());
}

} // namespace hello
