#pragma once
#include "schedule.hpp"

class ShortestProcessingTimeFirst : public Scheduler {
   private:
    deque<task> wait;

   public:
    void start();
};