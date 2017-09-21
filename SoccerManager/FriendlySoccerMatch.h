#include "FriendlyMatch.h"
#include "Team.h"

class FriendlySoccerMatch : public FriendlyMatch
{
private:
    string nameHomeTeam;
    string nameGuestTeam;
    int pointsHome;
    int pointsGuest;
    bool printToFile;
public:
    //constructor
    FriendlySoccerMatch();
    //~FriendlySoccerMatch(){}

    //get set function
    string getHomeTeam();
    string getGuestTeam();
    int getHomePoints();
    int getGuestPoints();
    string getResultText();
    void setPrint(bool f);
    float calculateStrength(Team team);
    void attack(Team attackTeam, Team defenceTeam, bool isGuest, int time);

    // start game function
    void startGame(Team t1, Team t2);
};
