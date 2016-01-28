#ifndef NETWORK_H
#define NETWORK_H

#include "person.h"

class Network
{
public:

    /**
     * @brief Network
     * takes filename and calls readFile funtion to read the file and build network
     * @param filename name of file to read network from
     */
    Network(string filename);
    virtual ~Network();

    /**
     * @brief readFile
     * Reads data file and creates person vector
     * also builds the graph
     * @param filename data file to read
     */
    void readFile(string filename);

    /**
     * @brief find
     * search for a name in the vector of persons
     * @param name person name to search for
     * @return reference to desired person object
     */
    Person* find(QString name);
    /**
     * @brief find
     * search for a name in the vector of persons
     * @param person list of person objects to search in
     * @param name person name to search for
     * @return true if the person exists, false otherwise
     */
    bool find(vector<Person *> & person, QString name);
    /**
     * @brief findIndex
     * search for a name in the vector of persons
     * @param name person name to search for
     * @return index of desired person object
     */
    int findIndex(QString name);

    /**
     * @brief searchGroups
     * search for a name in the vector of groups to decide to which group it belongs to
     * @param groups list of groups each group is a list of person objects
     * @param name person name to search for
     * @return index of the group that person belongs to
     */
    int searchGroups(vector< vector<Person *> > & groups, QString name);

    /**
     * @brief getMutual
     *       returns the number of mutual friends between two persons
     * @param first name of first person
     * @param second second name of second person
     * @param mutual list of mutual friends names
     * @return QString : contains the error message
     *         int : number of mutual friends between two persons
     */
    pair<QString, int> getMutual(QString first, QString second, QStringList & mutual);
    /**
     * @brief KargerMinCut
     * this algo is used in Min cut into 2 groups
     * @return  Minimum Cut acheived
     */
    vector< vector<Person* > > KargerMinCut();

    /**
     * @brief getMinCutValue
     * @param g groups to get min cut between
     * @return
     */
    int getMinCutValue(vector< vector<Person *> > &g);

    /**
     * @brief getSuggestedFriends
     * get a list of suggested friends using the critria
     * that the link between them is no more than 5 person
     * they work for the same company
     * @param name name of person to get suggests for
     * @param sameCompany if true the suggested friend must be in same company
     * @return list of references to suggested person objects
     */
    vector<Person *> getSuggestedFriends(QString name, bool sameCompany);

    /**
     * @brief recurseFriends
     * recursively find friends of friends to a defined limit
     * they need to be from the same company
     * @param suggests contains valid suggests conforming to the cratria
     * @param p reference to the person that you are processing now
     * @param preConn name of the previous connection
     * @param company company name to compare suggests with
     * @param count current count how far this friend from the user
     * @param limit the max length of how far this friend from the user
     */
    void recurseFriends(vector<Person *> & suggests, Person * p, QString preConn, QString company, int count, int limit);

    /**
     * @brief recurseFriends
     * recursively find friends of friends to a defined limit
     * @param suggests contains valid suggests conforming to the cratria
     * @param p reference to the person that you are processing now
     * @param preConn name of the previous connection
     * @param count current count how far this friend from the user
     * @param limit the max length of how far this friend from the user
     */
    void recurseFriends(vector<Person *> & suggests, Person * p, QString preConn, int count, int limit);

    /**
     * @brief initializeMarks
     * forces all bool ismarked varible in all person objects
     * in person vector to be false
     */
    void initializeMarks();

    /**
     * @brief getShortestLink
     * Get shortest link between two nodes
     */
    void getShortestLink();

    /**
     * @brief backtrack
     * @param temp_map
     * @param dst
     * @param src
     */
    void backtrack(std::map<QString, QString> temp_map,QString dst,QString src);

    //variables
    vector<Person *> person; // array of pointers to vector Person
    int personCount; // no of Persons

};

#endif // NETWORK_H
