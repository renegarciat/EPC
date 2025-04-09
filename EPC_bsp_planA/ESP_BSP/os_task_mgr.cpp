#include "os_task_mgr.hpp"

/*Create the objects of all the needed classes*/
#define OS_TASK(classname, InitFunction, TaskFunction, nameForTheTask, StackDepth, priority, periodicity_MS)\
  classname classname##_o;
  DEFINED_OS_TASKS 
#undef OS_TASK

os_task_mgr::os_task_mgr() 
{

}

/*Generation of functions for each task, where the main function will be called periodically depending on the declared period*/
#define OS_TASK(classname, InitFunction, TaskFunction, nameForTheTask, StackDepth, priority, periodicity_MS)\
  void classname##_fun( void * pvParameters )\
  {\
    while(1)\
    {\
      classname##_o.TaskFunction();\
      vTaskDelay(periodicity_MS / portTICK_PERIOD_MS);\
    }\
  }
  DEFINED_OS_TASKS 
#undef OS_TASK

void os_task_mgr::initTasks()
{
#define OS_TASK(classname, InitFunction, TaskFunction, nameForTheTask, StackDepth, priority, periodicity_MS)\
  classname##_o.InitFunction();
  DEFINED_OS_TASKS 
#undef OS_TASK

#define OS_TASK(classname, InitFunction, TaskFunction, nameForTheTask, StackDepth, priority, periodicity_MS)\
  xTaskCreate(classname##_fun, "nameForTheTask", StackDepth, NULL, priority, NULL);
  DEFINED_OS_TASKS 
#undef OS_TASK
  
}