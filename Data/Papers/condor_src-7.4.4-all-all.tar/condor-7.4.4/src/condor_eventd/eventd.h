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


#if !defined(__EVENTD_H)
#define __EVENTD_H

#include "scheduled_event.h"

class EventDaemon : public Service {
public:
	EventDaemon();
	~EventDaemon();
	int Config();
	int Timeout();
private:
	ScheduledEvent *NewEvent(const char name[], const char record[]);
	int	EventInterval;
	int MaxEventPreparation;
	int TimeoutTid;
	ScheduledEvent **EventList;
	int NumEvents;
};

extern EventDaemon *EventD;

#endif
