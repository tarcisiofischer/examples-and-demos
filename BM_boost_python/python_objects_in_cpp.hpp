#ifndef PYTHON_OBJECTS_IN_CPP_H
#define PYTHON_OBJECTS_IN_CPP_H

#include <boost/python.hpp>

using namespace boost::python;

/*
Boost::Python available python objects:
list
dict
tuple
str
long_
enum
*/

int return_value_from_dict(dict d)
{
    object b = d["x"];
    int cpp_b = extract<int>(b);

    return cpp_b + 1;
}

void mess_with_python_object(list t)
{
    t[0] = 1;
}

//void change_immutable(object& o)
void change_immutable(object o)
{
    // Does objects change?
    int& i = extract<int&>(o);
    i += 1;
    // TypeError: No registered converter was able to extract a C++ reference to type int from this Python object of type int
    // https://misspent.wordpress.com/2009/09/27/how-to-write-boost-python-converters/
}

enum Color { red, blue };

#endif