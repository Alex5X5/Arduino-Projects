#define MAX_SCHEDULED_TASKS 100 

struct ScheduledTask {
    void (*func)(long);
    long tick;
};

class Scheduler {
  private:
    long currentTick;
    long currentTaskCount;
    ScheduledTask tasks[MAX_SCHEDULED_TASKS];
  
  public:
    Scheduler();

  private:
    void cleanUpFunction(int func);
    
  public:
    long getCurrentTick();
    
    void schedule(void (*func)(long));
    void scheduleAt(void (*func)(long), long tick);
    void scheduleIn(void (*func)(long), long tick);
    void tick();
};
