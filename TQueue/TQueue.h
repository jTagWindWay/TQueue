#pragma once
 template <class T>
	 class TQueue {
		 int first;
		 int MaxSize;
		 int Size;
		 int last;
		 T * mas;
	 public:

		 TQueue(int _MaxSize = 20) {                      // онструктор по умолчанию
			 MaxSize = _MaxSize;
			 Size = 0;
			 mas = new T[MaxSize];
			 first = 0;
			 last = -1;
		 }
		                     
		 TQueue(const TQueue & tq) {                       //конструктор копирвоани€
			 MaxSize = tq.MaxSize;
			 Size = tq.Size;
			 mas = new T[MaxSize];
			 for (size_t i = 0; i < Size; i++) {
				 mas[i] = tq.mas[i];
			 }
			 first = tq.first;
			 last = tq.last;
		 }

		 bool isEmpty() {                                  //проверка на пустоту
			 if (Size == 0) return true;
			 else return false;
		 }

		 bool isFull() {
			 if (Size == MaxSize) return true;             //проверка на полноту
			 else return false;
		 }

		 void Push(T a) {                                  //положить элемент в очередь
			 if (isFull()) throw 1;
			 if (last == MaxSize - 1) last = 0;
			 else {
				 last++;
				 mas[last] = a;
				 Size++;
			 }
		 }

		 T Pop() {                                         //вз€ть элемент из очереди
			 if (isEmpty()) throw 2;
			 T a = mas[first];
			 if (first == MaxSize - 1) first = 0;
			 else {
				 first++;
				 Size--;
			 }
		 }

		 T & operator = (const T & tq) {                    //перегрузка оператора присваивани€
			 if (MaxSize != tq.MaxSize) {
				 delete[] mas;
				 MaxSize = tq.MaxSize;
				 Size = tq.Size;
				 mas = new T[MaxSize];
			 }
			 for (size_t i = 0; i < MaxSize; i++) {
				 mas[i] = tq.mas[i];
			 }
			 fitst = tq.first;
			 last = tq.last;
			 return *this;
		 }


 };