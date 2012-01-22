////////
//BY IVANA NG // CS 35 Data Structures and Algorithms, Dec 9 2009
///////

#include <iostream>
#include <stdexcept>
#include "HashTableDictionary.h"
#include "ArrayList.h"
#include "LinkedQueue.h"
using namespace std;

void makeDict(string filename, HashTableDictionary* actorDict, HashTableDictionary* filmDict); 
void intro();
void reportPath(string type, OracleNode* finalActor);

int main() {
  //creates two hash tables; one indexes actors and the other indexes films
  string testFile = "Bacon2Links.txt";
  HashTableDictionary* actorDict = new HashTableDictionary(99999);
  HashTableDictionary* filmDict = new HashTableDictionary(99999);
  makeDict(testFile, actorDict, filmDict);
  ////////////////////////////////////////

  cout << "Welcome to the Oracle of Bacon [sizzleNoise]!\n\n";

  while (true) {
    cout << "(1) Tell me all the movies this actor has been in\n"
      << "(2) Tell me all the actors that starred in this movie\n"
      << "(3) Find the degrees of separation between two actors.\n"
      << "(4) Quit\n\n";
    cout << "Choice: ";
    int choice;
    cin >> choice;

    //checks for invalid input
    if (choice<0 || choice>4){
      cout << "Invalid input. Please try again.\n\n";
    }

    // if user enters 4, program ends
    if (choice==4){
      cout << "Goodbye!\n\n";
      return 0;
    }

    cin.get();
    int i; //variable for for-loop
    int j; // variable for for-loop

    // returns list of movies an actor has been in
    if (choice==1){
      cout << "Actor's name: ";
      string name;
      getline(cin, name);
      if (actorDict->containsKey(name)){
        for (i=0;i<actorDict->get(name)->length();i++){
          cout << actorDict->get(name)->get(i)<<endl;
        }
      }
      else {
        cout << "Sorry, name cannot be found in database.\n";
      }
      cout << endl;
    }

    // returns list of actors in the movie entered by the user
    if (choice == 2){
      cout << "Movie name: ";
      string movie;
      getline(cin, movie);
      if (filmDict->containsKey(movie)){
        for (i=0;i<filmDict->get(movie)->length();i++){
          cout << filmDict->get(movie)->get(i)<<endl;
        }
      }
      else {
        cout << "Sorry, movie cannot be found in database.\n";
        return 0;
      }
      cout << endl;
    }

    // finds a link between two actors
    if (choice==3){
      cout << "Enter first actor's name: ";
      string firstActor;
      getline(cin, firstActor);
      cout << "Enter second actor's name: ";
      string secondActor;
      getline(cin, secondActor);
     
      if (!actorDict->containsKey(firstActor) || 
          !actorDict->containsKey(secondActor)){
        cout << "Sorry, one of the two actors you entered cannot be "
          << "found in our database.\n\n";
      }

      //checks if user wanted to find the link b/w an actor and him or
      // her self.
      else if (firstActor==secondActor){
        cout << firstActor <<" IS "<<secondActor << " so "
          <<secondActor << " has a " <<firstActor << " number of 0.\n\n";
      }

      //otherwise, find the link between the two actors
      else {
        LinkedQueue* searchQueue = new LinkedQueue();

        OracleNode* parent = NULL;
        OracleNode* k = NULL;
        string costar;
        string movie;
        string baconNum = firstActor; //keeps track of what type of "number"
        // we want to find for the secondActor
        HashTableDictionary* repeatDict = new HashTableDictionary(99999); 
        // this dictionary stores all the actor's names encountered during a search

        bool queueFull = true;
exitLoop:
        while (queueFull) {
          for (i=0;i<actorDict->get(firstActor)->length();i++){
            movie = actorDict->get(firstActor)->get(i);
            for (j=0;j<filmDict->get(movie)->length();j++){
              costar = filmDict->get(movie)->get(j);
              if (!repeatDict->containsKey(costar)){
                repeatDict->put(costar, 0);
                k = new OracleNode(firstActor, costar, movie, parent);
                k->setPrevious(parent);
              }
              if (costar==secondActor){
                reportPath(baconNum, k);
                cout << endl;
                queueFull = false;
                searchQueue->~LinkedQueue(); //deletes queue
                repeatDict->~Dictionary(); // deletes third hash table
                goto exitLoop; // this allows program to exit the nested
                // for-loops, once we've found a link
              }
              else {
                searchQueue->enqueue(k);
              }
            }
          }
          if (searchQueue->isEmpty()){
            cout << "No link found.\n" << secondActor << " has a "
              <<baconNum<< " number of infinity.\n\n";
            queueFull = false;
          }
          parent = searchQueue->front();
          firstActor = searchQueue->dequeue()->getSecondActor(); 
        }
      }
    }
  }
}

void reportPath(string type, OracleNode* finalActor){
  string hasNum = finalActor->getSecondActor();
  int linkNum = 0;
  while (finalActor!=NULL) {
    cout << finalActor->getSecondActor() << " was in "
        << finalActor->getMovie() << " with " 
        << finalActor->getFirstActor() << ".\n";
    finalActor = finalActor->getPrevious();
    linkNum ++;
  }
  string typeNum = type;
  cout << hasNum << " has a " << typeNum << " number of "
    << linkNum << ".\n\n";
}


void makeDict(string filename, HashTableDictionary* actorDict, HashTableDictionary* filmDict) {
  //this function simultaneously creates the actorDict and the filmDict
  char line[256];
  string text;
  FILE *in = fopen(filename.c_str(),"r");
  int first, second, third;
  string name, title;

  if (in==NULL)
    cout <<  "Search database cannot be found.\n\n";

  while (fgets(line,256,in) != NULL){
    text = (const char *)line;
    first = text.find("\t");
    name = text.substr(0,first);
    second = text.find("\t", first+1);
    if (second != first+1)
      name += " " + text.substr(first+1, second-first-1);
    third = text.find("\t", second+1);
    title = text.substr(second+1,third-second-1);
    title += " (" + text.substr(third+1,4) + ")";

    if (!actorDict->containsKey(name)){
      ArrayList* listOfMovies = new ArrayList(100);
      actorDict->put(name, listOfMovies);
      actorDict->get(name)->append(title);
    }
    else {
      actorDict->get(name)->append(title);
    }
    if (!filmDict->containsKey(title)){
      ArrayList* listOfActors = new ArrayList(100);
      filmDict->put(title, listOfActors);
      filmDict->get(title)->append(name);
    }
    else {
      filmDict->get(title)->append(name);
    }
  }
  fclose(in);
}
