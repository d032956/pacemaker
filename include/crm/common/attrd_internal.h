/*
 * Copyright 2004-2020 the Pacemaker project contributors
 *
 * The version control history for this file may have further details.
 *
 * This source code is licensed under the GNU Lesser General Public License
 * version 2.1 or later (LGPLv2.1+) WITHOUT ANY WARRANTY.
 */

#ifndef CRM_ATTRD__H
#  define CRM_ATTRD__H

#ifdef __cplusplus
extern "C" {
#endif

#  include <crm/common/ipc.h>

// Options for clients to use with functions below
enum pcmk__node_attr_opts {
    pcmk__node_attr_none    = 0,
    pcmk__node_attr_remote  = (1 << 0),
    pcmk__node_attr_private = (1 << 1),
};

int pcmk__node_attr_request(crm_ipc_t * ipc, char command, const char *host,
                            const char *name, const char *value,
                            const char *section, const char *set,
                            const char *dampen, const char *user_name,
                            int options);

int pcmk__node_attr_request_clear(crm_ipc_t *ipc, const char *host,
                                  const char *resource, const char *operation,
                                  const char *interval_spec,
                                  const char *user_name, int options);

const char *pcmk__node_attr_target(const char *name);

#ifdef __cplusplus
}
#endif

#endif
