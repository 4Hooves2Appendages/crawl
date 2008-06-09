/*
 *  File:       religion.h
 *  Summary:    Misc religion related functions.
 *  Written by: Linley Henzell
 *
 *  Modified for Crawl Reference by $Author$ on $Date$
 *
 *  Change History (most recent first):
 *
 *               <1>     -/--/--        LRH             Created
 */


#ifndef RELIGION_H
#define RELIGION_H

#include "enum.h"
#include "ouch.h"
#include "externs.h"

#define MAX_PIETY 200

enum harm_protection_type
{
    HPT_NONE = 0,
    HPT_PRAYING,
    HPT_ANYTIME,
    HPT_PRAYING_PLUS_ANYTIME,
    NUM_HPTS
};

// Calls did_god_conduct() when the object goes out of scope.
struct god_conduct_trigger
{
    conduct_type conduct;
    int pgain;
    bool known;
    bool enabled;
    std::auto_ptr<monsters> victim;

    god_conduct_trigger(conduct_type c = NUM_CONDUCTS,
                        int pg = 0,
                        bool kn = true,
                        const monsters *vict = NULL);

    void set(conduct_type c = NUM_CONDUCTS,
             int pg = 0,
             bool kn = true,
             const monsters *vict = NULL);

    ~god_conduct_trigger();
};

bool is_evil_god(god_type god);
bool is_good_god(god_type god);
bool is_chaotic_god(god_type god);
bool is_lawful_god(god_type god);
bool is_priest_god(god_type god);
void simple_god_message(const char *event, god_type which_deity = you.religion);
int piety_breakpoint(int i);
std::string god_name(god_type which_god, bool long_name = false);
void dec_penance(int val);
void dec_penance(god_type god, int val);

bool did_god_conduct(conduct_type thing_done, int pgain, bool known = true,
                     const monsters *victim = NULL);
void set_attack_conducts(const monsters *mon, god_conduct_trigger& conduct,
                         bool known = true);

void excommunication(god_type new_god = GOD_NO_GOD);
void gain_piety(int pgn);
void god_speaks(god_type god, const char *mesg );
void lose_piety(int pgn);
void offer_corpse(int corpse);
std::string god_prayer_reaction();
void pray();
void handle_god_time(void);
int god_colour(god_type god);
void god_pitch(god_type which_god);
int piety_rank(int piety = -1);
void offer_items();
bool god_hates_your_god(god_type god,
                        god_type your_god = you.religion);
std::string god_hates_your_god_reaction(god_type god,
                                        god_type your_god = you.religion);
bool god_hates_killing(god_type god, const monsters* mon);
bool god_likes_butchery(god_type god);
bool god_hates_butchery(god_type god);
harm_protection_type god_protects_from_harm(god_type god, bool actual = true);
void god_smites_you(god_type god, kill_method_type death_type,
                    const char *message = NULL);
void divine_retribution(god_type god);

bool beogh_water_walk();
void beogh_idol_revenge();
void good_god_holy_attitude_change(monsters *holy);
void beogh_convert_orc(monsters *orc, bool emergency,
                       bool converted_by_follower = false);
bool is_evil_item(const item_def& item);
bool god_dislikes_item_handling(const item_def &item);
bool ely_destroy_weapons();
bool trog_burn_books();
bool tso_unchivalric_attack_safe_monster(const actor *act);

bool is_good_follower(const monsters* mon);
bool is_orcish_follower(const monsters* mon);
bool is_follower(const monsters* mon);
bool bless_follower(monsters *follower = NULL,
                    god_type god = you.religion,
                    bool (*suitable)(const monsters* mon) = is_follower,
                    bool force = false);

bool god_hates_attacking_friend(god_type god, const actor *fr);
bool god_likes_items(god_type god);

#endif
