# Automatically generated build file. Do not edit.
COMPONENT_INCLUDES += $(PROJECT_PATH)/3rd-party/esp-idf/components/cxx/include
COMPONENT_LDFLAGS += -L$(BUILD_DIR_BASE)/cxx -lcxx -u __cxa_guard_dummy -u __cxx_fatal_exception
COMPONENT_LINKER_DEPS += 
COMPONENT_SUBMODULES += 
COMPONENT_LIBRARIES += cxx
component-cxx-build: 
