#include"list.h"



void search_prizes_places(pnode head) {
    if (!head) {
        return;
    }
    pnode current = head;
    Sport_info* sport_result = nullptr;
    int max = 3;
  
    ofstream outputFile("Best prizes places.txt");
    if (outputFile.is_open()) {
        current = head;
        while (current) {
            sport_result = current->info.sports_result;
            if ( sport_result != nullptr && sport_result->place <= max) {
                outputFile << "Name of country: " << current->info.country_name << "\n";

                while (sport_result) {

                    if (sport_result->place <= max) {

                        outputFile << "Sport: ";
                        switch (sport_result->sport) {
                        case Running:
                            outputFile << "running - ";
                            break;
                        case Swimming:
                            outputFile << "swimming - ";
                            break;
                        case Boxing:
                            outputFile << "boxing - ";
                            break;
                        case Basketball:
                            outputFile << "basketball - ";
                            break;
                        case Football:
                            outputFile << "football - ";
                            break;
                        case Cycling:
                            outputFile << "cycling - ";
                            break;
                        default:
                            outputFile << "sport not identified - ";
                        }
                        outputFile << sport_result->place << " place." << "\n";


                    }
                    sport_result = sport_result->next;
                }
                outputFile << "\n";
            }
            
            current = current->next;

        }
        
    }

}

void country_search_for_write_totxt(pnode head, char name[]) {
    string for_copy_name;
    bool flag = false;
    pnode current = head;
    if (!head) {
        return;
    }
    while (current) {
        if (strcmp(current->info.country_name, name) == 0) {
            for_copy_name = name;
            flag = true;
            break;
        }
        current = current->next;
    }
    if (!flag) {
        cout << "\nCountry not found\n";
        return;
    }
    
    ofstream outputFile(for_copy_name + ".txt");
    if (outputFile.is_open()) {
        Sport_info* sport_result = nullptr;
        
        while (current != nullptr) {
            if (strcmp(current->info.country_name, name) == 0) {
                outputFile << "Name of country: " << current->info.country_name << "\n";
                sport_result = current->info.sports_result;

                while (sport_result != nullptr) {
                    outputFile << "Sport: ";
                    switch (sport_result->sport) {
                    case Running:
                        outputFile << "running - ";
                        break;
                    case Swimming:
                        outputFile << "swimming - ";
                        break;
                    case Boxing:
                        outputFile << "boxing - ";
                        break;
                    case Basketball:
                        outputFile << "basketball - ";
                        break;
                    case Football:
                        outputFile << "football - ";
                        break;
                    case Cycling:
                        outputFile << "cycling - ";
                        break;
                    default:
                        outputFile << "sport not identified - ";
                    }
                    outputFile << sport_result->place << " place." << "\n";
                    sport_result = sport_result->next;
                    outputFile << "\n";
                }
            }
            current = current->next;
        }
            

    }
        outputFile.close();
}




void sort_sports_results(pnode head) {
    tnode* current = head;
    while (current != nullptr) {
        sortSportsResults(current);
        current = current->next;
    }
    current = head;
}


void write_type_txt(pnode head) {
    write_type_to_txt(head, 0, "running.txt");
    write_type_to_txt(head, 1, "swimming.txt");
    write_type_to_txt(head, 2, "boxing.txt");
    write_type_to_txt(head, 3, "basketball.txt");
    write_type_to_txt(head, 4, "football.txt");
    write_type_to_txt(head, 5, "cycling.txt");
}


void remove_kind_of_sport(pnode list, char name[]) {
    
    int answer;
    cout << "Enter the sport in which this country no longer participates."
        "\n\n\x1B[44mPosition(0 for Running, 1 for Swimming, 2 for Boxing, 3 for Basketball, 4 for Football, 5 for Cycling):\x1B[0m:";
    cin >> answer;
    while (list) {
        if (strcmp(list->info.country_name, name) == 0) {
            Sport_info* sport_result = list->info.sports_result;
            Sport_info* prev = nullptr;

            if (sport_result != nullptr && sport_result->sport == answer) {
                list->info.sports_result = sport_result->next;
                delete sport_result;
                return;
            }
            else {
                while (sport_result != nullptr) {
                    if (sport_result->sport == answer) {
                        Sport_info* uninstallingNode;
                        uninstallingNode = sport_result;
                        prev->next = sport_result->next;
                        delete uninstallingNode;
                        return;
                    }
                    prev = sport_result;
                    sport_result = sport_result->next;
                }
            }
            return;
        }
        list = list->next;
    }
    return;  
}


