  /********************************************************************\
  * Axel -- A lighter download accelerator for Linux and other Unices. *
  *                                                                    *
  * Copyright 2001 Wilmer van der Gaast                                *
  \********************************************************************/

/* HTTP control include file						*/

/*
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License with
  the Debian GNU/Linux distribution in file /usr/doc/copyright/GPL;
  if not, write to the Free Software Foundation, Inc., 59 Temple Place,
  Suite 330, Boston, MA  02111-1307  USA
*/

#include <openssl/ssl.h>

typedef struct
{
	char host[MAX_STRING];
	char auth[MAX_STRING];
	char request[MAX_QUERY];
	char headers[MAX_QUERY];
	int proto;			/* FTP through HTTP proxies	*/
	int proxy;
	long long int firstbyte;
	long long int lastbyte;
	int status;
	int fd;
    SSL *ssl;
    SSL_CTX *ctx;
	char *local_if;
} https_t;

int https_connect( https_t *conn, int proto, char *proxy, char *host, int port, char *user, char *pass );
void https_disconnect( https_t *conn );
void https_get( https_t *conn, char *lurl );
void https_addheader( https_t *conn, char *format, ... );
int https_exec( https_t *conn );
char *https_header( https_t *conn, char *header );
long long int https_size( https_t *conn );
void https_encode( char *s );
void https_decode( char *s );
