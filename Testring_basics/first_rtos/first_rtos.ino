#include <Arduino.h>
#include <FreeRTOSConfig.h>

void Task1(void *pvParameters) {
  for (;;) {
    Serial.println("Task 1 is running");
    vTaskDelay(1000 / portTICK_PERIOD_MS);  // Wait for 1 second
  }
}

void Task2(void *pvParameters) {
  for (;;) {
    Serial.println("Task 2 is running");
    vTaskDelay(2000 / portTICK_PERIOD_MS);  // Wait for 2 seconds
  }
}

void setup() {
  Serial.begin(115200);

  // Create two FreeRTOS tasks
  xTaskCreate(Task1, "Task 1", 1024, NULL, 1, NULL);
  xTaskCreate(Task2, "Task 2", 1024, NULL, 1, NULL);
}

void loop() {
  // No code needed in loop, tasks are running independently
}
