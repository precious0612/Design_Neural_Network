# 检测操作系统
UNAME := $(shell uname -s)

# 设置编译器标志
ifeq ($(UNAME), Linux)
    CFLAGS += -D_POSIX_C_SOURCE=200809L
else ifeq ($(UNAME), Darwin)
    CFLAGS += -D_DARWIN_C_SOURCE
endif
CFLAGS += -Wall -Wextra

# 设置库链接路径
ifeq ($(UNAME), Linux)
    LDFLAGS += -L/usr/local/lib
else ifeq ($(UNAME), Darwin)
    LDFLAGS += -L/opt/homebrew/Cellar/json-c/0.17/lib -L/opt/homebrew/Cellar/jpeg-turbo/3.0.2/lib -L/opt/homebrew/opt/libpng/lib -L/opt/homebrew/Cellar/hdf5/1.14.3_1/lib
endif
LDLIBS = -ljson-c -lturbojpeg -lpng16 -lz -lhdf5 -lopenblas

# 设置头文件路径
ifeq ($(UNAME), Linux)
    CFLAGS += -I/usr/local/include
else ifeq ($(UNAME), Darwin)
    CFLAGS += -I/usr/local/include/stb -I/opt/homebrew/Cellar/json-c/0.17/include -I/opt/homebrew/Cellar/json-c/0.17/include/json-c -I/opt/homebrew/Cellar/jpeg-turbo/3.0.2/include -I/opt/homebrew/opt/libpng/include/libpng16 -I/opt/homebrew/Cellar/hdf5/1.14.3_1/include
endif

# 设置目标文件扩展名
ifeq ($(UNAME), Linux)
    OBJ_EXT = .o
else ifeq ($(UNAME), Darwin)
    OBJ_EXT = .o
else
    OBJ_EXT = .obj
endif

# 排除 main.c
SOURCES = $(filter-out main.c, $(wildcard *.c input/data.c model/model.c model/layer/layer.c model/loss/losses.c model/metric/metric.c model/optimizer/optimizer.c utils/*.c utils/compute/*.c))
OBJECTS = $(patsubst %.c, %$(OBJ_EXT), $(SOURCES))
HEADERS = $(wildcard *.h input/*.h model/*.h model/layer/*.h model/loss/*.h model/metric/*.h model/optimizer/*.h utils/*.h utils/compute/*.h)
EXAMPLE_EXECUTABLE = main

all: $(EXAMPLE_EXECUTABLE)

$(EXAMPLE_EXECUTABLE): main$(OBJ_EXT) $(OBJECTS)
	$(CC) $(LDFLAGS) main$(OBJ_EXT) $(OBJECTS) $(LDLIBS) -o $@

main$(OBJ_EXT): main.c $(HEADERS)
	$(CC) $(CFLAGS) -c main.c -o main$(OBJ_EXT)

%.$(OBJ_EXT): %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

run_example: $(EXAMPLE_EXECUTABLE)
	./$(EXAMPLE_EXECUTABLE)

.PHONY: all clean run_example