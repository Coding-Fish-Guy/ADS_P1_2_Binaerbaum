/*************************************************
 * ADS Praktikum 1.2
 * Tree.cpp
 * Erweiterung um Hilfsfunktionen gestattet.
 *************************************************/
#include "Tree.h"
#include "TreeNode.h"
#include <iomanip>
#include <iostream>

using namespace std;

////////////////////////////////////
// Ihr Code hier:
void Tree::addNode(std::string Name, int Age, double Income, int PostCode) {
    int NodeOrderID = Age + (int)Income + PostCode;
    TreeNode* neuer_eintrag = new TreeNode(NodeOrderID, m_currentNodeChronologicalID, Name, Age, Income, PostCode);
    TreeNode* parent = nullptr;
    TreeNode* ptr = m_anker;
    while (ptr != nullptr) {
        parent = ptr;
        if (neuer_eintrag->getNodeOrderID() < ptr->getNodeOrderID())
            ptr = ptr->getLeft();
        else {                                                             // den Baum durchlaufen
            ptr = ptr->getRight();
        }
    }
    if (m_anker == nullptr) {                                                // Leerer Baum
        m_anker = neuer_eintrag;
    }
    else {
        if (neuer_eintrag->getNodeOrderID() < parent->getNodeOrderID()) {       // einzufügender Knoten nach links einfügen
            parent->setLeft(neuer_eintrag);
        }
        else {                                                                  // einzufügender Knoten nach rechts einfügen
            parent->setRight(neuer_eintrag);
        }
    }
    this->m_currentNodeChronologicalID++;
}

void Tree::deletetree(TreeNode* k) {
    if (k != nullptr) {
        deletetree(k->getLeft());
        deletetree(k->getRight());
        delete k;
    }
}

TreeNode* Tree::deletehelpfunction(TreeNode* ptr, int NodeOrderID, bool& found) {
    if (ptr == nullptr) { return ptr; }                                               // leerer Baum
    else if (NodeOrderID < ptr->getNodeOrderID())                                     // wandere nach links
        ptr->setLeft(deletehelpfunction(ptr->getLeft(), NodeOrderID, found));
    else if (NodeOrderID > ptr->getNodeOrderID())                                     // wandere nach rechts
        ptr->setRight(deletehelpfunction(ptr->getRight(), NodeOrderID, found));
    else {
        if (ptr->getLeft() == nullptr && ptr->getRight() == nullptr) {                // zu löschender Knoten ist ein Blattknoten
            delete ptr;
            ptr = nullptr;                                                            // ptr auf NULL zeigen (dangling pointer)
            return ptr;
        }
        else if (ptr->getLeft() == nullptr) {                                           // zu löschender Knoten hat einen rechten Nachfolger
            TreeNode* temp = ptr;
            ptr = ptr->getRight();
            delete temp;
            return ptr;
        }
        else if (ptr->getRight() == nullptr) {                                        // zu löschender Knoten hat einen linken Nachfolger
            TreeNode* temp = ptr;
            ptr = ptr->getLeft();
            delete temp;
            return ptr;
        }
        else if (ptr->getLeft() != nullptr && ptr->getRight() != nullptr) {                          // zu löschender Knoten hat zwei Nachfolger
            TreeNode* minimum = Searchminimum(ptr->getRight());                                      // pointer zeigt auf das Minimum des rechten Teilbaums
            ptr->setNodeOrderID(minimum->getNodeOrderID());                                          // ptr Knoten kriegt NodeOrderID vom zu löschenden Minimum Knoten von ptr
            ptr->setRight(deletehelpfunction(ptr->getRight(), minimum->getNodeOrderID(), found));    // rechter Nachfolger von ptr wird rekursiv gesetzt nach dem Löschen
        }
    }
}

bool Tree::deleteNode(int NodeOrderID) {                                // Methode um Knoten endgültig zu löschen
    bool found = false;
    if (m_anker == nullptr) { return false; }
    else {
        m_anker = deletehelpfunction(m_anker, NodeOrderID, found);
        this->m_currentNodeChronologicalID--;
        return found;
    }
}

TreeNode* Tree::Searchminimum(TreeNode* ptr) {                          // suche Minimum
    while (ptr->getLeft() != nullptr) {
        ptr = ptr->getLeft();
    }
    return ptr;
}

void Tree::getOrder(TreeNode* ptr, int NodeOrderID, bool& found) {         // suche die OrderID und gebe (true) wenn sie existiert und (false) falls nicht
    if (ptr != nullptr) {
        if (ptr->getNodeOrderID() == NodeOrderID) { found = true; }
        if (ptr->getLeft() != nullptr) { getOrder(ptr->getLeft(), NodeOrderID, found); }
        if (ptr->getRight() != nullptr) { getOrder(ptr->getRight(), NodeOrderID, found); }
    }
}

bool Tree::searchOrder(int NodeOrderID) {
    TreeNode* ptr = m_anker;
    bool found = false;
    if (m_anker == nullptr) { return found; }
    getOrder(ptr, NodeOrderID, found);
    return found;
}

void Tree::getNames(TreeNode* ptr, string Name, bool& found) { // Iteriere mit Preorder durch den Baum und suche den Namen der übergeben wird
    if (ptr != nullptr) {
        if (ptr->getName() == Name) {
            found = true;
            cout << "\n+ Fundstellen:\n";
            cout << "ID: " << ptr->getNodeChronologicalID() << ", Name: " << Name << ", Age: " << ptr->getAge() << ", Income: "
                 << ptr->getIncome() << ", PostCode: " << ptr->getPostCode() << ", OrderID: " << ptr->getNodeOrderID() << endl;
        }
        if (ptr->getLeft() != nullptr) { getNames(ptr->getLeft(), Name, found); }
        if (ptr->getRight() != nullptr) { getNames(ptr->getRight(), Name, found); }
    }
}

bool Tree::searchNode(string Name) {
    TreeNode* ptr = m_anker;
    bool found = false;
    if (m_anker == nullptr) { return found; }
    getNames(ptr, Name, found);
    return found;
}

void Tree::printPreOrder(TreeNode* ptr) {
    if (ptr == nullptr) { return; }

    ptr->allprint();
    printPreOrder(ptr->getLeft());
    printPreOrder(ptr->getRight());
}

void Tree::printAll() {
    printPreOrder(m_anker);
}

void Tree::levelOrder() {

}

void Tree::printInOrder() {

}

void Tree::printPostOrder() {

}
//
////////////////////////////////////
