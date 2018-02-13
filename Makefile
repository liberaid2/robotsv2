PROJECT_NAME := esp32_robots

GENERATE_CMDS := $(shell python3 scripts/generate_cmds.py)

IDF_PATH=$(abspath 3rd-party/esp-idf)
COMPONENT_DIRS := $(IDF_PATH)/components $(abspath src) $(abspath 3rd-party/RuC/RuC) $(abspath src/cconsole/ccmds) $(abspath src/iobase) $(abspath src/util)

EXTRA_INCLUDES := -I $(abspath src/) -I $(abspath include/)
EXTRA_CFLAGS := $(EXTRA_INCLUDES)
EXTRA_CPPFLAGS := $(EXTRA_CFLAGS)

include $(IDF_PATH)/make/project.mk
