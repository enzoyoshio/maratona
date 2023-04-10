CXX = g++
CXXFLAGS = -fsanitize=address,undefined -fno-omit-frame-pointer -g -Wall -Wshadow -std=c++2a -Wno-unused-result -Wno-sign-compare -Wno-char-subscripts #-fuse-ld=gold
%: %.cpp
	${CXX} ${CXXFLAGS} $*.cpp -o $*
