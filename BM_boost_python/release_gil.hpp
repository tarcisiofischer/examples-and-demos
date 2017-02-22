#ifndef RELEASE_GIL_H
#define RELEASE_GIL_H

#include <boost/python.hpp>

// From: http://pieceofpy.com/2010/02/26/boost-python-threads-and-releasing-the-gil/
class ScopedGILRelease {
public:
    inline ScopedGILRelease() { m_thread_state = PyEval_SaveThread(); }
    inline ~ScopedGILRelease() {
        PyEval_RestoreThread(m_thread_state);
        m_thread_state = NULL;
    }
private:
    PyThreadState* m_thread_state;
};

#endif