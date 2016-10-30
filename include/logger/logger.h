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

#ifndef C_DEV_PACK_LOGGER_LOGGER_H_
#define C_DEV_PACK_LOGGER_LOGGER_H_

#include <syslog.h>

/**
 * We need to define wrappers over UNIX syslog definitions in order to be used
 * throughout the codebase because of portability concerns. This will be useful
 * if deciding to port the logger to non-UNIX environments.
 */

/** Define custom logger level wrappers. */
#define CDP_LOG_EMERG LOG_EMERG
#define CDP_LOG_ALERT LOG_ALERT
#define CDP_LOG_CRIT LOG_CRIT
#define CDP_LOG_ERR LOG_ERR
#define CDP_LOG_WARNING LOG_WARNING
#define CDP_LOG_NOTICE LOG_NOTICE
#define CDP_LOG_INFO LOG_INFO
#define CDP_LOG_DEBUG LOG_DEBUG

/**
 * Writes a message in the given format, having a specific priority, to the
 * default logging repository. The priority is represented by different logger
 * levels.
 *
 * @param priority The priority of the message to be written.
 * @param format The format of the message to be written.
 * @param ... Arguments used to substitute format specifiers in the format
 * buffer with their actual values.
 * @return CDP_SUCCESS if the operation was successfull, CDP_FAILURE otherwise.
 */
const int cdp_log(const int priority, const char *format, ...);

#endif /* C_DEV_PACK_LOGGER_LOGGER_H_ */
