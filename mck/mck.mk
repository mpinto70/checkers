
VPATH = .:$(MCKBIN)

MOVE_TO_BINDIR=1

DESTLIBDIR=$(MCKBIN)

LIB_BASE_NAME = lib$(subst /,,$(subst $(CHECKERS_ROOT),,$(shell pwd)))
LIBA=$(LIB_BASE_NAME).a
LIBSO=$(LIB_BASE_NAME).so

include $(CHECKERS_ROOT)/project.mk

CXXTEST_INC=$(CXXTEST_ROOT)

CFLAGS +=	-I$(CXXTEST_INC) \
			-DCHECKERS_ROOT="\"$(CHECKERS_ROOT)\"" \
			-DCXXTEST_HAVE_STD \
			-DCXXTEST_HAVE_EH \

libsotarget: directory_message $(LIBSO) $(SUBDIRS)

libatarget: directory_message $(LIBA) $(SUBDIRS)

libbothtarget: directory_message $(LIBA) $(LIBSO) $(SUBDIRS)

local: $(LIBA) $(LIBSO)

ifneq ($(LIBA),)
OTHER_DISTCLEAN+= $(MCKBIN)/$(LIBA)
endif
ifneq ($(LIBSO),)
OTHER_DISTCLEAN+= $(MCKBIN)/$(LIBSO)
endif

run_local: run

run:
	$(ECHO) -n ""

