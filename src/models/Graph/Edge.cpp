struct GraphEdge{
    int origin;
    int destiny;
    int weight; // Can be 1, in case it is not weighted.
    GraphEdge(int aOrigin, int aDestiny, int aWeight = 1) : origin(aOrigin), destiny(aDestiny), weight(aWeight) {}

    public:

    bool Equal(GraphEdge anotherEdger){
        return this->destiny == anotherEdger.destiny && this->origin == anotherEdger.origin && this->weight && anotherEdger.weight;
    }
};