bool compareSportInfo(const Sport_info& a, const Sport_info& b) {
    return a.place > b.place;
}



void sortSportsResults(pnode country) {
    if (country == nullptr || country->info.sports_result == nullptr) {
        return;
    }

    country->info.sports_result = sortSportInfo(country->info.sports_result, compareSportInfo);
}


Sport_info* sortSportInfo(Sport_info* head, bool (*compare)(const Sport_info&, const Sport_info&)) {
    std::vector<Sport_info> results;

    Sport_info* current = head;
    while (current != nullptr) {
        results.push_back(*current);
        current = current->next;
    }

    std::sort(results.begin(), results.end(), compare);

    Sport_info* new_head = nullptr;
    for (const Sport_info& result : results) {
        Sport_info* new_node = new Sport_info(result);
        new_node->next = new_head;
        new_head = new_node;
    }

    return new_head;
}



void adding_new_competitive_participation(pnode head) {

    Sport_info* sport_result = nullptr;
    int place = 0;
    char answer[20];
    cout << "In which country began to participate in the new sport: ";
    cin >> answer;

    while (head) {
        if (strcmp(head->info.country_name, answer) == 0) {
            sport_result = head->info.sports_result;
            while (sport_result->next) {
                sport_result = sport_result->next;
            }
            cout << "Input place: ";
            cin >> place;
            sport_result->next = new Sport_info;
            formation_of_sub_list(sport_result->next, place);
            sport_result->next->next = nullptr;
            break;
        }
        head = head->next;
    }
}

void print_small_list(pTotal_count head) {
    if (!head) {
        cout << "    Probleeeeeemmmmm!!!!!!   ";
        return;
    }

    int i = 0;
    Sport_info* sport_result = nullptr;
    while (head != nullptr) {
        cout << "\n\n\x1B[32mCount counries : \x1B[0m" << head->participating_teams << " ";
        
        
        switch (head->sport) {
        case Running:
            cout << "Running" << "\n\n";
            break;
        case Swimming:
            cout << "Swimming" << "\n\n";
            break;
        case Boxing:
            cout << "Boxing" << "\n\n";
            break;
        case Basketball:
            cout << "Basketball" << "\n\n";
            break;
        case Football:
            cout << "Football" << "\n\n";
            break;
        case Cycling:
            cout << "Cycling" << "\n\n";
            break;
        default:
            cout << "Sport not identified" << "\n\n";
        }

        head = head->next;
        i++;
    }

}


int count_for_pTotal(pnode head, int type_of_sport) {
    

    Sport_info* sport_result = nullptr;
    pnode current = head;
    int count_ = 0;
    while (current) {
        sport_result = current->info.sports_result;
        while (sport_result) {
            if (sport_result->sport == type_of_sport) {
                count_++;
            }
            sport_result = sport_result->next;
        }
        current = current->next;
    }

    return count_;
}


pTotal_count form_total(pnode head) {
    pTotal_count shead = nullptr;
    pTotal_count for_return_shead = nullptr;
    pnode for_tracer_head;
    Sport_info* sports_result = nullptr;
    int type_of_sport = 0;

    shead = new Total_count;
    for_return_shead = shead;
    for_tracer_head = head;
    sports_result = for_tracer_head->info.sports_result;

    while (type_of_sport <= 5) {
        if (type_of_sport == 0) {
            shead->sport = Running;
            shead->participating_teams = count_for_pTotal(head, type_of_sport);
        }
        if (type_of_sport == 1) {
            shead->sport = Swimming;
            shead->participating_teams = count_for_pTotal(head, type_of_sport);
        }
        if (type_of_sport == 2) {
            shead->sport = Boxing;
            shead->participating_teams = count_for_pTotal(head, type_of_sport);
        }
        if (type_of_sport == 3) {
            shead->sport = Basketball;
            shead->participating_teams = count_for_pTotal(head, type_of_sport);
        }
        if (type_of_sport == 4) {
            shead->sport = Football;
            shead->participating_teams = count_for_pTotal(head, type_of_sport);
        }
        if (type_of_sport == 5) {
            shead->sport = Cycling;
            shead->participating_teams = count_for_pTotal(head, type_of_sport);
            shead->next = nullptr;
            break;
        }
        shead->next = new Total_count;
        shead = shead->next;
        type_of_sport++;
    }
    
    return for_return_shead;
}


