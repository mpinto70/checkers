
default: subdirs

SUBDIRS = src tst mck

subdirs: $(SUBDIRS)

$(MAKECMDGOALS): environment $(SUBDIRS)

tst: src mck

include project.mk

