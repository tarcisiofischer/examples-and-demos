#ifndef RETURNING_STUFF_H
#define RETURNING_STUFF_H

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include "exposing_classes.hpp"

boost::shared_ptr<World> f_return_shared_ptr()
{
    return boost::make_shared<World>("I've been created with my_f_with_shared_ptr");
}

World& WRONG_f_return_reference()
{
    World w("I'm awesome!");
    return w;
}

World w("I've been returned as reference");
World& f_return_reference()
{
    return w;
}

World f_return_simple_object()
{
    return World("I'm such a simple guy.");
}

#endif