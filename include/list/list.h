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

#ifndef C_DEV_PACK_LIST_LIST_H_
#define C_DEV_PACK_LIST_LIST_H_

#include <defs.h>
#include <list/array_list.h>
#include <list/linked_list.h>

#define CDP_LIST_TYPE_ARRAY_LIST 0
#define CDP_LIST_TYPE_LINKED_LIST 1

struct cdp_list {
	int type;
	struct cdp_array_list *array_list;
	struct cdp_linekd_list *linked_list;
};

#endif /* C_DEV_PACK_LIST_LIST_H_ */