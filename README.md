# AdvancedProgrammingProject
**IMPORTANT: You need to make sure that you pulled all the files and the folders**

We created IO systems that inherit from the DefaultIO to communicate between client and server side.

We used FileIO to write and read from files, SocketIO to transfer data between client and server sides using sockets.

Then, we created the CLI, that manages the communication between the client(s) to the server.

We created a class for each command that a client can send to the server, and implemented the way the server will deal with the received data and send it back.

All the command classes inherites from the class Command.

Then, using the SocketIO way of sending data, we received the wanted command from the client and executed the relevat implementation.

The first (1) command is used to upload the data that the client want to be classified (a train and a test files).

The second (2) command is the settings of the classifier, the client can decide the wanted value of k and the distance function he would like to classify his data with.

The default settings are k=3 and the distance function is EUC.

The third command (3) is used to classify the data from the uploaded file (command 1) using the algorithm settings (command 2).

The forth command (4) is used to display the classified data for the client.

The fifth command (5) is used to let the client download and save the classified data he received from the server.

The sixth command (6) is used to show to show the client the confusion matrix of the algorithm.

The seventh (7) and final command allow the client to exit the program and terminates the communication between the server to this current client.

To **compile** the code use the following command **from the project path**:

make compile

To **run** the **server** side use:

make run_server

To **run** the **client** side use from a **different terminal**:

make run_client

**THATS IT?**

**DOES THE PARY BEL0W RELEVANT?

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

We used a 10 seconds timeout length.

We used a buffer size of 240 characters, which translates into 240 bytes, like the size of the given unclassified flowers file.

