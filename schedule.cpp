#include "schedule.hpp"

Scheduler::Scheduler() {
    time = 0;
    running.status = none;
    cout << "task of num" << endl;
    cin >> task_num;
    for (int i = 0; i < task_num; i++) {
        task t;
        cout << "task name,arriva time,cost" << endl;
        ;
        cin >> t.task_name;
        cin >> t.arrival_time;
        cin >> t.cost;
        create.push_back(t);
    }
    sort(create.begin(), create.end(), [](task& e1, task& e2) { return e1.arrival_time < e2.arrival_time; });
}

void Scheduler::result() {
    cout << "task name|arrival time|finish time|response time" << endl;
    for (auto v : finish) {
        cout << setw(9) << v.task_name << "|"
             << setw(12) << v.arrival_time << "|"
             << setw(11) << v.fin_time << "|"
             << setw(13) << v.fin_time - v.arrival_time << endl;
    }
}
