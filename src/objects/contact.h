//
// Created by moss on 1/1/19.
//

#ifndef GAMES_SCORE_STATISTICS_CONTACT_H
#define GAMES_SCORE_STATISTICS_CONTACT_H

#include "../../lib/_str.h"

typedef struct contact{
    long long sid;
    long long pid;
    double score;
}contact,* pcontact;

extern contact new_contact();
extern long long contact_get_sid();
extern long long contact_get_pid();
extern double contact_get_score();
extern void contact_set_sid(long long sid);
extern void contact_set_pid(long long pid);
extern void contact_set_score(double score);


#endif //GAMES_SCORE_STATISTICS_CONTACT_H