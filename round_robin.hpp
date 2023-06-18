#pragma once
#include "schedule.hpp"

class RoundRobin : public Scheduler {
   private:
    int slice_time;
    int quantum;
    queue<task> wait;

   public:
    void start();
};