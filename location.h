#ifndef LOCATION_H
#define LOCATION_H

class location
{
public:

    location()
    {id=0;energy_required=0;visitedbefore=false;quest=false;}

    location(int idC,int energy_requiredC,bool visitedbeforeC,bool questC)
    {id=idC;energy_required=energy_requiredC;visitedbefore=visitedbeforeC;quest=questC;}



    ~location(){}
private:

    int id;
    int energy_required;
    bool visitedbefore;
    bool quest;
public:

    int id_val(){return id;}
    void id_setval(int idS){id=idS;}
    int energy_required_val(){return energy_required;}
    void energy_required_setval(int erS){energy_required=erS;}
    bool visitedbefore_val(){return visitedbefore;}
    void visitedbefore_setval(bool vbS){visitedbefore=vbS;}
    bool quest_val(){return quest;}
    void quest_setval(bool qS){quest = qS;}
};

#endif // LOCATION_H
