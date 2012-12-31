/*
 * Copyright (C) 2011, Broadcom Corporation. All Rights Reserved.
 * 
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
 * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * Fundamental constants relating to Neighbor Discovery Protocol
 *
 * $Id: bcmipv6.h 305568 2011-12-29 20:21:17Z $
 */

#ifndef _bcmipv6_h_
#define _bcmipv6_h_

#ifndef _TYPEDEFS_H_
#include <typedefs.h>
#endif

/* This marks the start of a packed structure section. */
#include <packed_section_start.h>

#define ICMPV6_HEADER_TYPE 	0x3A
#define ICMPV6_PKT_TYPE_NS	135
#define ICMPV6_PKT_TYPE_NA	136

#define ICMPV6_ND_OPT_TYPE_TARGET_MAC	2
#define ICMPV6_ND_OPT_TYPE_SRC_MAC		1

#define IPV6_VERSION 	6
#define IPV6_HOP_LIMIT 	255

#define IPV6_ADDR_NULL(a)	((a[0] | a[1] | a[2] | a[3] | a[4] | \
							 a[5] | a[6] | a[7] | a[8] | a[9] | \
							 a[10] | a[11] | a[12] | a[13] | \
							 a[14] | a[15]) == 0)

/* IPV6 address */
BWL_PRE_PACKED_STRUCT struct ipv6_addr {
		uint8		addr[16];
} BWL_POST_PACKED_STRUCT;

#ifndef IL_BIGENDIAN

/* ICMPV6 Header */
BWL_PRE_PACKED_STRUCT struct icmp6_hdr {
	uint8	icmp6_type;
	uint8	icmp6_code;
	uint16	icmp6_cksum;
	BWL_PRE_PACKED_STRUCT union {
		uint32 reserved;
		BWL_PRE_PACKED_STRUCT struct nd_advt {
			uint32	reserved1:5,
				override:1,
				solicited:1,
				router:1,
				reserved2:24;
		} BWL_POST_PACKED_STRUCT nd_advt;
	} BWL_POST_PACKED_STRUCT opt;
} BWL_POST_PACKED_STRUCT;

/* Ipv6 Header Format */
BWL_PRE_PACKED_STRUCT struct ipv6_hdr {
	uint8	priority:4,
		version:4;
	uint8	flow_lbl[3];
	uint16	payload_len;
	uint8	nexthdr;
	uint8 	hop_limit;
	struct	ipv6_addr	saddr;
	struct	ipv6_addr	daddr;
} BWL_POST_PACKED_STRUCT;

/* Neighbor Advertisement/Solicitation Packet Structure */
BWL_PRE_PACKED_STRUCT struct nd_msg {
	struct icmp6_hdr	icmph;
	struct ipv6_addr target;
} BWL_POST_PACKED_STRUCT;


/* Neighibor Solicitation/Advertisement Optional Structure */
BWL_PRE_PACKED_STRUCT struct nd_msg_opt {
	uint8 type;
	uint8 len;
	uint8 mac_addr[ETHER_ADDR_LEN];
} BWL_POST_PACKED_STRUCT;

#endif /* IL_BIGENDIAN */

/* This marks the end of a packed structure section. */
#include <packed_section_end.h>

#endif	/* !defined(_bcmipv6_h_) */