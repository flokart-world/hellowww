/*
 * Copyright (c) 2016 Flokart World, Inc.
 * All rights reserved.
 */

#ifndef HELLOWWW_WWWMAIN_HPP
#define HELLOWWW_WWWMAIN_HPP

#include <pion/http/request.hpp>
#include <pion/http/response.hpp>

namespace hello {

void wwwmain(pion::http::response &output,
             const pion::http::request &input);

} // namespace hello

#endif
