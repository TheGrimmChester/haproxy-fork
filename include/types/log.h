/*
  include/types/log.h
  This file contains definitions of log-related structures and macros.

  Copyright (C) 2000-2006 Willy Tarreau - w@1wt.eu
  
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation, version 2.1
  exclusively.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _TYPES_LOG_H
#define _TYPES_LOG_H

#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <common/config.h>

#define MAX_SYSLOG_LEN          1024
#define NB_LOG_FACILITIES       24
#define NB_LOG_LEVELS           8
#define SYSLOG_PORT             514
#define UNIQUEID_LEN            128


/* lists of fields that can be logged */
enum {

	LOG_FMT_TEXT = 0, /* raw text */

	LOG_FMT_SEPARATOR, /* separator replaced by one space */
	LOG_FMT_VARIABLE,

	/* information fields */
	LOG_FMT_GLOBAL,
	LOG_FMT_CLIENTIP,
	LOG_FMT_CLIENTPORT,
	LOG_FMT_BACKENDIP,
	LOG_FMT_BACKENDPORT,
	LOG_FMT_FRONTENDIP,
	LOG_FMT_FRONTENDPORT,
	LOG_FMT_SERVERPORT,
	LOG_FMT_SERVERIP,
	LOG_FMT_COUNTER,
	LOG_FMT_PID,
	LOG_FMT_DATE,
	LOG_FMT_DATEGMT,
	LOG_FMT_TS,
	LOG_FMT_MS,
	LOG_FMT_FRONTEND,
	LOG_FMT_BACKEND,
	LOG_FMT_SERVER,
	LOG_FMT_BYTES,
	LOG_FMT_T,
	LOG_FMT_TQ,
	LOG_FMT_TW,
	LOG_FMT_TC,
	LOG_FMT_TR,
	LOG_FMT_TT,
	LOG_FMT_STATUS,
	LOG_FMT_CCLIENT,
	LOG_FMT_CSERVER,
	LOG_FMT_TERMSTATE,
	LOG_FMT_TERMSTATE_CK,
	LOG_FMT_CONN,
	LOG_FMT_ACTCONN,
	LOG_FMT_FECONN,
	LOG_FMT_BECONN,
	LOG_FMT_SRVCONN,
	LOG_FMT_RETRIES,
	LOG_FMT_QUEUES,
	LOG_FMT_SRVQUEUE,
	LOG_FMT_BCKQUEUE,
	LOG_FMT_HDRREQUEST,
	LOG_FMT_HDRRESPONS,
	LOG_FMT_HDRREQUESTLIST,
	LOG_FMT_HDRRESPONSLIST,
	LOG_FMT_REQ,
	LOG_FMT_HOSTNAME,
	LOG_FMT_UNIQUEID,
};

/* enum for parse_logformat */
enum {
	LF_TEXT = 0,
	LF_SEPARATOR,
	LF_VAR, // after %

	LF_STARTVAR,   // %
	LF_STARG, // { and within { }
	LF_EDARG, // end arg }
};


struct logformat_node {
	struct list list;
	int type;
	int options;
	char *arg;
};

#define LOG_OPT_HEXA		0x00000001
#define LOG_OPT_MANDATORY	0x00000002
#define LOG_OPT_QUOTE		0x00000004



/* fields that need to be logged. They appear as flags in session->logs.logwait */
#define LW_INIT		1	/* date */
#define LW_CLIP		2	/* CLient IP */
#define LW_SVIP		4	/* SerVer IP */
#define LW_SVID		8	/* server ID */
#define	LW_REQ		16	/* http REQuest */
#define LW_RESP		32	/* http RESPonse */
#define LW_BYTES	256	/* bytes read from server */
#define LW_COOKIE	512	/* captured cookie */
#define LW_REQHDR	1024	/* request header(s) */
#define LW_RSPHDR	2048	/* response header(s) */
#define LW_BCKIP	4096	/* backend IP */
#define LW_FRTIP 	8192	/* frontend IP */

struct logsrv {
	struct list list;
	struct sockaddr_storage addr;
	int facility;
	int level;
	int minlvl;
};

#endif /* _TYPES_LOG_H */

/*
 * Local variables:
 *  c-indent-level: 8
 *  c-basic-offset: 8
 * End:
 */
