#include <iostream>
//#include <cstring>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

typedef enum {
    Running,
    Swimming,
    Boxing,
    Basketball,
    Football,
    Cycling,
} Kind_of_sport;

struct Sport_info {
    Kind_of_sport sport;
    int place;
    Sport_info* next;
};

typedef struct tnoded {
    char country_name[20];
    int num_of_sports;
    Sport_info* sports_result;
} info1;

struct tnode {
    info1 info;
    tnode* next;
};

struct Total_count {
    int participating_teams = 0;
    Kind_of_sport sport;
    Total_count* next;
};

typedef tnode* pnode;
typedef Total_count* pTotal_count;

pnode form_list();
void printList(pnode head);
std::string color_place(int place);
void insertSorted(pnode& head, tnode* newNode);
void input_in_sotredtxt_for_func(pnode sortedHead);
pnode input_in_sotredtxt(pnode head);
void formation_of_sub_list(Sport_info* sub_list, int place);
void recOrderList(Sport_info*& sub_list_head, int place);
void recAddBefore(Sport_info*& sub_list_head, int element, int target);
pnode read_from_filetxt(std::string file_name);
void write_type_to_txt(pnode head, int type_of_sport, std::string name_of_file);
pnode removePlayer(pnode* list, char name[]);
void total_number_of_participants(pnode head);
void adding_new_countries(pnode& head);
pTotal_count form_total(pnode head);
void print_small_list(pTotal_count head);
int count_for_pTotal(pnode head, int type_of_sport);
bool compareSportInfo(const Sport_info& a, const Sport_info& b);
void sortSportsResults(tnode* country);
Sport_info* sortSportInfo(Sport_info* head, bool (*compare)(const Sport_info&, const Sport_info&));
void adding_new_competitive_participation(pnode head);
void remove_kind_of_sport(pnode list, char name[]);
void write_type_txt(pnode head);
void sort_sports_results(pnode head);
void country_search_for_write_totxt(pnode head, char name[]);
void search_prizes_places(pnode head);


using namespace std;










