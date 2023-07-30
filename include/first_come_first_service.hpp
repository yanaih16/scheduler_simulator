#pragma once
#include "schedule.hpp"

class FirstComeFirstService : public Scheduler {
   private:
    queue<task> wait;

   public:
    void start();
};