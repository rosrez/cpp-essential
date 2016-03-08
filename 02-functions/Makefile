
# project.mak defines the default 'all' target that reliess on TARGETNAMES
TARGETNAMES = \
	by-val-ref \
	func-pointer \
	overload-func \
	overload-op \
	variadic \

-include ../project.mak

$(BLDDIR)/by-val-ref: by-val-ref.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BLDDIR)/func-pointer: func-pointer.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BLDDIR)/overload-func: overload-func.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BLDDIR)/overload-op: overload-op.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BLDDIR)/variadic: variadic.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

