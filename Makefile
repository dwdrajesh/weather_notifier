SRC_DIR=./Source
INC_DIR=./include
CFLAGS=-g -std=c++11
all:
	#make clean
	g++ -pthread  $(CFLAGS) -c $(SRC_DIR)/server.cpp
	g++ -pthread  $(CFLAGS) -c $(SRC_DIR)/client.cpp

	g++ -pthread  $(CFLAGS) -I $(INC_DIR) -c $(SRC_DIR)/main.cpp 
	g++ -pthread  $(CFLAGS) -I $(INC_DIR) -c $(SRC_DIR)/main_client.cpp
	g++ -pthread $(CFLAGS) -o main main.o server.o
	g++ -pthread $(CFLAGS) -o main_client main_client.o client.o


clean:
	[ -f server ] && rm ./server || echo "no object"
	[ -f client ] && rm ./client || echo "no object"
	rm main
	rm main_client
	rm main.o 
	rm main_client.o
	rm server.o
	rm client.o	