void adding_new_countries(pnode& head) {
    if (!head) {
        head = form_list();
        return;
    }
    pnode new_head = nullptr;
    pnode last_country = nullptr;
    last_country = head;
    while (last_country->next) {
        last_country = last_country->next;
    }
    last_country->next = form_list();
    head = input_in_sotredtxt(head);

}


void total_number_of_participants(pnode head) {
    ofstream outputFile("The_total_number_of_participants.txt");
    if (outputFile.is_open()) {
        Sport_info* sport_result = nullptr;
        pnode current = head;
        int total_country = 0;
        while (current != nullptr) {
            if (!current->info.sports_result) {
                current = current->next;
                continue;
            }
            outputFile << "Name of country: " << current->info.country_name << "\n";
            current->info.sports_result;
            total_country++;
            outputFile << "\n";
            current = current->next;
        }
        outputFile << "\n";
        outputFile << "The total number of participants: " << total_country;
      
        outputFile.close();
        cout << "The total number of participants has been written." << endl;
    }
    else {
        cout << "Unable to open file 'The_total_number_of_participants.txt' for writing." << endl;
    }
}


pnode removePlayer(pnode* list, char name[]) {
    pnode cur, prev, uninstallingNode;

    if (!(*list))
        return 0;
    if ((strcmp((*list)->info.country_name, name) == 0)) {

        cur = *list;
        *list = (*list)->next;

        delete cur;

        return *list;
    }
    else {
        prev = *list;
        cur = (*list)->next;


        while (cur) {
            if (strcmp(cur->info.country_name, name) == 0) {
                cout << "Flaggg";
                uninstallingNode = cur;
                cur = cur->next;

                prev->next = cur;

                delete uninstallingNode;

                return (*list);


            }
            else {
                prev = cur;
                cur = cur->next;
            }
        }
        return (*list);
    }
}


pnode input_in_sotredtxt(pnode head) {
    if (head != nullptr && head->next != nullptr) {
        pnode sortedHead = nullptr;
        tnode* current = head;

        while (current != nullptr) {
            tnode* next = current->next;
            current->next = nullptr;
            //sort_sports_results(current);
            insertSorted(sortedHead, current);
            current = next;
        }
        std::cout << "Sorting was successful" << endl;
        input_in_sotredtxt_for_func(sortedHead);
        return sortedHead;
    }
    return nullptr; 
}


void write_type_to_txt(pnode head, int type_of_sport, std::string name_of_file) {
    int max = 0;
    int count_to_max = 0;
    pnode current = head;
    Sport_info* sport_result = nullptr;
    while (current != nullptr) {
        sport_result = current->info.sports_result;
        while (sport_result != nullptr) {
            if (sport_result->sport == type_of_sport && sport_result->place > max) {
                max = sport_result->place;
            }
            sport_result = sport_result->next;
        }
        current = current->next;
    }
    ofstream outputFile(name_of_file);
    if (outputFile.is_open()) {

        while (count_to_max <= max) {
            count_to_max++;
            current = head;
            while (current != nullptr) {
                sport_result = current->info.sports_result;
                
                while (sport_result != nullptr) {
                    if (sport_result->sport == type_of_sport && sport_result->place == count_to_max) {
                        outputFile << "Name of country: " << current->info.country_name << "\n";
                        outputFile << sport_result->place << " place." << "\n\n";
                    }
                    sport_result = sport_result->next;
                }

                current = current->next;
            }
        }
        outputFile.close();
    }
    else {
        cout << "Unable to open file for writing." << endl;
    }
}


