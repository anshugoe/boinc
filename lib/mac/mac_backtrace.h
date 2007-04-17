// Berkeley Open Infrastructure for Network Computing
// http://boinc.berkeley.edu
// Copyright (C) 2005 University of California
//
// This is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation;
// either version 2.1 of the License, or (at your option) any later version.
//
// This software is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU Lesser General Public License for more details.
//
// To view the GNU Lesser General Public License visit
// http://www.gnu.org/copyleft/lesser.html
// or write to the Free Software Foundation, Inc.,
// 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
/*
 *  mac_backtrace.h
 *
 */
 
/* This is a rudimentary backtrace generator for boinc project applications.  
*
* It is adapted from Apple Developer Technical Support Sample Code 
*   MoreisBetter / MoreDebugging / MoreBacktraceTest
*  The symbols it displays are not always clean.  
*
* This code handles Mac OS X 10.3.x through 10.4.2.  It may require some 
* adjustment for future OS versions; see the discussion of _sigtramp and 
* PowerPC Signal Stack Frames below.
*
*  For useful tips on using backtrace information, see Apple Tech Note 2123:
*  http://developer.apple.com/technotes/tn2004/tn2123.html#SECNOSYMBOLS
*
*  To convert addresses to correct symbols, use the atos command-line tool:
*  atos -o path/to/executable/with/symbols address
*  Note: if address 1a23 is hex, use 0x1a23.  
*
*  To demangle mangled C++ symbols, use the c++filt command-line tool. 
*  You may need to prefix C++ symbols with an additonal underscore before 
*  passing them to c++filt (so they begin with two underscore characters).
*
*  Flags in backtrace:
*    F this frame pointer is bad
*    P this PC is bad
*    S this frame is a signal handler
*
*/
 
#ifndef _BOINC_BACKTRACE_
#define _BOINC_BACKTRACE_


#ifdef __cplusplus
extern "C" {
#endif

#include <mach/mach.h>

void PrintBacktrace(void);

#if defined(__cplusplus)
}
#endif

#endif      // _BOINC_BACKTRACE_