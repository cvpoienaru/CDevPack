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

/** Define custom logger option wrappers. */
#define CDP_LOG_CONS LOG_CONS
#define CDP_LOG_NDELAY LOG_NDELAY
#define CDP_LOG_NOWAIT LOG_NOWAIT
#define CDP_LOG_ODELAY LOG_ODELAY
#define CDP_LOG_PERROR LOG_PERROR
#define CDP_LOG_PID LOG_PID

/** Define custom logger facility wrappers. */
#define CDP_LOG_AUTH LOG_AUTH
#define CDP_LOG_AUTHPRIV LOG_AUTHPRIV
#define CDP_LOG_CRON LOG_CRON
#define CDP_LOG_DAEMON LOG_DAEMON
#define CDP_LOG_FTP LOG_FTP
#define CDP_LOG_KERN LOG_KERN
#define CDP_LOG_LOCAL0 LOG_LOCAL0
#define CDP_LOG_LOCAL1 LOG_LOCAL1
#define CDP_LOG_LOCAL2 LOG_LOCAL2
#define CDP_LOG_LOCAL3 LOG_LOCAL3
#define CDP_LOG_LOCAL4 LOG_LOCAL4
#define CDP_LOG_LOCAL5 LOG_LOCAL5
#define CDP_LOG_LOCAL6 LOG_LOCAL6
#define CDP_LOG_LOCAL7 LOG_LOCAL7
#define CDP_LOG_LPR LOG_LPR
#define CDP_LOG_MAIL LOG_MAIL
#define CDP_LOG_NEWS LOG_NEWS
#define CDP_LOG_SYSLOG LOG_SYSLOG
#define CDP_LOG_USER LOG_USER
#define CDP_LOG_UUCP LOG_UUCP

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
 * Opens a connection to the system logger for the current identity, using the
 * specified option flags and the specified default facility for subsequent
 * logger calls.
 *
 * @param identity The identity to be prepended before each log message.
 * @param option The option flags to be used when opening the system logger
 * connection.
 * @param facility The default facility to be used for subsequent system logger
 * calls.
 */
void cdp_open_log(const char *identity, const int option, const int facility);

/**
 * Closes the connection to the system logger.
 */
void cdp_close_log(void);

/**
 * Writes a message in the given format, having a specific priority, to the
 * system logger. The priority is represented by different logger levels.
 *
 * @param priority The priority of the message to be written.
 * @param format The format of the message to be written.
 * @param ... Arguments used to substitute format specifiers in the format
 * buffer with their actual values.
 */
void cdp_log(const int priority, const char *format, ...);

#endif /* C_DEV_PACK_LOGGER_LOGGER_H_ */
