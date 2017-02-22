// Based on the examples in http://www.boost.org/doc/libs/1_59_0/libs/python/doc/tutorial/doc/html/python/exposing.html

#ifndef EXPOSING_CLASSES_H
#define EXPOSING_CLASSES_H

#include <iostream>

class World
{
public:
    World(std::string const& msg) : msg(msg) {}

    void set(std::string const& msg) { this->msg = msg; }
    std::string greet() { return msg; }

private:
    std::string msg;
};

#endif