# ===============================
# Tools and MCU
# ===============================
CC      = avr-gcc
OBJCOPY = avr-objcopy
AR      = avr-ar

MCU     = atmega328p
F_CPU   = 16000000UL

# ===============================
# Directories
# ===============================
OUT_DIR     = out
OUT_OBJ_DIR = $(OUT_DIR)/obj
OUT_LIB_DIR = $(OUT_DIR)/lib
LIB_DIR     = avr_lib
SRC_DIR     = src
INC_DIR     = avr_lib
LF_DIR		= LF

# ===============================
# Sources
# ===============================
LIB_SRC  = $(wildcard $(LIB_DIR)/*.c)
LIB_OBJ  = $(patsubst $(LIB_DIR)/%.c,$(OUT_OBJ_DIR)/%.o,$(LIB_SRC))
LIB_NAME = libatmega328p.a

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OUT_OBJ_DIR)/%.o,$(SRC_FILES))

# ===============================
# Targets
# ===============================
TARGET = load.elf
HEX    = load.hex

# ===============================
# Compiler / Linker flags
# ===============================
CFLAGS  = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -I$(INC_DIR)
LDFLAGS = -mmcu=$(MCU) -L$(OUT_LIB_DIR) -latmega328p

# ===============================
# Default target
# ===============================
all: $(HEX)

# ===============================
# Build main program
# ===============================
$(TARGET): $(OBJ_FILES) $(OUT_LIB_DIR)/$(LIB_NAME)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LDFLAGS) -o $(LF_DIR)/$@

# Convert ELF to HEX
$(HEX): $(TARGET)
	$(OBJCOPY) -O ihex $(LF_DIR)/$< $(LF_DIR)/$@

# ===============================
# Build static library
# ===============================
$(OUT_LIB_DIR)/$(LIB_NAME): $(LIB_OBJ) | $(OUT_LIB_DIR)
	$(AR) rcs $@ $^

# Compile library object files
$(OUT_OBJ_DIR)/%.o: $(LIB_DIR)/%.c | $(OUT_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile source object files
$(OUT_OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OUT_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# ===============================
# Create directories if missing
# ===============================
$(OUT_OBJ_DIR):
	mkdir -p $@

$(OUT_LIB_DIR):
	mkdir -p $@

# ===============================
# Clean build artifacts
# ===============================
clean:
	rm -rf $(OUT_OBJ_DIR)/*.o $(OUT_LIB_DIR)/$(LIB_NAME) $(TARGET) $(HEX)
