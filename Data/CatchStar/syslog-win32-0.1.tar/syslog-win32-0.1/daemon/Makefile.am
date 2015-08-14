if OS_WIN32

if DEBUG
AM_CFLAGS = -g
endif

if RELOCATABLE
AM_CPPFLAGS = -DSYSLOG_CONF_DIR=\".$(sysconfdir)\"
else
AM_CPPFLAGS = -DSYSLOG_CONF_DIR=\"$(sysconfdir)\"
endif

AM_CPPFLAGS += -I. -I../include $(GLIB_CFLAGS)

bin_PROGRAMS = syslogd
syslogd_SOURCES = conf.c fifo.c listener.c logrotate.c main.c names.c \
                  pathnames.c purger.c syslogd.c writer.c syslogd.h
syslogd_LDADD = -lws2_32 $(GLIB_LIBS)

endif
