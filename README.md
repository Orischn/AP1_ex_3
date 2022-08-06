# AdvancedProgrammingProject
**IMPORTANT: You need to make sure that you pulled all the files and the folders**

For each unclassified flower we applied the algorithm below:

Firstly, we sorted the flowers array using the given distance method that was given as an argument to the function.
Then, we counted the amount of times that each type of the first k flowers in the sorted array appeared.
We set the type of unclassified flower as the most appeared type from above, which made the flower classified.

To compile the project use the following command:

g++ -IsocketHandling serverSide/*.cpp socketHandling/sock.cpp -o server.exe -std=c++11 && g++ -Isockethandling clientSide/*.cpp socketHandling/sock.cpp -o client.exe -std=c++11

To run the server side use:

./server.exe

To run the client side use:

./client.exe