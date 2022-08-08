# AdvancedProgrammingProject
**IMPORTANT: You need to make sure that you pulled all the files and the folders**

For each unclassified flower we applied the algorithm below:

Firstly, we sorted the flowers array using the given distance method that was given as an argument to the function.
Then, we counted the amount of times that each type of the first k flowers in the sorted array appeared.
We set the type of unclassified flower as the most appeared type from above, which made the flower classified.

To compile the server use the following command **from the project path**:

g++ -I headerFiles serverSide/*.cpp *.cpp -std=c++11 -o server.exe

To compile the client use the following command **from the project path**:

g++ -I headerFiles clientSide/*.cpp *.cpp -std=c++11 -o client.exe

To run the server side use:

./server.exe

To run the client side use:

./client.exe