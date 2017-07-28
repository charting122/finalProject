# finalProject
CSCI2270 final project summer 2017

PROJECT SUMMARY
  This project was intended to be used to ship items across a network, if the load is not full items will be added until load is full and than it will be shipped along the shortest path within the network and delete the shipment at the end. This way if companies have to ship to costumers but don't have a full load on their truck could get more items being shipped to the same destination. Or on a larger scale how ups creates shipments from one destination to another however my code will not pick up and drop items off between two destinations.

HOW TO RUN
  simply download the cpp hpp and text files and run the driver file from the command line with the txt file e.g:{ projectDriver.exe projecttxt.txt} doing this will build the network and instantiate the loop to create cities, shipments and to add to current shipments;
  
  DEPENDANCIES
    nonde
    
  SYSTEM REQUIREMENTS
    i wrote this program on my computer which operating windows, the only differences I know are from the command line everything else should be the same.
    
  Colman Hartinger
  
  ISSUES/BUGS;
    there where a few issues i had getting my list of shipments interacting with the graph, i wanted to be able to add and delete shiping contents as you traverse each city on the shortest path but had enough trouble implementing a shortest path algorithm.
