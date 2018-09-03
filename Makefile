default:all

.DEFAULT:
	cd source && $(MAKE) $@

all:
	cd source && $(MAKE) $@

.PHONY:all

test:
	build/test


