
#include "CException.h"

namespace util {
CException::CException(const std::string & msg)
    : std::runtime_error(msg) {
}

CSquareOutOfRange::CSquareOutOfRange(const std::string & msg)
    : CException(msg) {
}

CInvalidSquareState::CInvalidSquareState(const std::string & msg)
    : CException(msg) {
}

CInvalidMove::CInvalidMove(const std::string & msg)
    : CException(msg) {
}

}

