.PHONY: all clean


all:
	@for d in *; do \
		test -d $$d && test -f $$d/Makefile && \
			(echo ">>> Buliding $$d" && \
			cd $$d && $(MAKE) && cd - && echo "") || \
			true; \
	done

clean:
	@for d in *; do \
		test -d $$d && test -f $$d/Makefile && \
			(echo ">>> Cleaning $$d" && \
			cd $$d && $(MAKE) clean && cd - ) || \
			true; \
	done
