# AdvancedProgrammingProject
**IMPORTANT: You need to make sure that you pulled all the files and the folders**

We read the data from the given input path into a character array.

Then, we sent the array from the client side to the server side.

On the server side, we wrote the received data to a temporary file.

We created a vector of unclassified flowers from the temporary file, and we created a vector of classified flowers from the given classified flowers file.


Then, for each unclassified flower we applied the algorithm below:

Firstly, we sorted the flowers array using the given distance method that was given as an argument to the function.
Then, we counted the amount of times that each type of the first k flowers in the sorted array appeared.
We set the type of unclassified flower as the most appeared type from above, which made the flower classified.

Then, we wrote the type of the classified flowers (were unclassified) to a temporary file.

We read the data from the temporary file into a character array.

We sent the array from the server side to  back to the client side.

Eventually, on the client side, we wrote the received data into the given output path.

We used port number 42069 (because it's a cool number).

We used a 30 seconds timeout length.

We used a buffer size of 240 characters, which translates into 240 bytes, like the size of the given unclassified flowers file.


To compile the server use the following command **from the project path**:

g++ -I headerFiles serverSide/*.cpp sock.cpp -std=c++11 -o server.exe

To compile the client use the following command **from the project path**:

g++ -I headerFiles clientSide/*.cpp sock.cpp -std=c++11 -o client.exe

To run the server side use:

./server.exe

To run the client side use:

./client.exe clientSide/unclassified.csv clientSide/classified.csv
