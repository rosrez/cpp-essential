
# project.mak defines the default 'all' target that reliess on TARGETNAMES
TARGETNAMES = \
	reference \
	forrange \
	cout

-include ../project.mak

$(BLDDIR)/reference: reference.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BLDDIR)/forrange: forrange.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BLDDIR)/cout: cout.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^
