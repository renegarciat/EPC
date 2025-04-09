#include "os_task_mgr.hpp"

os_task_mgr os_task_mgr_o; 

void setup() {
  Serial.begin(115200);
  os_task_mgr_o.initTasks();
}

void loop() 
{
}
