/*************************************************
 * ADS Praktikum 1.2
 * TreeNode.cpp
 * Erweiterung um Hilfsfunktionen gestattet.
 *************************************************/
#include "TreeNode.h"
#include <iostream>
#include <string>
#include <iomanip>

////////////////////////////////////
// Ihr Code hier:
void TreeNode::print() const {
    cout << "ID: " << this->getNodeChronologicalID() << ", Name :" << this->getName() << ", Age : " << this->getAge() << ", Income : "
         << this->getIncome() << ", PostCode : " << this->getPostCode() << ", OrderID : " << this->getNodeOrderID() << endl;
}

void TreeNode::allprint() const {
    cout << this->getNodeChronologicalID() << setw(15) << this->getName() << setw(7) << this->getAge() << setw(9)
         << this->getIncome() << setw(10) << this->getPostCode() << setw(13) << this->getNodeOrderID() << endl;
}
//
////////////////////////////////////
