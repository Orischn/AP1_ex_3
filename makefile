compile:
	@echo "Compiling code..."
	@g++ -pthread -I headerFiles serverSide/*.cpp IO/*.cpp Commands/*.cpp -std=c++11 -o server.exe
	@g++ -pthread -I headerFiles clientSide/*.cpp IO/*.cpp -std=c++11 -o client.exe
run_server:
	@echo "server running..."
	@./server.exe
	@echo "server done"
run_client:
	@echo "client running"
	@./client.exe
	@echo "client done"
