VG_OPT	=	--suppressions=ignoreliberror
VG_OPT	+=	--leak-check=full
VG_OPT	+=	--show-leak-kinds=all
VG_OPT	+=	--track-fds=yes
VG_OPT	+=	--trace-children=yes
# VG_OPT	+=	--log-file=vg.log

valgrind:
#	${MAKE} ${NAME} DEBUG=1
	$@ ${VG_OPT} ./${NAME}

.PHONY: valgrind
