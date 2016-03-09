
# project.mak defines the default 'all' target that reliess on TARGETNAMES
TARGETNAMES = \
	class \
	struct \
	const-safe \
	constructor \

-include ../project.mak

$(BLDDIR)/class: class.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BLDDIR)/struct: struct.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BLDDIR)/const-safe: const-safe.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BLDDIR)/constructor: constructor.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^


