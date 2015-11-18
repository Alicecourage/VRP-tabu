#ifndef Vertex_H
#define Vertex_H

#include <map>
#include <vector>
#include "Edge.h"

class Vertex {
public:
    // Only Graph can create an object of type Vertex
    class ConstructionToken {
    private:
        ConstructionToken() = default;
        friend class Graph;
    };

    Vertex(const ConstructionToken &);          //!< constructor

    void InsertEdge(const Customer &, const int &);
    void RemoveEdge(const Customer &);
    int GetWeight(const Customer &) const;
    const std::map<Customer, Edge> GetEdges() const;
	bool SwapState();
	bool GetState() { return this->isFree; }
private:
	bool isFree = true;
    std::map<Customer, Edge> edges;             /**< List of all the edges from customer */

    /** @brief Overriding of '<<' operator */
    friend std::ostream& operator<<(std::ostream& out, const Vertex& v) {
        for(auto& e : v.edges)
            std::cout << e.second.weight << " ";
        return out;
    }
};

#endif /* Vertex_H */
