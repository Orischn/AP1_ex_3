#ifndef ADVNACEDPROGRAMMING_FLOWER_H_
#define ADVNACEDPROGRAMMING_FLOWER_H_

#include <vector>
#include <string>

using namespace std;

class Flower {
    private :
        double sepalWidth;
        double sepalLength;
        double petalWidth;
        double petalLength;
        string flowerType;
    public :
        //CTORS
        Flower();
        Flower(const Flower& flower);
        //setters
        void setSepalWidth(double sepalWidth);
        void setSepalLength(double sepalLength);
        void setPetalWidth(double petalWidth);
        void setPetalLength(double petalLength);
        void setFlowerType(string flowerType);
        //getters
        double getSepalWidth();
        double getSepalLength();
        double getPetalWidth();
        double getPetalLength();
        string getFlowerType();
        /*
         * Returns the euclidian distance from this flower to a different flower.
         * Input: A flower.
         * Output: The euclidian distance from this flower to the given flower.
         */
        double euclidianDisTo(Flower flower);
        /*
         * Returns the manhattan distance from this flower to a different flower.
         * Input: A flower.
         * Output: The manhattan distance from this flower to the given flower.
         */
        double manhattanDisTo(Flower flower);
        /*
         * Returns the chebyshev distance from this flower to a different flower.
         * Input: A flower.
         * Output: The chebyshev distance from this flower to the given flower.
         */
        double chebyshevDisTo(Flower flower);
        /*
        * The function sorts the classified array using the distance function,
        * and then finds the type of the unclassified flower based on the KNN algorithm.
        * Input: An Array of classified flowers, the length of array, 
        * the k number from the KNN algorithm, and a distance function.
        */
        void classifyFlower(vector<Flower> cFlowers, int k, double (Flower::*distance)(Flower));
};

#endif
