CC = g++ -Wall
SRCS = ./*.cpp
OBS = ./*.o

# The following line means that do SRC first.
pipeline: SRC
	$(CC) -o $@ $(OBS)

SRC: $(SRCS)
	$(CC) -c $(SRCS)

clean: $(OBS)
	rm $(OBS) pipeline
