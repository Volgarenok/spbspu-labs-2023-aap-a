# Version 2.1

.PHONY: all labs clean
.SECONDEXPANSION:
.SECONDARY:

BOOST_LOCATION := $(shell test -f .boost_location && cat .boost_location ; true)

ifneq 'yes' '$(VERBOSE)'
hidecmd := @
endif
# The variable SILENT controls additional messages

CPPFLAGS += -Wall -Wextra -Werror -Wno-missing-field-initializers -Wold-style-cast $(if $(BOOST_LOCATION),-isystem $(BOOST_LOCATION))
CXXFLAGS += -g

system   := $(shell uname)

ifneq 'MINGW' '$(patsubst MINGW%,MINGW,$(system))'
CPPFLAGS += -std=c++14
else
CPPFLAGS += -std=gnu++14
endif

ifeq 'Darwin' '$(system)'
TIMEOUT_CMD := gtimeout
else
TIMEOUT_CMD := timeout
endif

students := $(filter-out out Makefile README.md,$(wildcard *))
labs     := $(foreach student,$(students),$(wildcard $(student)/??) $(wildcard $(student)/??.?))

student            = $(word 1,$(subst /, ,$(1)))

lab_test_sources   = $(wildcard $(1)/test-*.cpp)
lab_sources        = $(filter-out $(1)/test-%,$(wildcard $(1)/*.cpp))
lab_headers        = $(wildcard $(1)/*.h) $(wildcard $(1)/*.hpp) $(wildcard $(1)/*.hxx)
lab_common_sources = $(if $(wildcard $(1)/common),$(filter-out $(1)/common/test-%.cpp,$(wildcard $(1)/common/*.cpp)))
lab_common_tests   = $(if $(wildcard $(1)/common),$(wildcard $(1)/common/test-*.cpp))
lab_common_headers = $(if $(wildcard $(1)/common),$(wildcard $(1)/common/*.h) $(wildcard $(1)/common/*.hpp) $(wildcard $(1)/common/*.hxx))

lab_objects        = $(patsubst %.cpp,out/%.o,$(call lab_sources,$(1)) $(call lab_common_sources,$(call student,$(1))))
lab_test_objects   = $(patsubst %.cpp,out/%.o,$(call lab_test_sources,$(1)) $(call lab_common_tests,$(call student,$(1))))
lab_header_checks  = $(addprefix out/,$(addsuffix .header,$(call lab_headers,$(1)) $(call lab_common_headers,$(call student,$(1)))))

objects           := $(sort $(foreach lab,$(labs),$(call lab_objects,$(lab))))
test_objects      := $(sort $(foreach lab,$(labs),$(call lab_test_objects,$(lab))))
header_checks     := $(sort $(foreach lab,$(labs),$(call lab_header_checks,$(lab))))

common_include     = $(if $(wildcard $(call student,$(1))/common),-I$(call student,$(1))/common -I$(call student,$(1))/common/include)

all: $(addprefix build-,$(labs))

labs:
	@echo $(labs)

$(addprefix run-,$(labs)): run-%: out/%/lab
	@$(FAULT_INJECTION_CONFIG) $(if $(TIMEOUT),$(TIMEOUT_CMD) --signal=KILL $(TIMEOUT)s )$(if $(VALGRIND),valgrind $(VALGRIND) )$< $(ARGS)

clean:
	rm -rf out

$(addprefix build-,$(labs)): build-%: out/%/lab

$(addprefix test-,$(labs)): test-%: out/%/test-lab
	$(if $(SILENT),,@echo [TEST] $(patsubst out/%/test-lab,%,$<))
	$(hidecmd)$(if $(TIMEOUT),$(TIMEOUT_CMD) --signal=KILL $(TIMEOUT)s )$(if $(VALGRIND),valgrind $(VALGRIND) )$< $(TEST_ARGS)

out/%/lab: $$(call lab_objects,%) $$(call lab_header_checks,%) | $$(@D)/.dir
	$(if $(SILENT),,@echo [LINK] $(patsubst out/%/lab,%,$@))
	$(hidecmd)$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -o $@ $(filter-out %.header,$^)

out/%/test-lab: $$(call lab_test_objects,%) $$(call lab_objects,%) | $$(@D)/.dir
	$(if $(SILENT),,@echo [LINK] $(patsubst out/%/test-lab,%,$@))
	$(hidecmd)$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -o $@ $(filter-out %/main.o,$^)

$(test_objects): out/%.o: %.cpp | $$(@D)/.dir
	$(if $(SILENT),,@echo [C++ ] $<)
	$(hidecmd)$(CXX) $(CPPFLAGS) $(CXXFLAGS) -Wno-old-style-cast -Wno-unused-parameter -MMD -MP -c $(call common_include,$<) -o $@ $<

$(objects): out/%.o: %.cpp | $$(@D)/.dir
	$(if $(SILENT),,@echo [C++ ] $<)
	$(hidecmd)$(CXX) $(CPPFLAGS) $(CXXFLAGS) -MMD -MP -c $(call common_include,$<) -o $@ $<

$(header_checks): out/%.header: % | $$(@D)/.dir
	$(if $(SILENT),,@echo [HDR ] $<)
	$(hidecmd)$(CXX) $(CPPFLAGS) $(CXXFLAGS) -Wno-unused-const-variable -c $(call common_include,$<) -fsyntax-only $<
	@touch $@

%/.dir:
	@mkdir -p $(@D) && touch $@

include $(wildcard $(patsubst %.o,%.d,$(objects) $(test_objects)))
