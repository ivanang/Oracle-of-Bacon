// Create a class to store the information needed for the search

#ifndef _ORACLENODE_H
#define _ORACLENODE_H

using namespace std;

class OracleNode {
  private:
    string actor1; //name of actor1
    string actor2; //name of actor2
    string movieLink; //name of movie that actor is in
    OracleNode* previous; //previous actor
  public:
    OracleNode(string firstActor, string secActor, string film, OracleNode* parent);
    //constructor
    OracleNode* getPrevious (); //accessor for previous
    string getFirstActor(); //accessor for actor1
    string getSecondActor(); //accessor for acto2
    string getMovie(); //accessor for movieLink
    void setPrevious(OracleNode *p);
};

#endif