pnode read_from_filetxt(std::string file_name) {
    pnode cur, next_head = nullptr, head;
    Sport_info* cur_sport = nullptr;

    string old_country_name = "@@@-<1><1><4>-@@@1";
    string country_name;
    string sport_name;
    int place_no;

    std::ifstream file(file_name);
    if (!file.is_open()) {
        std::cerr << "Error opening file" << endl;
        return nullptr;
    }
    std::string line;
    getline(file, line);
    if (line.find("Name of country:") == string::npos) {
        return nullptr;
    }
    head = new tnode;
    cur = head;
    cur->next = nullptr;



    while (file.good()) {


        if (line.find("Name of country:") != string::npos) {
            // Extract country name
            country_name = line.substr(17);

            if (old_country_name != "@@@-<1><1><4>-@@@1") {
                cur->next = new tnode;
                cur = cur->next;
                cur->next = nullptr;
            }

            strcpy_s(cur->info.country_name, country_name.c_str());
            cur->info.country_name[country_name.size() > 19 ? 19 : country_name.size()] = '\0';
            cur->info.num_of_sports = 0;
            cur->info.sports_result = nullptr;
        }
        else if (line.find("Sport:") != string::npos) {
            // Extract sport name and place
            sport_name = line.substr(7, line.find(" -") - 7);
            place_no = stoi(line.substr(line.find("-") + 2, line.find("place.") - 2));

            if (country_name != old_country_name) {
                old_country_name = country_name;
                cur_sport = new Sport_info;
                cur_sport->next = nullptr;
                cur->info.sports_result = cur_sport;
            }
            else {
                cur_sport->next = new Sport_info;
                cur_sport = cur_sport->next;
                cur_sport->next = nullptr;
            }

            cur->info.num_of_sports += 1;

            cur_sport->place = place_no;
            if (sport_name == "running")
                cur_sport->sport = Running;
            else if (sport_name == "swimming")
                cur_sport->sport = Swimming;
            else if (sport_name == "boxing")
                cur_sport->sport = Boxing;
            else if (sport_name == "basketball")
                cur_sport->sport = Basketball;
            else if (sport_name == "football")
                cur_sport->sport = Football;
            else if (sport_name == "cycling")
                cur_sport->sport = Cycling;
        }

        getline(file, line);
    }

    file.close();
    return head;
}


void input_in_sotredtxt_for_func(pnode sortedHead) {
    ofstream outputFile("sorted_list.txt");
    if (outputFile.is_open()) {
        Sport_info* sport_result = nullptr;
        pnode current = sortedHead;
        while (current != nullptr) {
            outputFile << "Name of country: " << current->info.country_name << "\n";
            sport_result = current->info.sports_result;

            while (sport_result != nullptr) {
                outputFile << "Sport: ";
                switch (sport_result->sport) {
                case Running:
                    outputFile << "running - ";
                    break;
                case Swimming:
                    outputFile << "swimming - ";
                    break;
                case Boxing:
                    outputFile << "boxing - ";
                    break;
                case Basketball:
                    outputFile << "basketball - ";
                    break;
                case Football:
                    outputFile << "football - ";
                    break;
                case Cycling:
                    outputFile << "cycling - ";
                    break;
                default:
                    outputFile << "sport not identified - ";
                }
                outputFile << sport_result->place << " place." << "\n";
                sport_result = sport_result->next;
            }
            outputFile << "\n";
            current = current->next;
        }
        outputFile.close();
        cout << "Sorted list has been written to 'sorted_list.txt'" << endl;
    }
    else {
        cout << "Unable to open file for writing." << endl;
    }
}


