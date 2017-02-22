#ifndef FUNCTION_RELEASING_GIL_H
#define FUNCTION_RELEASING_GIL_H

#include "release_gil.hpp"
#include <boost/python.hpp>
#include <boost/unordered_map.hpp>
#include<vector>
#include<map>
#include<string>


int f_release_gil(object o)
{
    int max_i = extract<int>(o);
    int result = 0;

    {
        ScopedGILRelease s;

        for (int i = 0; i < max_i; ++i) {
            result += i;
        }
    }

    return result;
}

int f_no_release_gil(object o)
{
    int max_i = extract<int>(o);
    int result = 0;

    {
        for (int i = 0; i < max_i; ++i) {
            result += i;
        }
    }

    return result;
}

float dangerous_list_sum(list l)
{
    int size = len(l);
    float result = 0.0;

    {
        ScopedGILRelease s;

        for (int i = 0; i < size; ++i) {
            result += extract<float>(l[i]);
        }
    }

    return result;
}

float probably_safe_list_sum(list l)
{
    int size = len(l);

    // There are probably better ways to copy all the list values, but it is not important
    // for the current example.
    std::vector<float> v;
    for (int i = 0; i < size; ++i) {
        float my_value = extract<float>(l[i]);
        v.push_back(my_value);
    }

    // c++ ->

    float result = 0.0;
    {
        ScopedGILRelease s;

        for (int i = 0; i < size; ++i) {
            result += v[i];
        }
    }

    return result;
}

void fire(unsigned long long max)
{
    PyEval_SaveThread();
    unsigned long long i = 0;
    while (true)
    {
        i++;
        for (unsigned long long j = 0; j < max; j++) {
            if (i > max) {
                throw 1;
            }
        }
    }
}

int with_map(int max)
{
    std::string key;
    key.resize(4);
    std::map<std::string, int> m;
    for (int i = 0; i < max; ++i) {
        for (int j = 0; j < 4; ++j) {
            key[j] = rand() % 26 + 'a';
        }
        m[key] = i;
    }
    return m.size();
}

int with_hash(int max)
{
    std::string key;
    key.resize(4);
    boost::unordered_map<std::string, int> m;
    for (int i = 0; i < max; ++i) {
        for (int j = 0; j < 4; ++j) {
            key[j] = rand() % 26 + 'a';
        }
        m[key] = i;
    }
    return m.size();
}

int with_dict(int max)
{
    //str key;
    char buf[5];
    buf[4] = 0;
    dict m;
    // std::map<std::string, int> m;
    for (int i = 0; i < max; ++i) {
        for (int j = 0; j < 4; ++j) {
            buf[j] = rand() % 26 + 'a';
        }
        str key(buf);
        m[key] = i;
    }
    //return m.size();
    return len(m);
}

#endif