#include "hello_world_function.hpp"
#include "exposing_classes.hpp"
#include "returning_stuff.hpp"
#include "f_with_default_arguments.hpp"
#include "python_objects_in_cpp.hpp"
#include "function_releasing_gil.hpp"
#include "factorial_example.hpp"
#include "numpy_stuff.hpp"

#include <boost/python.hpp>
#include <iostream>

using namespace boost::python;

void register_hello_world()
{
    // Docs: http://www.boost.org/doc/libs/1_59_0/libs/python/doc/v2/def.html
    def(
        "greet",        // The function name in python
        &greet          // The function name in C++ code
//        "greet docs..." // The function documentation
    );
}

// ================================================================================================

void register_exposing_classes()
{
    //class_<World, boost::shared_ptr<World>>("World", init<std::string>())
    //    .def("greet", &World::greet)
    //    .def("set", &World::set)
    //    ;

    // Or, like I saw many times in our projects...
    // The main advantage of using it this way is that if an error occurs, it is easy to say
    // where it happened (Compile error is easy to read and identify).
    typedef World T;
    class_<T, boost::shared_ptr<T>> c(    // Expose the class and it's shared pointer to Python
        "World",                          // Class name in Python
        init<std::string>(                // __init__(self, msg) python function with
            (arg("msg")),                 // docs
            "World docs ..."
        )
    );

    c.def("greet", &World::greet);        // Expose class member functions to Python
    c.def("set", &World::set);
}

// ================================================================================================

void register_returning_stuff()
{
    def("f_return_simple_object", f_return_simple_object);

    def("my_f_with_shared_ptr", f_return_shared_ptr);

    // Call policies, the "reference_existing_object: naive (dangerous) approach"
    // http://www.boost.org/doc/libs/1_59_0/libs/python/doc/tutorial/doc/html/python/functions.html#python.call_policies
    def("WRONG_f_return_reference", WRONG_f_return_reference, return_value_policy<reference_existing_object>());
    def("f_return_reference", f_return_reference, return_value_policy<reference_existing_object>());

    // As this is not really much used or suggested in ESSS code (We always use shared pointers), I didn't bother explaining
    // too deep. We can try more stuff if needed in BookMeeting. Just take a look in the boost manual examples.
}

// ================================================================================================

int f_with_default_arguments1(int a) { return f_with_default_arguments(a); }
int f_with_default_arguments2(int a, int b) { return f_with_default_arguments(a, b); }
int f_with_default_arguments3(int a, int b, int c) { return f_with_default_arguments(a, b, c); }
void register_default_arguments()
{
    def("f_with_default_arguments", f_with_default_arguments1);
    def("f_with_default_arguments", f_with_default_arguments2);
    def("f_with_default_arguments", f_with_default_arguments3);
}
// Better approach: Use boost python macros :)
BOOST_PYTHON_FUNCTION_OVERLOADS(f_with_default_arguments_overloads, f_with_default_arguments, 1, 3)
void register_default_arguments_2()
{
    def("f_with_default_arguments2", f_with_default_arguments, f_with_default_arguments_overloads());
}

// ================================================================================================

void register_python_objects_in_cpp()
{
    def("return_value_from_dict", return_value_from_dict);
    def("mess_with_python_object", mess_with_python_object);
    def("change_immutable", change_immutable);

    enum_<Color>("Color")
        .value("red", red)
        .value("blue", blue)
        ;
}

void register_function_releasing_gil()
{
    def("f_release_gil", f_release_gil);
    def("f_no_release_gil", f_no_release_gil);
    def("dangerous_list_sum", dangerous_list_sum);
    def("probably_safe_list_sum", probably_safe_list_sum);
}

// ================================================================================================

void register_factorial_example()
{
    def("factorial", factorial);
    def("factorial_nogil", factorial_nogil);
}

// ================================================================================================

void register_numpy_sum_all()
{
    def("numpy_sum_all", numpy_sum_all);
}

// ================================================================================================

BOOST_PYTHON_MODULE(hello_ext)
{
    // Bookmeeting 1
    register_hello_world();
    register_exposing_classes();

    // Bookmeeting 2
    register_returning_stuff();
    register_default_arguments();
    register_default_arguments_2();

    // Bookmeeting 3
    // (Issues from bookmeeting2)
    register_python_objects_in_cpp();

    // Python vs Cython (Features)
    register_factorial_example();
    register_function_releasing_gil();

    // Future
    // Boost::Python + Numpy
    boost::python::numeric::array::set_module_and_type("numpy", "ndarray");
    register_numpy_sum_all();

    def("fire", &fire);

    def("with_map", &with_map);
    def("with_hash", &with_hash);
    def("with_dict", &with_dict);
}
