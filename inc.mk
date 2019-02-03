ECHO=echo
CP=cp
RM=rm
MV=mv

#ifeq (linux, $(LOCAL_HOST))
CC=gcc #arm-linux-gnueabihf-gcc
AR=ar  #arm-linux-gnueabihf-ar
#endif
CFLAGS=-Wall -I/home/sunny/others/system/packages/ffmpeg/deps/build/include
PROJECT=adPlatform
LDFLAGS=-L/home/sunny/others/system/packages/ffmpeg/deps/build/lib
LD_LIBRARY_PATH=
LIBS=-lpthread -lavformat -lavutil -lavcodec -lswresample
EXE=app
