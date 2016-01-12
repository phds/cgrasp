UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
  CCFLAGS = -I/usr/include/python2.7/  -lpython2.7 -lmpfr -lgmp -lm
endif
ifeq ($(UNAME_S),Darwin)
  CCFLAGS = -framework Python
endif

linesearch: linesearch.cpp
	g++ linesearch.cpp -o bin/linesearch $(CCFLAGS)

constructgrandomized: ConstructGreedyRandomized.cpp linesearch.cpp
	g++ ConstructGreedyRandomized.cpp -o bin/ConstructGreedyRandomized $(CCFLAGS)

localimprovement: LocalImprovement.cpp
	g++ localImprovement.cpp -o bin/localImprovement $(CCFLAGS)