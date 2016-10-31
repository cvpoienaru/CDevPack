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

#include <list/list_metadata.h>

#include <defs.h>
#include <logger/logger.h>

#include <stdlib.h>

struct cdp_list_metadata* cdp_create_list_metadata(void)
{
	struct cdp_list_metadata *metadata = NULL;

	metadata = (struct cdp_list_metadata*)malloc(
		sizeof(struct cdp_list_metadata));
	if(!metadata) {
		cdp_log(CDP_LOG_ERR, "Error: Cannot create list metadata.");
		return metadata;
	}

	metadata->items_used = 0;
	metadata->items_allocated = 0;

	return metadata;
}

struct cdp_list_metadata* cdp_create_list_metadata_copy(
	struct cdp_list_metadata *metadata)
{
	struct cdp_list_metadata *metadata_copy = NULL;

	if(!metadata) {
		cdp_log(CDP_LOG_ERR, "Error: No list metadata to copy.");
		return metadata_copy;
	}
	if(cdp_validate_list_metadata(metadata) != CDP_SUCCESS) {
		cdp_log(CDP_LOG_ERR, "Error: List metadata failed validation.");
		return metadata_copy;
	}

	metadata_copy = cdp_create_list_metadata();
	if(!metadata_copy) {
		cdp_log(CDP_LOG_ERR, "Error: Cannot create list metadata copy.");
		return metadata_copy;
	}

	metadata_copy->items_used = metadata->items_used;
	metadata_copy->items_allocated = metadata->items_allocated;

	return metadata_copy;
}

void cdp_destroy_list_metadata(struct cdp_list_metadata **metadata)
{
	if(!metadata || !(*metadata)) {
		cdp_log(CDP_LOG_WARNING, "Warning: No list metadata to destroy.");
		return;
	}

	free(*metadata);
	*metadata = NULL;
}

const int cdp_validate_list_metadata(struct cdp_list_metadata *metadata)
{
	if(!metadata) {
		cdp_log(CDP_LOG_ERR, "Error: No list metadata to validate.");
		return CDP_FAILURE;
	}

	if(metadata->items_used < 0) {
		cdp_log(
			CDP_LOG_ERR,
			"Error: Invalid number of list metadata items used (%li).",
			metadata->items_used);
		return CDP_FAILURE;
	}
	if(metadata->items_allocated < 0) {
		cdp_log(
			CDP_LOG_ERR,
			"Error: Invalid number of list metadata items allocated (%li).",
			metadata->items_allocated);
		return CDP_FAILURE;
	}
	if(metadata->items_used > metadata->items_allocated) {
		cdp_log(
			CDP_LOG_ERR,
			"Error: Items used (%li) are greater than items allocated (%li).",
			metadata->items_used,
			metadata->items_allocated);
		return CDP_FAILURE;
	}

	return CDP_SUCCESS;
}

const cdp_size_t cdp_get_list_metadata_items_used(
	struct cdp_list_metadata *metadata)
{
	if(!metadata) {
		cdp_log(CDP_LOG_ERR, "Error: Invalid list metadata pointer.");
		return CDP_SIZE_INVALID;
	}
	if(cdp_validate_list_metadata(metadata) != CDP_SUCCESS) {
		cdp_log(CDP_LOG_ERR, "Error: List metadata failed validation.");
		return CDP_SIZE_INVALID;
	}

	return metadata->items_used;
}

const cdp_size_t cdp_get_list_metadata_items_allocated(
	struct cdp_list_metadata *metadata)
{
	if(!metadata) {
		cdp_log(CDP_LOG_ERR, "Error: Invalid list metadata pointer.");
		return CDP_SIZE_INVALID;
	}
	if(cdp_validate_list_metadata(metadata) != CDP_SUCCESS) {
		cdp_log(CDP_LOG_ERR, "Error: List metadata failed validation.");
		return CDP_SIZE_INVALID;
	}

	return metadata->items_allocated;
}

const int cdp_set_list_metadata_items_used(
	struct cdp_list_metadata *metadata, cdp_size_t items_used)
{
	if(!metadata) {
		cdp_log(CDP_LOG_ERR, "Error: Invalid list metadata pointer.");
		return CDP_FAILURE;
	}
	if(cdp_validate_list_metadata(metadata) != CDP_SUCCESS) {
		cdp_log(CDP_LOG_ERR, "Error: List metadata failed validation.");
		return CDP_FAILURE;
	}
	if(items_used < 0) {
		cdp_log(
			CDP_LOG_ERR,
			"Error: Invalid number of list metadata items used (%li).",
			items_used);
		return CDP_FAILURE;
	}
	if(items_used > metadata->items_allocated) {
		cdp_log(
			CDP_LOG_ERR,
			"Error: Items used (%li) are greater than items allocated (%li).",
			items_used,
			metadata->items_allocated);
		return CDP_FAILURE;
	}

	metadata->items_used = items_used;
	return CDP_SUCCESS;
}

const int cdp_set_list_metadata_items_allocated(
	struct cdp_list_metadata *metadata, cdp_size_t items_allocated)
{
	if(!metadata) {
		cdp_log(CDP_LOG_ERR, "Error: Invalid list metadata pointer.");
		return CDP_FAILURE;
	}
	if(cdp_validate_list_metadata(metadata) != CDP_SUCCESS) {
		cdp_log(CDP_LOG_ERR, "Error: List metadata failed validation.");
		return CDP_FAILURE;
	}
	if(items_allocated < 0) {
		cdp_log(
			CDP_LOG_ERR,
			"Error: Invalid number of list metadata items allocated (%li).",
			items_allocated);
		return CDP_FAILURE;
	}
	if(metadata->items_used > items_allocated) {
		cdp_log(
			CDP_LOG_ERR,
			"Error: Items used (%li) are greater than items allocated (%li).",
			metadata->items_used,
			items_allocated);
		return CDP_FAILURE;
	}

	metadata->items_allocated = items_allocated;
	return CDP_SUCCESS;
}
