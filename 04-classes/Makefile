
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
