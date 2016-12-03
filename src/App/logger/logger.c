#include "logger.h"

#include "bsp.h"

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdint.h>

/* ===== SETTINGS =========================================================== */


/* ===== TYPEDEFS =========================================================== */


/* ===== LOCAL ============================================================== */


static char _log_buffer[MAX_MESSAGE_LENGTH];

/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */

static void _send_to_uart(uint8_t* data, uint16_t size) {
   bsp_debug_write(data, size);
}

/* ===== IMPLEMENTATION ===================================================== */

void logger( const char* format, ...) {

    va_list args;
    va_start(args, format);

    vsnprintf(_log_buffer, MAX_MESSAGE_LENGTH, format, args);

    va_end(args);

    _send_to_uart((uint8_t*)_log_buffer, strlen(_log_buffer));
}

/* -------------------------------------------------------------------------- */
