if OS_WIN32

if DEBUG
AM_CFLAGS = -g
endif

AM_CPPFLAGS = -I../include

bin_PROGRAMS = dropcount test

dropcount_SOURCES = dropcount.c

test_SOURCES = test.c
test_LDFLAGS = -L../client
test_LDADD = -lsyslog

endif
