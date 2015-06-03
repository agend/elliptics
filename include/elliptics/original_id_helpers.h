#ifndef __ORIGINAL_ID_HELPERS_H
#define __ORIGINAL_ID_HELPERS_H

#include <eblob/blob.h>
#include "elliptics/packet.h"
#include "elliptics/interface.h"

#ifdef __cplusplus
extern "C" {
#endif

const int ORIGINAL_ID_SIZE = sizeof (int64_t);
const int ORIGINAL_ID_OFFSET_IN_ID = EBLOB_ID_SIZE - sizeof (int64_t);

static inline void copy_to_eblob_id (uint8_t *eblob_id, uint8_t *dnet_id)
{
	memcpy(eblob_id, dnet_id + ORIGINAL_ID_OFFSET_IN_ID, ORIGINAL_ID_SIZE);
	memcpy(eblob_id + ORIGINAL_ID_SIZE, dnet_id, ORIGINAL_ID_OFFSET_IN_ID);
}

static inline void copy_to_dnet_id (uint8_t *dnet_id, uint8_t *eblob_id)
{
	memcpy(dnet_id, eblob_id + ORIGINAL_ID_SIZE, ORIGINAL_ID_OFFSET_IN_ID);
	memcpy(dnet_id + ORIGINAL_ID_OFFSET_IN_ID, eblob_id, ORIGINAL_ID_SIZE);
}

#ifdef __cplusplus
}
#endif

#endif /* __ORIGINAL_ID_HELPERS_H */
