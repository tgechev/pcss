#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "FriendlySoccerMatch.h"

//constructor
FriendlySoccerMatch::FriendlySoccerMatch()
{
    nameHomeTeam="A";
    nameGuestTeam="B";
    pointsHome=0;
    pointsGuest=0;
    printToFile=false;
}
//~FriendlySoccerMatch(){}
//get set function
string FriendlySoccerMatch::getHomeTeam()
{
    return nameHomeTeam;
}
string FriendlySoccerMatch::getGuestTeam()
{
    return nameGuestTeam;
}
int FriendlySoccerMatch::getHomePoints()
{
    return pointsHome;
}
int FriendlySoccerMatch::getGuestPoints()
{
    return pointsGuest;
}

string FriendlySoccerMatch::getResultText()
{
    stringstream sstm;
    sstm<<"The friendly game ends with		\n\n"<<nameHomeTeam<<" - "<<nameGuestTeam<<" "<<pointsHome<<":"<<pointsGuest<<".";
    return sstm.str();
}

void FriendlySoccerMatch::setPrint(bool f)
{
    printToFile=f;
}
float FriendlySoccerMatch::calculateStrength(Team team){
    //influence of motivation on strength
    float strength = team.getStrength()/2.0f+((team.getStrength()/2.0f)*(team.getMotivation()/10.0f));

    //influence of trainer on strength
    int deviation=rand()%2;
        if(strength>team.getCoach().getExperience())
        {
            deviation=-deviation;
        }
    return strength=max(1,min(10,(int)strength+deviation));

}

void FriendlySoccerMatch::attack(Team attackTeam, Team defenceTeam, bool isGuest, int time){
            ofstream out_stream;

            //randomly choose player for shooting
            int shooter=rand()%10;
            Player p=attackTeam.getPlayer(shooter);
            Keeper k=defenceTeam.getKeeper();
            int shot=p.shootsOnGoal();

            //check if shot is saved
            bool goal=!k.saveShot(shot);

            if(!printToFile){
                cout<<"\n"<<time<<".Minute: \n";
                cout<<" Chance for "<<attackTeam.getName()<<" ...\n";
                cout<<" "<<p.getName()<<" shoots\n";
            }else
            {
                out_stream.open("test.txt", ios::app);
                out_stream<<"\n"<<time<<".Minute: \n";
                out_stream<<" Chance for "<<attackTeam.getName()<<" ...\n";
                out_stream<<" "<<p.getName()<<" shoots\n";
                out_stream.close();
            }

            if(goal)
            {
                if(!isGuest){
                    pointsHome++;
                }else{
                    pointsGuest++;
                }
                attackTeam.addGoal(shooter);
                if(!printToFile){
                    cout<<" Goal!!! "<<pointsHome<<":"<<pointsGuest;
                    cout<<" "<<p.getName()<<"("<<attackTeam.getPlayer(shooter).getGoals()<<")\n";
                }else
                {
                    out_stream.open("test.txt", ios::app);
                    out_stream<<" Goal!!! "<<pointsHome<<":"<<pointsGuest;
                    out_stream<<" "<<p.getName()<<"("<<attackTeam.getPlayer(shooter).getGoals()<<")\n";
                    out_stream.close();
                }
            } else
            {
                if(!printToFile){
                    cout<<" "<<defenceTeam.getKeeper().getName()<<" saves brilliantly.\n";
                }else
                {
                    out_stream.open("test.txt", ios::app);
                    out_stream<<" "<<defenceTeam.getKeeper().getName()<<" saves brilliantly.\n";
                    out_stream.close();
                }
            }
}

// start game function
void FriendlySoccerMatch::startGame(Team t1, Team t2)
{
    //inits
    nameHomeTeam=t1.getName();
    nameGuestTeam=t2.getName();
    pointsHome=0;
    pointsGuest=0;

    //make ready for game
    bool gameRuns=true;
    int gameDuration=90+rand()%5;
    int time=1;
    int nextAction;

    if(printToFile)
    {
        remove("test.txt");
    }

    // start game
    while(gameRuns)
    {
        nextAction=rand()%15+1;
        if((time+nextAction>gameDuration)||(time>gameDuration))
        {
            gameRuns=false;
            break;
        }
        //new action
        time=time+nextAction;

        float strength1 = calculateStrength(t1);

        float strength2 = calculateStrength(t2);


        //the stronger team has greater chance to attack
        if((rand()%((int)(strength1+strength2))-strength1)<=0)
        {
            attack(t1, t2, false, time);

        } else
        {
            attack(t2, t1, true, time);
        }
    }

}

