compile_code:
	@echo "Compiling code..."
	@g++ -I headerFiles serverSide/*.cpp -std=c++11 -o server.exe
	@g++ -I headerFiles clientSide/*.cpp -std=c++11 -o client.exe
run_server:
	@echo "server running..."
	@./server.exe
	@echo "server done"
run_client:
	@echo "client running"
	@./client.exe clientSide/unclassified.csv clientSide/classified.csv
	@echo "client done"