#include "List.h"

#include <iostream>
#include <string>

/**Constructor with value as parameter, creates list with one element
* with value as in argument*/
List::List(int val) : next(nullptr), value(val)
{}

/**Adding element at the beginning of list*/
List* List::add(int val) {
	if(this->value == -2147483647) {	//if no elements in list
		this->value = val;
		return this;
	} else {
        List *elem = new List(val); /**Adding new element*/
        elem->next = this; /**Defining new head*/
        return elem;    /**Return new head*/
	}

}

/**Adding value at specific index of list*/
List* List::addAtIndex(int val, unsigned int index) {
    /**Checking if index is between 0 and list size*/
	if (index >= this->getSize()) {
		return this->addAtEnd(val);	//if index is greater or equal list's size, value will be added at the list's end
	}
    else {
        List *ptr = this;   /**List's head, 0 element to do stuff on it*/
        List *head = this;  /**Copy of head to be returned*/

        /**0 is list's first element*/
        if(index == 0) return ptr->add(val);   /**Adding at beginning*/

        else {      /**Adding at another place in list*/
            while(index > 1) {
                /**Switching to element before given index (that's why 1 not 0)*/
                ptr = ptr->next;
                index--;
            }
            /**Dividing list at given index*/
            List *tail = ptr->next;

            /**Creating new list element*/
            ptr->next = new List(val);

            /**Switching to created element*/
            ptr = ptr->next;

            /**Adding tail*/
            ptr->next = tail;

            return head;
        }
    }
}

/**Prints list on the standard output*/
void List::print() {
    List *ptr = this;
    while(ptr != NULL) {    /**While there are elements in list*/
        std::cout << ptr->value << " ";
        ptr = ptr->next;
    }
}

/**Adding elements at the end of list*/
List* List::addAtEnd(int val) {
	if(this->value == -2147483647) {	//if no elements in list
		this->value = val;
		return this;
	}
	else {
        List *head = this;
		List *ptr = this->toEnd();  /**Goes to end of list*/
		ptr->next = new List(val);  /**Creates new element on the very end*/
        return head;
	}
}

/**Returns number of elements inside list*/
unsigned int List::getSize() {
    List *ptr = this;
    unsigned int size = 0;
    if(ptr->value == -2147483647 && ptr->next == nullptr) return 0;     /**Checking if list is empty, if true then return 0 as size*/
    else {
        while(ptr->next != nullptr) {
            size++;             /**Counting elements*/
            ptr = ptr->next;
        }
        return size+1;  /**Add one to counted size because counter stops at the last element but its not counted*/
    }
}

/**deletes first element and returns it's value*/
int List::deleteFirst(Structure** head) {
    List *ptr = (List*)*head;    /**Copying head*/
    int value = ptr->value;     /**Getting value that will be returned*/

    if(ptr->next != nullptr) {
        (*head) = ptr->next;    /**Changing head to next element*/
    } else {
        (*head) = nullptr;      /**If last element, than head will be null*/
    }
    delete(ptr);        /**Freeing memory*/

    return value;       /**Returning value*/
}

/**Deletes element at list's end and returns it's value*/
int List::deleteLast() {
    List *newLast = this->toLastButOne();   /**pointing to last but one element*/
    int value;

    if(newLast->next == nullptr) {
        value = newLast->value;
        delete(newLast);
    } else {
        value = newLast->next->value;    /**saving value to be returned*/
        delete(newLast->next);   /**freeing memory*/
        newLast->next = nullptr;    /**new last element*/
    }

    return value;   /**Returning last value*/
}
/**Deletes value at given index*/
int List::deleteAtIndex(unsigned int index, Structure** head) {
	/**Checking if index is between 0 and size*/
	if (index >= this->getSize()) {
		return this->deleteLast(); //if index is greater or equal list's size,  last element will be removed
	}
	else {
		if (index == 0) return this->deleteFirst(head);	//deleting first element
		else {
			List *ptr = (List*)*head;
			int value;
			while (index > 1) {
				ptr = ptr->next;		//skipping to element before the one to be deleted
				index--;
			}
			List *tail = ptr->next->next;	//saving tail
			value = ptr->next->value;	//getting value
			delete(ptr->next);	//deleting list element
			ptr->next = tail;	//adding tail
			return value;
		}
	}
}
/**searches for specific value*/
bool List::findValue(int value) {
    List *ptr = this;
    if(ptr->value == -2147483647) {
        return false;
    } else {
        while(ptr->next != nullptr) {
            if(ptr->value == value) return true;
            else ptr = ptr->next;
        }
        return false;
    }
}

/**Checks if list is empty, depending on the list size*/
bool List::isEmpty() {
    if(this->getSize() == 0) return true;
    else return false;
}

/**return value at specified index*/
int List::get(unsigned int index) {
    if(index >= this->getSize()) {
        return NULL;
    } else {
        List *ptr = this;
        while(index > 0) {
            ptr = ptr->next;
            index--;
        }
        return ptr->value;
    }
}

List::~List()
{

}

/**Goes to the last element on the list*/
List* List::toEnd() {
    List *ptr = this;
    while(ptr->next != nullptr) {
        ptr = ptr->next;
    }
    return ptr;
}

/**Goes to the last but one element on the list*/
List* List::toLastButOne() {
    List *ptr = this;
    if(ptr->next == nullptr) {
        return ptr;
    } else {
        while(ptr->next->next != nullptr) {
            ptr = ptr->next;
        }
        return ptr;
    }
}
