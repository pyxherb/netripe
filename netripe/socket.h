#ifndef _NETRIPE_SOCKET_H_
#define _NETRIPE_SOCKET_H_

#include "basedefs.h"
#include <peff/base/rcobj.h>

namespace netripe {
	class AsyncBuffer : public peff::RcObject {
	private:
		size_t _size;
		char *_data;

	public:
		NETRIPE_API AsyncBuffer(size_t size, char *data);
		NETRIPE_API ~AsyncBuffer();

		NETRIPE_FORCEINLINE size_t size() const {
			return _size;
		}
		NETRIPE_FORCEINLINE const char *data() const {
			return _data;
		}
		NETRIPE_FORCEINLINE char *data() {
			return _data;
		}
	};

	using SocketSendFlags = uint32_t;
	using SocketReceiveFlags = uint32_t;

	class Socket {
	public:
		NETRIPE_API virtual ~Socket();

		virtual size_t send(const char *buffer, size_t szBuffer, SocketSendFlags sendFlags) = 0;
		virtual size_t receive(char *buffer, size_t szBuffer, SocketReceiveFlags receiveFlags) = 0;
		virtual size_t sendAsync(const char *buffer, size_t szBuffer, SocketSendFlags sendFlags) = 0;
		virtual size_t receiveAsync(char *buffer, size_t szBuffer, SocketReceiveFlags receiveFlags) = 0;
		virtual size_t sendAsync(const AsyncBuffer *buffer, SocketSendFlags sendFlags) = 0;
		virtual size_t receiveAsync(AsyncBuffer *buffer, SocketReceiveFlags receiveFlags) = 0;
	};
}

#endif
