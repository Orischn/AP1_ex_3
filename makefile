compile:
	@echo "Compiling code..."
	@g++ -g -I headerFiles serverSide/*.cpp IO/*.cpp -std=c++11 -o server.exe
	@g++ -g -I headerFiles clientSide/*.cpp -std=c++11 -o client.exe
run_server:
	@echo "server running..."
	@./server.exe
	@echo "server done"
run_client:
	@echo "client running"
	@./client.exe clientSide/unclassified.csv clientSide/classified.csv
	@echo "client done"
