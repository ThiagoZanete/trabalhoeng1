
CXX := g++
CXXFLAGS := -Wall -std=c++11 -g -Isrc
LDFLAGS := -lm
BUILD_DIR := bin

SOURCES_SRC := $(wildcard src/*.cpp)
SOURCES_TEST := $(shell find test -name '*.cpp')

# Os arquivos .o vão para o BUILD_DIR
OBJECTS_SRC := $(addprefix $(BUILD_DIR)/, $(notdir $(SOURCES_SRC:.cpp=.o)))
OBJECTS_TEST := $(addprefix $(BUILD_DIR)/, $(notdir $(SOURCES_TEST:.cpp=.o)))
OBJECTS := $(OBJECTS_SRC) $(OBJECTS_TEST)

TARGET := exe
VPATH = src:$(shell find test -type d)


.PHONY: all run clean

all: $(TARGET)


$(TARGET): $(OBJECTS) | $(BUILD_DIR)
	# O output é $(TARGET), que agora é 'exe' no diretório raiz
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $(TARGET)
	@echo "Linkagem concluída: [$(TARGET)]"

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)


run: all
	@echo "Executando..."
	./$(TARGET)


# Agora remove o diretório 'bin' E o arquivo 'exe' da raiz
clean:
	@echo "Limpando diretório [$(BUILD_DIR)] e executável [$(TARGET)]..."
	rm -rf $(BUILD_DIR)
	rm -f $(TARGET)