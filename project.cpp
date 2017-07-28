#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <map>
#include <utility>
#include "project.hpp"
using namespace std;


Graph::Graph(){
  head=nullptr;
  tail=nullptr;
  vertices_count=1;
}
Graph::~Graph(){}
void Graph::addEdge(string v1, string v2,int weight){
  for(int i = 0; i < vertices.size(); i++){
      if(vertices[i].name == v1){
          int count = 0;
          for(int j = 0; j < vertices.size(); j++){
              if(vertices[j].name == v2 && i != j){
                  adjVertex av;
                  av.v = &vertices[j];
                  av.weight = weight;
                  vertices[i].adj.push_back(av);
                  count=1;//adj city
              }
          }
      }
  }
}
void Graph::addVertex(string name){
  bool found = false;
  vertex v;
  if(vertices.size()==0){
    v.name = name;
    vertices.push_back(v);
    found=true;
  }
  else{
    for(int i = 0; i < vertices.size()+1; i++){
      if(vertices[i].name == name){
        found = true;
        //cout<<vertices[i].name<<" found."<<endl;
        return;
      }
    }
  }

  if(found == false){
      //vertex<T> v;
      v.name = name;
      vertices.push_back(v);

  }
  vertices_count++;

}
void Graph::displayEdges(){
  for(int i = 0; i < vertices.size(); i++){
      cout<<vertices[i].name<<"--->";
      for(int j = 0; j < vertices[i].adj.size(); j++){
          cout<<vertices[i].adj[j].v->name<<"--->";
      }
      cout<<endl;
  }
}
void Graph::createShipment(string destination, string start,string name,string desc, int w){
  //TODO find shortestPath
  shipment* temp= new shipment;
  temp->destination=destination;
  //temp->maxWeight=10000;
  temp->start=start;
  temp->name=name;
  temp->contents[desc]=w;
  temp->currentWeight=w;
  temp->next=nullptr;
  if(head==nullptr){
    head=temp;
    tail=temp;
    temp=nullptr;
  }
  else{
    tail->next=temp;
    tail=temp;
  }
}
void Graph::displayShipments(){
  shipment* temp=new shipment;
  temp=head;
  while (temp!=nullptr){
    cout<<"currentWeight "<<temp->currentWeight<<endl;
    cout<< "destination: "<<temp->destination<<"starting point: "<<temp->start<<" "<<temp->name<<endl;
    for(auto& x: temp->contents){
      cout<<"description: "<<x.first<<" weight:"<<" "<<x.second<<endl;
    }
    temp=temp->next;
  }
}
shipment* Graph::findShipment(int weight,string destination, string start){
  shipment* walker= head;
  while(walker!=nullptr){
    if((walker->currentWeight+weight)<walker->maxWeight&& walker->destination==destination&&walker->start==start){
      return walker;
    }
    walker=walker->next;
  }
  if(walker->currentWeight>walker->maxWeight-1000){
    deleteShipment(walker->name);
    cout<<"shipment reacheed destination\n";
  }
}
void Graph::shipContent(string load,int kg,string destination, string start){
  shipment* walker= nullptr;
  walker=findShipment(kg,destination,start);
  if(walker==nullptr){cout<<"shipment not found \n"; return;}
  walker->contents[load]=kg;
  walker->currentWeight+=kg;
}
void Graph::delete_first(){
   shipment *temp=new shipment;
   temp=head;
   head=head->next;
   delete temp;
 }
void Graph::delete_last(){
   shipment *current=new shipment;
   shipment *previous=new shipment;
   current=head;
   while(current->next!=nullptr){
     previous=current;
     current=current->next;
   }
   tail=previous;
   previous->next=nullptr;
   delete current;
 }
void Graph::delete_position(string name){
   shipment *current=new shipment;
   shipment *previous=new shipment;
   current=head;
   while(current->name !=name)
   {
     previous=current;
     current=current->next;
   }
   previous->next=current->next;
 }
void Graph::deleteShipment(string name){
   shipment* temp= new shipment;
   temp=head;
   if(head->name==name){delete_first();}
   else if(tail->name==name){delete_last();}
   else{
     delete_position(name);
   }
 }
//vertex Gsearch
