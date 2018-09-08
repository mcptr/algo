all:
	for d in *; do test -d $$d && cd $$d && $(MAKE) && cd -; done

clean:
	for d in *; do test -d $$d && cd $$d && $(MAKE) clean && cd -; done
