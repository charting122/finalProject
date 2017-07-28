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

int main(int argc, char const *argv[]) {
  Graph G;
  ifstream file;
  file.open(argv[1]);
  //file.open("project.txt");
  if(file.fail()){
    cout << "Could not open file\n";
    exit(1);
  }
  string line,key,city;

  // build vertexes
  while(getline(file,line)){// within this while loop build vertex
    stringstream ss(line);
    getline(ss,key,'-');
    G.addVertex(key);
  }
  file.close();

  file.open(argv[1]);
  if(file.fail()){
    cout << "Could not open file\n";
    exit(1);
  }
  // build edges from file
  while(getline(file,line)){// within this while loop build vertex
    stringstream ss(line);
    getline(ss,key,'-');
    city=key;
    string adCit; int weight;

    while(!ss.eof()){//within this while loop build adjacent cities
      getline(ss,key,',');
      adCit=key;
      getline (ss,key,',');
      weight=stoi(key);
      G.addEdge(city, adCit, weight);
    }
    //cout<<endl;
  }
  file.close();

  // creating initial shipments
  G.createShipment("Boulder", "Colorado Springs","pc3","apples",2000 );
  G.createShipment("Boulder", "Grand Junction","al3","pens",1000 );
  G.createShipment("Denver","Frisco","ar4","tuna",4000);



  int num;
  while(num!=5){
    cout<<"===Main Menu===\n";
    cout<<"1. Add City and adj cities\n";
    cout<<"2. Print Network and shipments\n";
    cout<<"3. Create shipment\n" ; // use multiple shortest path algortithms
    cout<<"4. Find shipment\n";
    cout<<"5. Quit program\n";
    cin>>num;
    switch(num){
      case 1:{
        string name,city1;
        cout<<"enter city name \n";
        cin>>ws;
        getline(cin,name);
        G.addVertex(name);
        char c;
        int distance;
        while(c!='s'){
          cout<<"enter adjacent cities\n ";
          cin>>ws;
          getline(cin,city1);
          cout<<"enter distance enter s to stop adding adjacent cities\n";
          cin>>distance;
          G.addEdge(name, city1,distance);
          cout<<" enter s to stop, or another character to continue\n";
          cin>>c;

        }
      }
      case 2:{
        G.displayEdges();
        cout<<endl;
        G.displayShipments();
        break;
      }
      case 3:{
        string destination, start, name, description;
        int weight;
        cout<<"Enter start\n";
        cin>>ws;
        getline(cin,start);
        cout<<"Enter destination\n";
        cin>>ws;
        getline(cin,destination);
        cout<<"Enter shipment name\n";
        cin>>ws;
        getline(cin,name);
        cout<<"enter shipment description\n";
        cin>>ws;
        getline(cin,description);
        cout<<"Enter shipment weight";
        cin>>weight;
        G.createShipment(destination,start,name,description,weight);

        //TODO cout<< shortest path
        break;
      }
      case 4:{
        string load;
        int kg;
        string destination;
        string start;
        cout<<"Enter start\n";
        cin>>ws;
        getline(cin,start);
        cout<<"Enter destination\n";
        cin>>ws;
        getline(cin,destination);
        cout<<"Enter shipment weight\n";
        cin>>kg;
        cout<<"enter load description\n";
        cin>>ws;
        getline(cin,load);
        G.shipContent(load,kg,destination,start);

        //TODO print path if shipment found

        break;
      }
      case 5:{
        cout<<"quitting";
        exit(1);
      }
    }
  }

  return 0;
}
