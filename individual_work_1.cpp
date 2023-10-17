/*
Є набір текстових файлів.У першому міститься інформація про країни -
учасниці спортивної олімпіади у вигляді набору рядків, у кожному з яких

– назва країни та перелік видів спорту, в яких вона бере участь.Інші файли
(їх стільки, скільки видів спорту) – це результати змагань : кожен
називається назвою виду спорту і містить перелік країн у порядку
зайнятих ними місць у цьому виді спорту.Потрібно створити 1) список
видів спорту із зазначенням загальної кількості команд - учасниць; 2)
список списків : список країн в алфавітному порядку та для кожної країни
список видів спорту та зайнятого місця у цьому виді спорту,
впорядкований за зростанням місць. Забезпечити операції додавання,
видалення, редагування та розумного пошуку інформації в обох списках,
а також виведення інформації в розумному вигляді (наприклад, країна, вид
спорту та зайняте місце із загальної кількості команд у цьому виді спорту).
*/

#include"list.h"




int main() {
    pnode head = nullptr;
    pnode head_for_add = nullptr;
    pTotal_count small = nullptr;
    char name[20];
    
    int choice;
    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Country formation" << std::endl;
        std::cout << "2. Print country formation" << std::endl;
        std::cout << "3. Print of competition participants" << std::endl;
        std::cout << "4. Read from file txt and sort him" << std::endl;
        std::cout << "5. Delete country" << std::endl;
        std::cout << "6. Adding new countries" << std::endl;
        std::cout << "7. Adding new competitive participation" << std::endl;
        std::cout << "8. Remove kind of sport" << std::endl;
        std::cout << "9. Find country by name for write to txt file" << std::endl;
        std::cout << "10. Write to file prizes places" << std::endl;
        std::cout << "11. Exit" << std::endl;
        std::cout << "Select the option: ";

        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Country formation" << std::endl;
            head = form_list();
            input_in_sotredtxt(head);
            write_type_txt(head);
            total_number_of_participants(head);
            cout << "\n\n";
            break;
        case 2:
            std::cout << "Print country formation" << std::endl;
            head = read_from_filetxt("sorted_list.txt");
            printList(head);
            total_number_of_participants(head);
            cout << "\n\n";
            break;
        case 3:
            std::cout << "Print of competition participants" << std::endl;
            head = read_from_filetxt("sorted_list.txt");
            small = form_total(head);
            print_small_list(small);
            input_in_sotredtxt(head);
            total_number_of_participants(head);
            cout << "\n\n";
            break;
        case 4:
            head = read_from_filetxt("sorted_list.txt");
            sort_sports_results(head);
            input_in_sotredtxt(head);
            write_type_txt(head);
            printList(head);
            total_number_of_participants(head);
            cout << "\n\n";
            break;
        case 5:
            std::cout << "Delete country: " << std::endl;
            
            std::cout << "Which country you need delete: " << std::endl;
            cin >> name;
            head = read_from_filetxt("sorted_list.txt");
            removePlayer(&head, name);
            input_in_sotredtxt(head);
            write_type_txt(head);
            total_number_of_participants(head);
            cout << "\n\n";
            break;
        case 6:
            std::cout << "Which country you need adding: " << std::endl;
            head = read_from_filetxt("sorted_list.txt");
            adding_new_countries(head);
            input_in_sotredtxt(head);
            write_type_txt(head);
            total_number_of_participants(head);
            cout << "\n\n";
            break;
        case 7:
            std::cout << "Which country you adding competitive participation" << std::endl;
            head = read_from_filetxt("sorted_list.txt");
            adding_new_competitive_participation(head);
            sort_sports_results(head);
            input_in_sotredtxt(head);
            write_type_txt(head);
            total_number_of_participants(head);
            cout << "\n\n";
            break;
        case 8:
            std::cout << " " << std::endl;
            head = read_from_filetxt("sorted_list.txt");
            cout << "In which country: ";
            cin >> name;
            remove_kind_of_sport(head, name);
            input_in_sotredtxt(head);
            write_type_txt(head);
            printList(head);
            total_number_of_participants(head);
            cout << "\n\n";
            break;
        case 9:
            std::cout << " " << std::endl;
            head = read_from_filetxt("sorted_list.txt");
            cout << "Which country: ";
            cin >> name;
            country_search_for_write_totxt(head, name);
            input_in_sotredtxt(head);
            write_type_txt(head);
            total_number_of_participants(head);
            cout << "\n\n";

            break;
        case 10:
            std::cout << " " << std::endl;
            head = read_from_filetxt("sorted_list.txt");
            input_in_sotredtxt(head);
            total_number_of_participants(head);
            cout << "\n\n";
            search_prizes_places(head);

            break;
        case 11:
            cout << "\n" << "Thanks for using our software";
            return 0;
            break;
        default:
            cout << "Wrong choice. Try again." << std::endl;
        }

    } while (choice != '11');


    return 0;
}










































