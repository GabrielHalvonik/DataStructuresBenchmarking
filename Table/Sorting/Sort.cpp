#include "Sort.h"

Structures::SortNotifier::SortNotifier(int notificationPeriod): notificationPeriod(notificationPeriod), currentNotification(0) {
}

void Structures::SortNotifier::notify() {
		this->currentNotification++;
		if (this->currentNotification == this->notificationPeriod) {
			this->doNotify();
			this->currentNotification = 0;
        }
}
