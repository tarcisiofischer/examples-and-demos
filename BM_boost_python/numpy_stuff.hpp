void numpy_sum_all(boost::python::numeric::array& data)
{
    std::cout << "First array item: " << extract<float>(data[0]) << std::endl;
}
