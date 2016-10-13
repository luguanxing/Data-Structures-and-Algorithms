#ifndef EXTENDED_QUEUE_H
#define EXTENDED_QUEUE_H

#define MAX 100

typedef int Error_code;
#define success 0
#define overflow 1
#define underflow 2
#define fail 3



class Extend_queue {
	public:
		int count, front, rear;
		Plane entry[MAX];

		Extend_queue() {
			count = front = 0;
			rear = MAX -1;
		}
		bool empty() {
			return count == 0;
		}
		Error_code append(const Plane &item) {
			if (count >= MAX)
				return overflow;
			count++;
			rear = ((rear+1) == MAX) ? 0 : (rear+1);
			entry[rear] = item;
			return success;
		}
		Error_code serve() {
			if (count <= 0)
				return underflow;
			count--;
			front = ((front+1) == MAX) ? 0 : (front+1);
			return success;
		}
		Error_code retrieve(Plane &item) const {
			if (count <= 0)
				return underflow;
			item = entry[front];
			return success;
		}
		int size()const {
            return count;
         }
        ~Extend_queue() {
           while(count)
				serve();
         }
};
#endif
