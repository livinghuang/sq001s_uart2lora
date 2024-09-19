#include <Arduino.h>

#define MAX_DATA_SIZE 45
#define QUEUE_SIZE 2000 // Define the size of the queue

// Data structure
struct data_struct
{
  uint32_t timestamp;
  char data[MAX_DATA_SIZE];
};

// uartQueue class for Arduino
class uartQueue
{
private:
  data_struct queueArray[QUEUE_SIZE]; // Statically allocated queue
  int front;
  int rear;
  int count;

public:
  uartQueue()
  {
    front = 0;
    rear = -1;
    count = 0;
  }

  // Add item to the queue
  void enqueue(data_struct data)
  {
    if (count < QUEUE_SIZE)
    {
      rear = (rear + 1) % QUEUE_SIZE;
      queueArray[rear] = data;
      count++;
    }
    else
    {
      Serial.println("uartQueue is full!");
    }
  }

  // Remove and return an item from the queue
  data_struct dequeue()
  {
    if (count > 0)
    {
      data_struct data = queueArray[front];
      front = (front + 1) % QUEUE_SIZE;
      count--;
      return data;
    }
    else
    {
      Serial.println("uartQueue is empty!");
      data_struct emptyData = {0, ""};
      return emptyData;
    }
  }

  // Check if the queue is empty
  bool isEmpty()
  {
    return count == 0;
  }

  // Check if the queue is full
  bool isFull()
  {
    return count == QUEUE_SIZE;
  }

  // Get the current size of the queue
  int size()
  {
    return count;
  }
};

// Instantiate uartQueue object
uartQueue uartQ;

void queue_example()
{
  // Example data
  data_struct data1 = {1629981620, "First message"};
  data_struct data2 = {1629981680, "Second message"};
  data_struct data3 = {1629981740, "Third message"};

  // Enqueue the data
  uartQ.enqueue(data1);
  uartQ.enqueue(data2);
  uartQ.enqueue(data3);

  // Dequeue and print the data
  while (!uartQ.isEmpty())
  {
    data_struct data = uartQ.dequeue();
    Serial.print("Dequeued: ");
    Serial.println(data.data);
  }
}

void uartQ_enqueue(struct data_struct *data)
{
  uartQ.enqueue(*data);
}

struct data_struct uartQ_dequeue()
{
  return uartQ.dequeue();
}

bool uartQ_is_empty()
{
  return uartQ.isEmpty();
}

bool uartQ_is_full()
{
  return uartQ.isFull();
}

int uartQ_size()
{
  return uartQ.size();
}