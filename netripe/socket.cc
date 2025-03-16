#include "socket.h"

using namespace netripe;

NETRIPE_API AsyncBuffer::AsyncBuffer(size_t size, char *data): _size(size), _data(data) {
}
NETRIPE_API AsyncBuffer ::~AsyncBuffer() {
}

NETRIPE_API Socket::~Socket() {}
