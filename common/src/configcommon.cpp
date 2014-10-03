/* ****************************************************************************

 * eID Middleware Project.
 * Copyright (C) 2008-2011 FedICT.
 *
 * This is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License version
 * 3.0 as published by the Free Software Foundation.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this software; if not, see
 * http://www.gnu.org/licenses/.

**************************************************************************** */
#include "configuration.h"

// Common declaration to File and Registry Config
namespace eIDMW
{ 

//GENERAL
  const struct CConfig::Param_Str CConfig::EIDMW_CONFIG_PARAM_GENERAL_INSTALLDIR 	=	{EIDMW_CNF_SECTION_GENERAL,	EIDMW_CNF_GENERAL_INSTALLDIR,   L"$home"};
  const struct CConfig::Param_Str CConfig::EIDMW_CONFIG_PARAM_GENERAL_INSTALL_PRO_DIR =	{EIDMW_CNF_SECTION_GENERAL,	EIDMW_CNF_GENERAL_INSTALL_PRO_DIR,   L"$home"};
  const struct CConfig::Param_Str CConfig::EIDMW_CONFIG_PARAM_GENERAL_INSTALL_SDK_DIR =	{EIDMW_CNF_SECTION_GENERAL,	EIDMW_CNF_GENERAL_INSTALL_SDK_DIR,   L"$home"};
  const struct CConfig::Param_Str CConfig::EIDMW_CONFIG_PARAM_GENERAL_CACHEDIR 		=	{EIDMW_CNF_SECTION_GENERAL,	EIDMW_CNF_GENERAL_CACHEDIR,     L"$home" WDIRSEP L".eidmwcache"};
  const struct CConfig::Param_Str CConfig::EIDMW_CONFIG_PARAM_GENERAL_LANGUAGE	 	=	{EIDMW_CNF_SECTION_GENERAL,	EIDMW_CNF_GENERAL_LANGUAGE,		L"en"};
  const struct CConfig::Param_Num CConfig::EIDMW_CONFIG_PARAM_GENERAL_CARDTXDELAY 	=	{EIDMW_CNF_SECTION_GENERAL,	EIDMW_CNF_GENERAL_CARDTXDELAY,	3};
  const struct CConfig::Param_Num CConfig::EIDMW_CONFIG_PARAM_GENERAL_CARDCONNDELAY =	{EIDMW_CNF_SECTION_GENERAL,	EIDMW_CNF_GENERAL_CARDCONNDELAY,0};
  const struct CConfig::Param_Num CConfig::EIDMW_CONFIG_PARAM_GENERAL_BUILDNBR		=	{EIDMW_CNF_SECTION_GENERAL,	EIDMW_CNF_GENERAL_BUILDNBR,0};

//LOGGING
  const struct CConfig::Param_Str CConfig::EIDMW_CONFIG_PARAM_LOGGING_DIRNAME 		=	{EIDMW_CNF_SECTION_LOGGING,	EIDMW_CNF_LOGGING_DIRNAME,      L"$home"};
  const struct CConfig::Param_Str CConfig::EIDMW_CONFIG_PARAM_LOGGING_PREFIX	 	=	{EIDMW_CNF_SECTION_LOGGING,	EIDMW_CNF_LOGGING_PREFIX,		L".BEID"};
  const struct CConfig::Param_Num CConfig::EIDMW_CONFIG_PARAM_LOGGING_FILENUMBER	=	{EIDMW_CNF_SECTION_LOGGING,	EIDMW_CNF_LOGGING_FILENUMBER,	2};
  const struct CConfig::Param_Num CConfig::EIDMW_CONFIG_PARAM_LOGGING_FILESIZE  	=	{EIDMW_CNF_SECTION_LOGGING,	EIDMW_CNF_LOGGING_FILESIZE,		100000};
  const struct CConfig::Param_Str CConfig::EIDMW_CONFIG_PARAM_LOGGING_LEVEL  		=	{EIDMW_CNF_SECTION_LOGGING,	EIDMW_CNF_LOGGING_LEVEL,        L"error"};
  const struct CConfig::Param_Num CConfig::EIDMW_CONFIG_PARAM_LOGGING_GROUP  		=	{EIDMW_CNF_SECTION_LOGGING,	EIDMW_CNF_LOGGING_GROUP,        0};

//CRL
  const struct CConfig::Param_Num CConfig::EIDMW_CONFIG_PARAM_CRL_SERVDOWNLOADNR	=	{ EIDMW_CNF_SECTION_CRL,	EIDMW_CNF_CRL_SERVDOWNLOADNR,	3};
  const struct CConfig::Param_Num CConfig::EIDMW_CONFIG_PARAM_CRL_TIMEOUT			=	{ EIDMW_CNF_SECTION_CRL,	EIDMW_CNF_CRL_TIMEOUT,			300};
  const struct CConfig::Param_Str CConfig::EIDMW_CONFIG_PARAM_CRL_CACHEDIR			=	{ EIDMW_CNF_SECTION_CRL,	EIDMW_CNF_CRL_CACHEDIR,			L"$common" WDIRSEP L"crl"};
  const struct CConfig::Param_Str CConfig::EIDMW_CONFIG_PARAM_CRL_CACHEFILE			=	{ EIDMW_CNF_SECTION_CRL,	EIDMW_CNF_CRL_CACHEFILE,		L".cache.cdc"};
  const struct CConfig::Param_Str CConfig::EIDMW_CONFIG_PARAM_CRL_LOCKFILE			=	{ EIDMW_CNF_SECTION_CRL,	EIDMW_CNF_CRL_LOCKFILE,			L".crllock.flg"};

//CERTIFICATE VALIDATION
  const struct CConfig::Param_Num CConfig::EIDMW_CONFIG_PARAM_CERTVALID_ALLOWTESTC 	=	{EIDMW_CNF_SECTION_CERTVALID, EIDMW_CNF_CERTVALID_ALLOWTESTC,	0};
  const struct CConfig::Param_Num CConfig::EIDMW_CONFIG_PARAM_CERTVALID_CRL			=	{EIDMW_CNF_SECTION_CERTVALID, EIDMW_CNF_CERTVALID_CRL,			0};
  const struct CConfig::Param_Num CConfig::EIDMW_CONFIG_PARAM_CERTVALID_OCSP 		=	{EIDMW_CNF_SECTION_CERTVALID, EIDMW_CNF_CERTVALID_OCSP,			0};

//CERTIFICATE CACHE
  const struct CConfig::Param_Str CConfig::EIDMW_CONFIG_PARAM_CERTCACHE_CACHEFILE  	=	{EIDMW_CNF_SECTION_CERTCACHE, EIDMW_CNF_CERTCACHE_CACHEFILE,	L"$common" WDIRSEP L".cache.csc"};
  const struct CConfig::Param_Num CConfig::EIDMW_CONFIG_PARAM_CERTCACHE_LINENUMB  	=	{EIDMW_CNF_SECTION_CERTCACHE, EIDMW_CNF_CERTCACHE_LINENUMB,		25};
  const struct CConfig::Param_Num CConfig::EIDMW_CONFIG_PARAM_CERTCACHE_VALIDITY  	=	{EIDMW_CNF_SECTION_CERTCACHE, EIDMW_CNF_CERTCACHE_VALIDITY,		15*60};
  const struct CConfig::Param_Num CConfig::EIDMW_CONFIG_PARAM_CERTCACHE_WAITDELAY  	=	{EIDMW_CNF_SECTION_CERTCACHE, EIDMW_CNF_CERTCACHE_WAITDELAY,	2*60};

//PROXY
  const struct CConfig::Param_Str CConfig::EIDMW_CONFIG_PARAM_PROXY_HOST  			=	{EIDMW_CNF_SECTION_PROXY,	EIDMW_CNF_PROXY_HOST,				L""};
  const struct CConfig::Param_Num CConfig::EIDMW_CONFIG_PARAM_PROXY_PORT  			=	{EIDMW_CNF_SECTION_PROXY,	EIDMW_CNF_PROXY_PORT,				0};
  const struct CConfig::Param_Str CConfig::EIDMW_CONFIG_PARAM_PROXY_PACFILE  		=	{EIDMW_CNF_SECTION_PROXY,	EIDMW_CNF_PROXY_PACFILE,			L""};
  const struct CConfig::Param_Num CConfig::EIDMW_CONFIG_PARAM_PROXY_CONNECT_TIMEOUT	=	{EIDMW_CNF_SECTION_PROXY,	EIDMW_CNF_PROXY_CONNECT_TIMEOUT,	5};

//SECURITY
  const struct CConfig::Param_Num CConfig::EIDMW_CONFIG_PARAM_SECURITY_SINGLESIGNON	=	{EIDMW_CNF_SECTION_SECURITY, EIDMW_CNF_SECURITY_SINGLESIGNON,	1};

//GUI
  const struct CConfig::Param_Num CConfig::EIDMW_CONFIG_PARAM_GUITOOL_STARTWIN		=	{EIDMW_CNF_SECTION_GUITOOL, EIDMW_CNF_GUITOOL_STARTWIN,			0};
#ifdef __APPLE__
  const struct CConfig::Param_Num CConfig::EIDMW_CONFIG_PARAM_GUITOOL_STARTMINI		=	{EIDMW_CNF_SECTION_GUITOOL, EIDMW_CNF_GUITOOL_STARTMINI,		0};
#else
  const struct CConfig::Param_Num CConfig::EIDMW_CONFIG_PARAM_GUITOOL_STARTMINI		=	{EIDMW_CNF_SECTION_GUITOOL, EIDMW_CNF_GUITOOL_STARTMINI,		1};
#endif
  const struct CConfig::Param_Num CConfig::EIDMW_CONFIG_PARAM_GUITOOL_SHOWPIC		=	{EIDMW_CNF_SECTION_GUITOOL, EIDMW_CNF_GUITOOL_SHOWPIC,			0};
  const struct CConfig::Param_Num CConfig::EIDMW_CONFIG_PARAM_GUITOOL_SHOWNOTIFICATION	=	{EIDMW_CNF_SECTION_GUITOOL, EIDMW_CNF_GUITOOL_SHOWNOTIFICATION,			1};
  const struct CConfig::Param_Num CConfig::EIDMW_CONFIG_PARAM_GUITOOL_SHOWTBAR		=	{EIDMW_CNF_SECTION_GUITOOL, EIDMW_CNF_GUITOOL_SHOWTBAR,			1};
  const struct CConfig::Param_Num CConfig::EIDMW_CONFIG_PARAM_GUITOOL_VIRTUALKBD	=	{EIDMW_CNF_SECTION_GUITOOL, EIDMW_CNF_GUITOOL_VIRTUALKBD,		0};
  const struct CConfig::Param_Num CConfig::EIDMW_CONFIG_PARAM_GUITOOL_AUTOCARDREAD	=	{EIDMW_CNF_SECTION_GUITOOL, EIDMW_CNF_GUITOOL_AUTOCARDREAD,		0};
  const struct CConfig::Param_Num CConfig::EIDMW_CONFIG_PARAM_GUITOOL_CARDREADNUMB	=	{EIDMW_CNF_SECTION_GUITOOL, EIDMW_CNF_GUITOOL_CARDREADNUMB,		-1};	
  const struct CConfig::Param_Num CConfig::EIDMW_CONFIG_PARAM_GUITOOL_REGCERTIF		=	{EIDMW_CNF_SECTION_GUITOOL, EIDMW_CNF_GUITOOL_REGCERTIF,		1};
  const struct CConfig::Param_Num CConfig::EIDMW_CONFIG_PARAM_GUITOOL_REMOVECERTIF	=	{EIDMW_CNF_SECTION_GUITOOL, EIDMW_CNF_GUITOOL_REMOVECERTIF,		0};
  const struct CConfig::Param_Str CConfig::EIDMW_CONFIG_PARAM_GUITOOL_FILESAVE		=   {EIDMW_CNF_SECTION_GUITOOL, EIDMW_CNF_GUITOOL_FILESAVE,			L""};

//XSIGN
  const struct CConfig::Param_Str CConfig::EIDMW_CONFIG_PARAM_XSIGN_TSAURL  		=	{EIDMW_CNF_SECTION_XSIGN,	EIDMW_CNF_XSIGN_TSAURL,		L"http://tsa.belgium.be/connect"};
  const struct CConfig::Param_Num CConfig::EIDMW_CONFIG_PARAM_XSIGN_ONLINE  		=	{EIDMW_CNF_SECTION_XSIGN,	EIDMW_CNF_XSIGN_ONLINE,		1};
  const struct CConfig::Param_Str CConfig::EIDMW_CONFIG_PARAM_XSIGN_WORKINGDIR 		=	{EIDMW_CNF_SECTION_XSIGN,	EIDMW_CNF_XSIGN_WORKINGDIR,	L""};
  const struct CConfig::Param_Num CConfig::EIDMW_CONFIG_PARAM_XSIGN_TIMEOUT 		=	{EIDMW_CNF_SECTION_XSIGN,	EIDMW_CNF_XSIGN_TIMEOUT,	30};

//MESSAGES
  const struct CConfig::Param_Num CConfig::EIDMW_CONFIG_PARAM_MESSAGES_SHOWSDK35WARN =	{EIDMW_CNF_SECTION_MESSAGES,	EIDMW_CNF_MESSAGES_SHOWSDK35WARN,		1};

} // namespace eidMW