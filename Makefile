TARGET = main
UNITTEST = unittest_all
CROW = crow

CC = g++
CXXFLAGS = -std=c++11 -Wno-deprecated

OUT_DIR = ./bin
LIB_DIR = ./lib

SUB_DIR = $(filter-out lib bin, $(patsubst %/., %, $(wildcard */.)))
# SUB_DIR_INCS = $(wildcard $(foreach dir, $(SUB_DIR), $(dir)/*.hpp))
# SUB_DIR_SRCS = $(wildcard $(foreach dir, $(SUB_DIR), $(dir)/*.cpp))
INCS = $(wildcard *.hpp $(foreach f, $(SUB_DIR), $(f)/*.hpp)) # $(wildcard *.hpp param/*.hpp) = param/param.hpp
SRCS = $(wildcard *.cpp $(foreach f, $(SUB_DIR), $(f)/*.cpp))

INCS_DIR = $(addprefix -I, $(SUB_DIR))
CROW_INCS = -I/Users/user/Documents/search-env/package/crow-1.0/include
UNITTEST_INCS = -I/opt/homebrew/Cellar/boost/1.81.0_1/include
UNITTEST_LIBS = -L/opt/homebrew/Cellar/boost/1.81.0_1/lib
UNITTEST_LIBS_NAME = -lboost_unit_test_framework

NOTDIR_SRC = $(notdir $(SRCS))
NOTDIR_SRC_FOR_TARGET = $(filter-out $(UNITTEST).cpp $(CROW).cpp %_unittest.cpp, $(NOTDIR_SRC))
NOTDIR_SRC_FOR_UNITTEST = $(filter-out $(TARGET).cpp $(CROW).cpp, $(NOTDIR_SRC))
NOTDIR_SRC_FOR_CROW = $(filter-out $(TARGET).cpp $(UNITTEST).cpp %_unittest.cpp, $(NOTDIR_SRC))

OBJS = $(addprefix $(LIB_DIR)/, $(patsubst %.cpp, %.o, $(NOTDIR_SRC)))
OBJS_FOR_TARGET = $(addprefix $(LIB_DIR)/, $(patsubst %.cpp, %.o, $(NOTDIR_SRC_FOR_TARGET)))
OBJS_FOR_UNITTEST = $(addprefix $(LIB_DIR)/, $(patsubst %.cpp, %.o, $(NOTDIR_SRC_FOR_UNITTEST)))
OBJS_FOR_CROW = $(addprefix $(LIB_DIR)/, $(patsubst %.cpp, %.o, $(NOTDIR_SRC_FOR_CROW)))

vpath %.cpp $(SUB_DIR)

# object 리스트 생성
PHONY := all
all: clean makedir $(TARGET) $(UNITTEST) $(CROW)
$(TARGET): $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS_FOR_TARGET) -o $(OUT_DIR)/$@

$(LIB_DIR)/%.o: %.cpp $(INCS)
	$(CC) $(CXXFLAGS) $(INCS_DIR) $(CROW_INCS) $(UNITTEST_INCS) -c $< -o $@

PHONY += $(CROW)
$(CROW): $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS_FOR_CROW) -o $(OUT_DIR)/$@

PHONY += $(UNITTEST)
$(UNITTEST): $(OBJS_FOR_UNITTEST)
	$(CC) $(CXXFLAGS) $(UNITTEST_LIBS) $(UNITTEST_LIBS_NAME) $(OBJS_FOR_UNITTEST) -o $(OUT_DIR)/$@

PHONY += clean
clean:
	rm -rf $(LIB_DIR) $(OUT_DIR)

PHONY += makedir
makedir:
	if [ ! -d $(LIB_DIR) ]; then mkdir $(LIB_DIR); fi
	if [ ! -d $(OUT_DIR) ]; then mkdir $(OUT_DIR); fi

PHONY += echoes
echoes:
	@echo "SUBDIR : $(SUB_DIR)"
	@echo "NOTDIR_SRCS : $(NOTDIR_SRC)"
	@echo "NOTDIR_SRCS_FOR_TARGET : $(NOTDIR_SRC_FOR_TARGET)"
	@echo "NOTDIR_SRCS_FOR_UNITTEST : $(NOTDIR_SRC_FOR_UNITTEST)"
	@echo "NOTDIR_SRCS_FOR_CROW : $(NOTDIR_SRC_FOR_CROW)"

.PHONY = $(PHONY)