## Makefile -- 
##  Copyright (c) Sriram Rao
##                This source is provided as is without any express or
##                written warranty.  Permission to use, copy, modify, and 
##                distribute this software for any purpose without fee is
##                hereby granted, provided that this entire notice is 
##                included in all copies of any software which is or includes
##                a copy or modification of this software and in all copies
##                of the supporting documentation for such software.
##                All Rights Reserved.
## $Locker:  $
## $Log: Makefile,v $
## Revision 1.1.1.1  2001/02/12 00:00:16  ravshank
## Start of Spring 2001
##
## Revision 1.2  2000/06/27 20:15:50  phoebe
## Cleaned up Makefiles. Made DebugTrace into a proper class. Fixed the communication tracking part of Stats.cc.
##
## Revision 1.1.1.1  2000/03/06 20:00:22  phoebe
## Sriram's original code with no modifications
##
## $Id: Makefile,v 1.1.1.1 2001/02/12 00:00:16 ravshank Exp $
## Author          : Sriram Rao
## Created On      : Thu Apr 29 23:30:49 1999
## Last Modified By: Sriram Rao
## Last Modified On: Sun Aug 15 16:15:19 1999
## Update Count    : 37
## Status          : Unknown, Use with caution!
## PURPOSE
## 	|>Description of modules purpose<|

include Makefile.common

SOURCES = $(COMMON_SOURCES)

vpath %.cc ${EGIDA_SOURCE_DIR}

all: libEgida.a

libEgida.a: $(COMMON_OBJECTS)
	rm -f $@
	CC -xar -o $@ $(COMMON_OBJECTS)

$(COMMON_OBJECTS) : %.o : ${EGIDA_SOURCE_DIR}/%.cc
	$(CXX) -c $(CXXFLAGS) $(IO_STREAM_FLAG) $<

clean:
	@rm -rf *.o *~ ${EGIDA_INCLUDE_DIR}/*~ libEgida.a SunWS_cache

depend:
	@rm -f make-deps
	$(DEPEND) $(IO_STREAM_FLAG) $(SOURCES) > make-deps

include make-deps
