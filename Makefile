# Tên tệp thực thi
EXECUTABLE := build/main

# Danh sách các tệp cpp bạn muốn biên dịch
SRCS := src/main.cpp

# Quy tắc chính để biên dịch chương trình
all: $(EXECUTABLE) run

# Biên dịch chương trình từ main.cpp
$(EXECUTABLE): $(SRCS)
	g++ -Ilib/Include/SDL2 -Llib/lib -o $(EXECUTABLE) $(SRCS) -lmingw32 -lSDL2main -lSDL2

# Mục tiêu để chạy chương trình
run:
	$(EXECUTABLE)

# clean:
# 	rm -f $(EXECUTABLE)