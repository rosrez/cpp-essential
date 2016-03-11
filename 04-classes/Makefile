
# project.mak defines the default 'all' target that reliess on TARGETNAMES
TARGETNAMES = \
	class \
	struct \
	const-safe \
	constructor \
	implicit-explicit \
	namespace \
	this \
	overload-op \
	overload-func \
	overload-conv \
	newdelete \
	exceptions \
	functor \

-include ../project.mak

$(BLDDIR)/class: class.o
	$(LINK.cpp) $^ -o $@

$(BLDDIR)/struct: struct.o
	$(LINK.cpp) $^ -o $@

$(BLDDIR)/const-safe: const-safe.o
	$(LINK.cpp) $^ -o $@

$(BLDDIR)/constructor: constructor.o
	$(LINK.cpp) $^ -o $@

$(BLDDIR)/implicit-explicit: implicit-explicit.o
	$(LINK.cpp) $^ -o $@ 

$(BLDDIR)/namespace: namespace.o
	$(LINK.cpp) $^ -o $@ 

$(BLDDIR)/this: this.o
	$(LINK.cpp) $^ -o $@

$(BLDDIR)/overload-op: overload-op.o
	$(LINK.cpp) $^ -o $@ 

$(BLDDIR)/overload-func: overload-func.o
	$(LINK.cpp) $^ -o $@ 

$(BLDDIR)/overload-conv: overload-conv.o
	$(LINK.cpp) $^ -o $@

$(BLDDIR)/newdelete: newdelete.o
	$(LINK.cpp) $^ -o $@ 

$(BLDDIR)/exceptions: exceptions.o
	$(LINK.cpp) $^ -o $@

$(BLDDIR)/functor: functor.o
	$(LINK.cpp) $^ -o $@
