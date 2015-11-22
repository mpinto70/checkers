
#pragma once

#include <stdexcept>
#include <string>

namespace util {
/** game exception. */
class CException : public std::runtime_error {
    public:
        /** creates the object.
         * @param msg the error message (accessible via what())
         */
        explicit CException(const std::string & msg);
};

/** square out of range exception. */
class CSquareOutOfRange : public CException {
    public:
        /** creates the object.
         * @param msg the error message (accessible via what())
         */
        explicit CSquareOutOfRange(const std::string & msg);
};

/** invalid state for square exception. */
class CInvalidSquareState : public CException {
    public:
        /** creates the object.
         * @param msg the error message (accessible via what())
         */
        explicit CInvalidSquareState(const std::string & msg);
};

}
