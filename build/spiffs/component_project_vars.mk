# Automatically generated build file. Do not edit.
COMPONENT_INCLUDES += $(PROJECT_PATH)/3rd-party/esp-idf/components/spiffs/include
COMPONENT_LDFLAGS += -L$(BUILD_DIR_BASE)/spiffs -lspiffs
COMPONENT_LINKER_DEPS += 
COMPONENT_SUBMODULES += $(PROJECT_PATH)/3rd-party/esp-idf/components/spiffs/spiffs
COMPONENT_LIBRARIES += spiffs
spiffs-build: 
