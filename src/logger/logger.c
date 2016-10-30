/**
 * Copyright (c) 2016, Codrin-Victor Poienaru <cvpoienaru@gmail.com>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * This software is provided by the copyright holders and contributors "as is"
 * and any express or implied warranties, including, but not limited to, the
 * implied warranties of merchantability and fitness for a particular purpose
 * are disclaimed. In no event shall the copyright holder or contributors be
 * liable for any direct, indirect, incidental, special, exemplary, or
 * consequential damages (including, but not limited to, procurement of
 * substitute goods or services; loss of use, data, or profits; or business
 * interruption) however caused and on any theory of liability, whether in
 * contract, strict liability, or tort (including negligence or otherwise)
 * arising in any way out of the use of this software, even if advised of the
 * possibility of such damage.
 */

#include <logger/logger.h>

#include <defs.h>

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <syslog.h>

/**
 * Checks if the specified argument is a valid logging priority.
 *
 * @param priority The priority to be validated.
 * @return CDP_SUCCESS if the priority is valid, CDP_FAILURE otherwise.
 */
static inline const int cdp_validate_log_priority(const int priority)
{
	switch(priority) {
		case CDP_LOG_EMERG:
		case CDP_LOG_ALERT:
		case CDP_LOG_CRIT:
		case CDP_LOG_ERR:
		case CDP_LOG_WARNING:
		case CDP_LOG_NOTICE:
		case CDP_LOG_INFO:
		case CDP_LOG_DEBUG:
			return CDP_SUCCESS;

		default:
			return CDP_FAILURE;
	}
}

/**
 * Writes a message in the given format, having a specific priority, to the
 * default logging repository. The priority is represented by different logger
 * levels.
 *
 * @param priority The priority of the message to be written.
 * @param format The format of the message to be written.
 * @param ... Arguments used to substitute format specifiers in the format
 * buffer with their actual values.
 * @return CDP_SUCCESS if the operation is successfull, CDP_FAILURE otherwise.
 */
const int cdp_log(const int priority, const char *format, ...)
{
	if(cdp_validate_log_priority(priority) != CDP_SUCCESS)
		return CDP_FAILURE;
	if(!format)
		return CDP_FAILURE;

	va_list args;

	/* Get the variable arguments list and direct it to the syslog function. */
	va_start(args, format);
	vsyslog(priority, format, args);
	va_end(args);

	return CDP_SUCCESS;
}
