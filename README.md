# AdvancedProgrammingProject
**IMPORTANT: You need to make sure that you pulled all the files and the folders**

For each unclassified flower we applied the algorithm below:

Firstly, we sorted the flowers array using the given distance method that was given as an argument to the function.
Then, we counted the amount of times that each type of the first k flowers in the sorted array appeared.
We set the type of unclassified flower as the most appeared type from above, which made the flower classified.

To compile the project use the following command:

g++ *.cpp -std=c++11 -o main.exe

To run the project after compiling, use the following command:

./main.exe k

(k is the **number** from the KNN algorithm, which means you put a number at the command line, and not the char 'k').

The output files will be created in the directory named 'out'.