void insertSorted(pnode& head, tnode* newNode) {
    if (head == nullptr || std::strcmp(newNode->info.country_name, head->info.country_name) < 0) {
        newNode->next = head;
        head = newNode;
    }
    else {
        tnode* current = head;
        while (current->next != nullptr && std::strcmp(newNode->info.country_name, current->next->info.country_name) > 0) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}


void formation_of_sub_list(Sport_info* sub_list, int place) {
    int positionInput;

    cout << "\n\n\x1B[44mPosition (0 for Running, 1 for Swimming, 2 for Boxing, 3 for Basketball, 4 for Football, 5 for Cycling): \x1B[0m" << endl;
    cin >> positionInput;
    sub_list->sport = static_cast<Kind_of_sport>(positionInput);
    sub_list->place = place;
}


void formOrderList(Sport_info*& sub_list_head, int num_of_sports) {
    if (num_of_sports <= 0) {
        sub_list_head = nullptr;
        return;
    }
    int place;
    cout << "Input place in func ";
    cin >> place;
    formation_of_sub_list(sub_list_head, place);
    sub_list_head->next = nullptr;

    while (num_of_sports - 1) {
        cout << "Place: ";
        cin >> place;
        recOrderList(sub_list_head, place);
        num_of_sports--;
    }

}


void recOrderList(Sport_info*& sub_list_head, int place) {
    if (!sub_list_head) {
        sub_list_head = new Sport_info;
        formation_of_sub_list(sub_list_head, place);
        sub_list_head->next = nullptr;
        return;
    }
    if (sub_list_head->place >= place) {
        recAddBefore(sub_list_head, place, sub_list_head->place);
        return;
    }
    recOrderList(sub_list_head->next, place);
}


void recAddBefore(Sport_info*& sub_list_head, int element, int target) {
    if (!sub_list_head)
        return;
    if (sub_list_head->place == target) {
        Sport_info* newNode = new Sport_info;
        formation_of_sub_list(newNode, element);
        newNode->next = sub_list_head;
        sub_list_head = newNode;
        return;
    }
    recAddBefore(sub_list_head->next, element, target);
}


pnode form_list() {
    pnode cur, next_head, head;
    Sport_info* cur_sport = nullptr;
    int tracer = 0;

    cout << "\n\n\x1B[44mHow many countries do you have in competitions?: \x1B[0m" << endl;
    int count;
    cin >> count;

    if (count == 0) {
        cout << "\x1B[31mNo countries\x1B[0m" << endl;
        return nullptr;
    }
    head = new tnode;
    cur = head;

    while (count) {
        tracer++;

        cout << "\n\n\x1B[44mName of country: \x1B[0m" << endl;
        cin >> cur->info.country_name;

        cout << "\n\n\x1B[44mNumber of sports in which the country participates?\x1B[0m" << endl;
        cin >> cur->info.num_of_sports;

        cur_sport = new Sport_info;
        formOrderList(cur_sport, cur->info.num_of_sports);
        cur->info.sports_result = cur_sport;


        if (count == tracer) {
            cur->next = nullptr;
            return head;
        }
        else {
            next_head = new tnode;
            cur->next = next_head;
            cur = next_head;
        }
    }

    return head;
}


std::string color_place(int place) {
    switch (place) {
    case 1:
        return "\033[38;2;255;215;0mplace: \033[0m";
    case 2:
        return "\033[38;2;128;128;128mplace: \033[0m";
    case 3:
        return "\033[38;2;205;127;50mplace: \033[0m";
    default:
        return "\033[38;2;192;192;192mplace: \033[0m";
    }
}


void printList(pnode head) {
    Sport_info* sport_result = nullptr;
    while (head != nullptr) {
        cout << "\n\n\x1B[32mName of country: \x1B[0m" << head->info.country_name << "\n\n";
        sport_result = head->info.sports_result;
        while (sport_result != nullptr) {
            switch (sport_result->sport) {
            case Running:
                cout << "Running - ";
                break;
            case Swimming:
                cout << "Swimming - ";
                break;
            case Boxing:
                cout << "Boxing - ";
                break;
            case Basketball:
                cout << "Basketball - ";
                break;
            case Football:
                cout << "Football - ";
                break;
            case Cycling:
                cout << "Cycling - ";
                break;
            default:
                cout << "Sport not identified - ";
            }

            cout << color_place(sport_result->place) << sport_result->place << endl;
            sport_result = sport_result->next;
        }
        head = head->next;
    }
}
