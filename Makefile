#INCLUDE = -I /usr/local/include /usr/local/include/opencv /usr/local/include/opencv2
# 由于定义的时候<opencv2/opencv.h>这样书写，根据系统路径还是能找到地方的，所以不用制定
# 所以只要指定链接库地址就行
LIB = -L /usr/local/lib /usr/local/lib/*.so
# C/C++编译为obj文件的时候并不需要函数的具体实现，只要有函数的原型即可
# 链接为可执行文件的时候就必须要具体的实现了
# 所以无论是在链接之前编译含opencv的cpp文件，还是函数调用函数，都只需要头文件制定函数原型即可
# 但是最后链接成为可执行文件，都需要全部给出可链接的.o文件，并且需要按照一定的先后顺序

OBJ = sorted.o bubble.o select.o insert.o fast.o merge.o count.o radix.o draw.o

sorted:$(OBJ)
	g++ -o sorted $(OBJ) $(LIB)

sorted.o:sorted.cpp sorted_common.h
	g++ -c sorted.cpp

bubble.o:bubble.cpp sorted_common.h
	g++ -c bubble.cpp

select.o:select.cpp sorted_common.h
	g++ -c select.cpp

insert.o:insert.cpp sorted_common.h
	g++ -c insert.cpp

fast.o:fast.cpp sorted_common.h
	g++ -c fast.cpp

merge.o:merge.cpp sorted_common.h
	g++ -c merge.cpp

count.o:count.cpp sorted_common.h
	g++ -c count.cpp

radix.0:radix.cpp sorted_common.h
	g++ -c radix.cpp

draw.o:draw.cpp
	g++ -c draw.cpp

clean:
	rm *.o