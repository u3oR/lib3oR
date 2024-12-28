
TARGET = test_template

BUILD_DIR = build

CC  ?= gcc
SZ  ?= size

L3oR := ../../

C_SOURCES := 
C_SOURCES += main.c 
C_SOURCES += 
# e.g.
# C_SOURCES += $(L3oR)/src/DataStruct/L3oR_BitMap.c

C_INCLUDES := 
C_INCLUDES += -I$(L3oR)/include

CFLAGS := 
CFLAGS += -Wall 
CFLAGS += -Og 
CFLAGS += -g 
CFLAGS += $(C_INCLUDES)

LDFLAGS := 
LDFLAGS +=

all: $(BUILD_DIR)/$(TARGET)

#######################################
# build the application
#######################################
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))

vpath %.c $(sort $(dir $(C_SOURCES)))

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR) 
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/$(TARGET): $(OBJECTS) Makefile
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	
$(BUILD_DIR):
	mkdir -p $@

clean:
	-rm -fR $(BUILD_DIR)

# *** EOF ***
