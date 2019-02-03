include $(PRJROOT)/inc.mk

all: clean app link

link:
	$(CC) -o $(EXE) build/*.o $(LDFLAGS) $(CFLAGS) $(LIBS)
	@$(MV) $(EXE) bin

create_build:
	@mkdir build
	@mkdir bin

app: create_build headers
	$(MAKE) -C src/main build
	$(MAKE) -C src/client build
	$(MAKE) -C src/osal build
	$(MAKE) -C src/protocol build
	$(MAKE) -C src/parser build

headers:
	$(MAKE) -C src/main headers
	$(MAKE) -C src/client headers
	$(MAKE) -C src/osal headers
	$(MAKE) -C src/protocol headers
	$(MAKE) -C src/parser headers

clean:
	$(MAKE) -C src/main clean
	$(MAKE) -C src/client clean
	$(MAKE) -C src/osal clean
	$(MAKE) -C src/protocol clean
	$(MAKE) -C src/parser clean
	@$(RM) -rf build/*.o
	@$(RM) -rf build
	@$(RM) -rf bin/*
	@$(RM) -rf bin
