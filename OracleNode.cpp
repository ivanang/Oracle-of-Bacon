// Implementation of the OracleNode.h file
//
#include <iostream>
#include <cstdlib>
#include "OracleNode.h"

using namespace std;

OracleNode::OracleNode(string firstActor, string secActor, string film, OracleNode* parent) {
  actor1 = firstActor;
  actor2 = secActor;
  movieLink = film;
  previous = parent;
}

OracleNode* OracleNode::getPrevious(){
  return previous;
}

string OracleNode::getFirstActor(){
  return actor1;
}

string OracleNode::getSecondActor(){
  return actor2;
}

string OracleNode::getMovie(){
  return movieLink;
}

void OracleNode::setPrevious(OracleNode* p){
  previous = p;
}

