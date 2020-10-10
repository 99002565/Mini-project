all: all.out
all.out : NBA.o NBA_db.o result.o result_test.o NBA_db_test.o
	g++ $^ -o $@ -lgtest -lgtest_main -lpthread
NBA_db_test.o: NBA_db_test.cpp result.h NBA.h NBA_db.h
	g++ $< -c
result_test.o: result_test.cpp result.h NBA.h
	g++ $< -c
NBA_db.o : NBA_db.cpp NBA_db.h NBA.h result.h
	g++ $< -c
result.o : result.cpp NBA.h result.h
	g++ $< -c    
NBA.o : NBA.cpp NBA.h
	g++ $< -c
valgrind.o : ./all.out
	valgrind ./all.out
cppcheck: *.cpp
	cppcheck *.cpp
clean:
	rm -rf *.o *.out
