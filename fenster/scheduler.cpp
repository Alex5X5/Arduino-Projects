#include "scheduler.h"

Scheduler::Scheduler() {
  currentTick = 0;
  currentTaskCount = 0;
}

long Scheduler::getCurrentTick(){
  return currentTick;
}

void Scheduler::scheduleAt(void (*func)(long), long tick) {
  if (currentTaskCount >= MAX_SCHEDULED_TASKS)
    return;
  tasks[currentTaskCount] = {func, tick};
  currentTaskCount++;
}

void Scheduler::schedule(void (*func)(long)) {
  scheduleAt(func, currentTick + 1);
}

void Scheduler::scheduleIn(void (*func)(long), long tick) {
  scheduleAt(func, currentTick + tick);
}

void Scheduler::cleanUpFunction(int func) {
  if(func == 0){
    currentTaskCount--;
    return;
  }
  if(func == currentTaskCount - 1) {
    currentTaskCount--; 
    return;
  }
  tasks[func] = tasks[currentTaskCount - 1];
  currentTaskCount--; 
}

void Scheduler::tick() {
    currentTick++;
    for (int i = 0; i < currentTaskCount; i++) {
        if (tasks[i].tick == currentTick) {
            tasks[i].func(currentTick);
            cleanUpFunction(i);
        }
    }
}
