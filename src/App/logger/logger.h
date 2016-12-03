#ifndef __LOGGER_H__
#define __LOGGER_H__

#include "stdint.h"
#include <string.h>
#include <inttypes.h>

/* -------------------------------------------------------------------------- */

#ifdef __cplusplus
extern "C" {
#endif

/* ===== TYPEDEFS =========================================================== */

/* -------------------------------------------------------------------------- */
#define MAX_MESSAGE_LENGTH 256
/* -------------------------------------------------------------------------- */

/* ===== LOG MACROS ========================================================= */

#ifndef USE_LOG
#define USE_LOG (1)
#endif

#if USE_LOG==1

#define INFO                        logger
#define ERROR                       logger
#define DEBUG                       logger

#define LOG(...)                        logger( __VA_ARGS__)

#else /* USE_LOG==1 */

#define LOG(...)

#define INFO(...)
#define ERROR(...)
#define DEBUG(...)

#endif /* USE_LOG==1 */

/* -------------------------------------------------------------------------- */

#define TEST_LOG_LENGTH             (256)
/* -------------------------------------------------------------------------- */

/* ===== PROTOTYPES ========================================================= */

void logger(const char* format, ...);

/* -------------------------------------------------------------------------- */

#ifdef __cplusplus
}
#endif

#endif /*__LOGGER_H__*/
