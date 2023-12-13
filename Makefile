# Tên tệp thực thi
EXECUTABLE := build/main

# Danh sách các tệp cpp bạn muốn biên dịch
SRCS := src/*.cpp

# Đường dẫn đến các thư viện SDL2 và SDL_Image
SDL2_INCLUDE := -Ilib/SDL2/Include/SDL2
SDL2_IMAGE_INCLUDE := -Ilib/SDL_Image/Include/SDL2
INCLUDE := -Iinclude

SDL2_LIB := -Llib/SDL2/lib -lmingw32 -lSDL2main -lSDL2
SDL2_IMAGE_LIB := -Llib/SDL_Image/lib -lSDL2_image

# Quy tắc chính để biên dịch chương trình
all: $(EXECUTABLE) run

# Biên dịch chương trình từ main.cpp
$(EXECUTABLE): $(SRCS)
	g++ $(SDL2_INCLUDE) $(SDL2_IMAGE_INCLUDE) $(INCLUDE) -o $(EXECUTABLE) $(SRCS) $(SDL2_LIB) $(SDL2_IMAGE_LIB)

# Mục tiêu để chạy chương trình
run:
	$(EXECUTABLE)

