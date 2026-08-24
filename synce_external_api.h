/**
 * @file synce_external_api.h
 * @brief external API definition for synce4l
 * @note SPDX-FileCopyrightText: Copyright 2023 Intel Corporation
 * @note SPDX-License-Identifier: GPL-2.0+
 */
#ifndef HAVE_SYNCE_EXTERNL_API_H
#define HAVE_SYNCE_EXTERNL_API_H

#define MAX_COMMAND_SIZE		256
#define MAX_RESPONSE_SIZE		256

enum synce_manager_type {
	MSG_DEV_NAME = 1,
	MSG_SRC_NAME,
	MSG_ERR_MSG,
	MSG_GET_QL,
	MSG_GET_EXT_QL,
	MSG_SET_QL,
	MSG_SET_EXT_QL,
	MSG_END_MARKER,
	/* AMVP-3802: appended after MSG_END_MARKER rather than inserted earlier in
	 * the list, so existing clients that hardcode the numeric wire values (e.g.
	 * todmon-ptp4l's MSG_END_MARKER(8)) keep working unchanged. */
	MSG_PORT_NAME,		/* physical port name, for MSG_GET_PORT_QL */
	MSG_GET_PORT_QL,	/* per-port received QL - NOT the device's selected/winning QL (see MSG_GET_QL) */
};

struct synce_manager_tlv {
	uint16_t type;	// enum synce_manager_type
	uint16_t length;// length in bytes
	void *value;	// data of given length
};

#endif
