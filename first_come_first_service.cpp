#include "first_come_first_service.hpp"

void FirstComeFirstService::run() {
    while (finish.size() != task_num) {
        cout << "time:" << time << endl;
        if (!create.empty() && create.front().arrival_time == time) {
            wait.push(create.front());
            wait.pop();
        }
    }
}