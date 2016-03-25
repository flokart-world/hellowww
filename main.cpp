/*
 * Copyright (c) 2016 Flokart World, Inc.
 * All rights reserved.
 */

#include "server.hpp"

int main(int /* argc */, char * /* argv */ []) {
    hello::run_service(8000);

    return 0;
}
