#ifndef OS_TASK_MG_HPP
#define OS_TASK_MG_HPP

#include "gamepad_hdlr.hpp"

#define DEFAULT_STACK_DEPTH              2048

/*Use only these values for task priority*/
#define TASK_PRIORITY_LOW                3       
#define TASK_PRIORITY_NORMAL             10
#define TASK_PRIORITY_CRITICAL           15

/*Prototype needed for the function tasks*/
/*Function main function does not need to be a loop, the main function will be called automatically on the period defined*/
/*void vTaskCode(void)*/

/*Prototype needed for the init function*/
/*void init(void)*/

/*Define all the tasks needed in the system with the following format*/
/*OS_TASK(classname, InitFunction, TaskFunction, "Name for the task", StackDepth, priority, periodicity_MS)*/
#define DEFINED_OS_TASKS \ 
    OS_TASK(gamepad_hdlr, begin, main, "Gamepad handler", DEFAULT_STACK_DEPTH, TASK_PRIORITY_NORMAL, 10) \ 


class os_task_mgr 
{
public:
  os_task_mgr();
  void initTasks();

private:

};

#endif