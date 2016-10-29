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

#ifndef C_DEV_PACK_DEFS_H_
#define C_DEV_PACK_DEFS_H_

#include <stdlib.h>

/** Define the boolean values here if not already defined. */
#if !defined(FALSE) && !defined(TRUE)
#define FALSE 0
#define TRUE !(FALSE)
#endif

/** Define both successfull and unsuccessfull generic operation codes. */
#define CDP_SUCCESS EXIT_SUCCESS
#define CDP_FAILURE EXIT_FAILURE

/**
 * Define new generic data types to use throughout the codebase for portability
 * concerns.
 */
typedef unsigned int cdp_size_t;
typedef unsigned int cdp_index_t;

#endif /* C_DEV_PACK_DEFS_H_ */
