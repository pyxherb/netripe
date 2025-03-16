#ifndef _NETRIPE_BASEDEFS_H_
#define _NETRIPE_BASEDEFS_H_

#include <peff/base/basedefs.h>

#if NETRIPE_BUILD_SHARED
	#if NETRIPE_IS_BUILDING

		#if NETRIPE_BUILD_SHARED
			#define NETRIPE_API PEFF_DLLEXPORT
		#endif

	#else

		#if SLAKE_BUILD_SHARED
			#define NETRIPE_API PEFF_DLLIMPORT
		#endif

	#endif
#else
	#define NETRIPE_API
#endif

#define NETRIPE_FORCEINLINE PEFF_FORCEINLINE

#endif