/*
void less5times(pnode list) {
    cout << endl;
    cout << "Players with less than five goals:" << endl;
    int flag = 0;

    while (list != nullptr) {
        if (list->info.goals < 5) {
            list = printList(list);
            flag = 1;
        }
        else {
            list = list->next;
        }
    }
    if (flag == 0) {
        cout << "There were no players with less than five goals" << endl;
    }
}

void bestForward(pnode list) {
    pnode best = nullptr;

    cout << endl;
    cout << "Best Forward:" << endl;
    int flag = 0;

    while (list != nullptr) {

        if (list->info.goals > flag && list->info.player_position == 5) {
            flag = list->info.goals;
            best = list;

        }
        list = list->next;

    }

    if (best == nullptr) {
        cout << "Program dont have a best forward" << endl;
        return;
    }

    printList(best);

}

pnode inputList(pnode list) {
    pnode cur;
    cur = new tnode;
    cout << "NewName: ";
    cin >> cur->info.surname;

    cout << "Age: ";
    cin >> cur->info.age;

    cout << "Number of games: ";
    cin >> cur->info.number_of_game;

    cout << "Goals: ";
    cin >> cur->info.goals;

    cout << "Position (0 for Goalkeeper, 1 for Defender, 2 for Sweeper, 3 for Midfielder, 4 for Centre_midfield, 5 for Forward): ";
    int positionInput;
    cin >> positionInput;
    cur->info.player_position = static_cast<position>(positionInput);

    return cur;
}

pnode preddd(pnode list, char surname[]) {
    pnode cur = nullptr, prev = nullptr, newNode = nullptr;;

    if (!(list))
        return 0;

    if ((strcmp(list->info.surname, surname) == 0)) {
        cur = inputList(cur);

        cur->next = list;


        return cur;
    }
    else {
        prev = list;
        cur = list->next;


        while (cur) {
            if (strcmp(cur->info.surname, surname) == 0) {
                newNode = inputList(newNode);

                newNode->next = cur;
                prev->next = newNode;

                return list;
            }
            else {
                prev = cur;
                cur = cur->next;
            }
        }
        return list;
    }
}

pnode after(pnode list, char name[]) {
    pnode cur, prev, newNode;

    if (!(list))
        return 0;
    if ((strcmp(list->info.surname, name) == 0)) {
        cur = new tnode;

        cout << "NewName: ";
        cin >> cur->info.surname;

        cout << "Age: ";
        cin >> cur->info.age;

        cout << "Number of games: ";
        cin >> cur->info.number_of_game;

        cout << "Goals: ";
        cin >> cur->info.goals;

        cout << "Position (0 for Goalkeeper, 1 for Defender, 2 for Sweeper, 3 for Midfielder, 4 for Centre_midfield, 5 for Forward): ";
        int positionInput;
        cin >> positionInput;
        cur->info.player_position = static_cast<position>(positionInput);

        cur->next = list->next;
        list->next = cur; // По этому вопрос задай?
        return list;
    }
    else {
        prev = list;
        cur = list->next;


        while (cur) {
            if (strcmp(cur->info.surname, name) == 0) {
                newNode = new tnode;
                cout << "NewName: ";
                cin >> newNode->info.surname;

                cout << "Age: ";
                cin >> newNode->info.age;

                cout << "Number of games: ";
                cin >> newNode->info.number_of_game;

                cout << "Goals: ";
                cin >> newNode->info.goals;

                cout << "Position (0 for Goalkeeper, 1 for Defender, 2 for Sweeper, 3 for Midfielder, 4 for Centre_midfield, 5 for Forward): ";
                int positionInput;
                cin >> positionInput;
                newNode->info.player_position = static_cast<position>(positionInput);

                newNode->next = cur->next;
                cur->next = newNode;

                prev->next = cur;
                return list;


            }
            else {
                prev = cur;
                cur = cur->next;
            }
        }
        return list;
    }
}

pnode removePlayer(pnode* list, char name[]) {
    pnode cur, prev, uninstallingNode;

    if (!(*list))
        return 0;
    if ((strcmp((*list)->info.surname, name) == 0)) {

        cur = *list;
        *list = (*list)->next;

        delete cur;

        return *list;
    }
    else {
        prev = *list;
        cur = (*list)->next;


        while (cur) {
            if (strcmp(cur->info.surname, name) == 0) {

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



*/
