
#ifndef project_HPP
#define project_HPP
using namespace std;


struct shipment{
  string destination, start,name;
  int const maxWeight=10000;
  int currentWeight;
  map<string,int> contents;
  shipment* next;
};
struct vertex;
struct adjVertex{
  vertex *v;
  int weight;
};
struct vertex{
  string name;

  vector<adjVertex> adj;
  shipment* stuff;
};
class Graph{
    protected:
    private:
      int vertices_count;
      shipment* head,*tail;
      vector<vertex> vertices;
    public:
      Graph();
      ~Graph();
      void addEdge(std::string v1, std::string v2, int weight);
      void addVertex(std::string name);
      void createShipment(string destination, string start,string name,string desc,int w);
      shipment* findShipment(int weight,string destination, string start);
      void shipContent(string load,int kg,string destination, string start);
      void displayShipments();
      void displayEdges();
      void findPath(string,string);//TODO
      void delete_last();
      void delete_first();
      void delete_position(string name);
      void deleteShipment(string name);
};
#endif
