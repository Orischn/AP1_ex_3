#ifndef EX_3_HEADERFILES_FLOWER_H_
#define EX_3_HEADERFILES_FLOWER_H_

#include <vector>
#include <string>

class Flower {
private :
    std::vector<double> data;
    std::string flowerType;
public :
    void setFlowerType(std::string flowerType);
    std::string getFlowerType() const;
    /*
     * Returns the euclidian distance from this flower to a different flower.
     * Input: A flower.
     * Output: The euclidian distance from this flower to the given flower.
     */
    double euclidianDisTo(const Flower& flower) const;
    /*
     * Returns the manhattan distance from this flower to a different flower.
     * Input: A flower.
     * Output: The manhattan distance from this flower to the given flower.
     */
    double manhattanDisTo(const Flower& flower) const;
    /*
     * Returns the chebyshev distance from this flower to a different flower.
     * Input: A flower.
     * Output: The chebyshev distance from this flower to the given flower.
     */
    double chebyshevDisTo(const Flower& flower) const;
    /*
    * The function sorts the classified array using the distance function,
    * and then finds the type of the unclassified flower based on the KNN algorithm.
    * Input: An Array of classified flowers, the length of array, 
    * the k number from the KNN algorithm, and a distance function.
    */
    void classifyFlower(std::vector<Flower> cFlowers, const int k, double (Flower::*distance)(const Flower&) const);
    static Flower stof(std::string);
};

#endif
