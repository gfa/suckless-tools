# ssid - simple setsid
#   (C)opyright MMVI Anselm R. Garbe

include config.mk

SRC = ssid.c
OBJ = ${SRC:.c=.o}

all: options ssid

options:
	@echo ssid build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"
	@echo "LD       = ${LD}"

.c.o:
	@echo CC $<
	@${CC} -c ${CFLAGS} $<

${OBJ}: config.mk

ssid: ${OBJ}
	@echo LD $@
	@${LD} -o $@ ${OBJ} ${LDFLAGS}
	@strip $@

clean:
	@echo cleaning
	@rm -f ssid ${OBJ} ssid-${VERSION}.tar.gz

dist: clean
	@echo creating dist tarball
	@mkdir -p ssid-${VERSION}
	@cp -R LICENSE Makefile README config.mk ${SRC} ssid-${VERSION}
	@tar -cf ssid-${VERSION}.tar ssid-${VERSION}
	@gzip ssid-${VERSION}.tar
	@rm -rf ssid-${VERSION}

install: all
	@echo installing executable file to ${DESTDIR}${PREFIX}/bin
	@mkdir -p ${DESTDIR}${PREFIX}/bin
	@cp -f ssid ${DESTDIR}${PREFIX}/bin
	@chmod 755 ${DESTDIR}${PREFIX}/bin/ssid

uninstall:
	@echo removing executable file from ${DESTDIR}${PREFIX}/bin
	@rm -f ${DESTDIR}${PREFIX}/bin/ssid

.PHONY: all options clean dist install uninstall
