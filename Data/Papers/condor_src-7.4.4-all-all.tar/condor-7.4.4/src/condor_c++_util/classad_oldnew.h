/***************************************************************
 *
 * Copyright (C) 1990-2007, Condor Team, Computer Sciences Department,
 * University of Wisconsin-Madison, WI.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License"); you
 * may not use this file except in compliance with the License.  You may
 * obtain a copy of the License at
 * 
 *    http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ***************************************************************/

#ifndef _ClassAdOldNew_H
#define _ClassAdOldNew_H
 
/*
  This file holds utility functions that rely on *new* ClassAds.
*/
#include "stream.h"

#ifndef WANT_CLASSAD_NAMESPACE
#define WANT_CLASSAD_NAMESPACE
#endif
#include "classad/classad_distribution.h"
using namespace std;
BEGIN_NAMESPACE( classad )

ClassAd* getOldClassAd( Stream *sock );
bool getOldClassAd( Stream *sock, ClassAd& ad );
bool getOldClassAdNoTypes( Stream *sock, ClassAd& ad );
bool putOldClassAd ( Stream *sock, ClassAd& ad );
bool putOldClassAdNoTypes ( Stream *sock, ClassAd& ad );
END_NAMESPACE // classad

#endif
