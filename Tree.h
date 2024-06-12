/*************************************************
 * ADS Praktikum 1.2
 * Tree.h
 * Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
 *************************************************/
#pragma once
#include "TreeNode.h"
#include "catch.h"
#include <string>

using namespace std;

class Tree
{

private:
    ///////////////////////////////////////
    // Ihr Code hier:
    TreeNode* m_anker;
    int m_currentNodeChronologicalID;

    void printPreOrder(TreeNode* ptr);
    void printInOrder();
    void printPostOrder();
    //
    ////////////////////////////////////

public:
    ///////////////////////////////////////
    // Ihr Code hier:
    Tree() : m_currentNodeChronologicalID{ 0 }, m_anker{ nullptr } {}
    ~Tree() { deletetree(m_anker); delete m_anker;}

    void addNode(std::string Name, int Age, double Income, int PostCode);
    bool deleteNode(int NodeOrderID);
    bool searchNode(std::string Name);
    void printAll();
    void levelOrder();
    void getNames(TreeNode* ptr, string Name, bool& found);
    void getOrder(TreeNode* ptr, int NodeOrderID, bool& found);
    bool searchOrder(int NodeOrderID);
    TreeNode* Searchminimum(TreeNode* ptr);
    TreeNode* deletehelpfunction(TreeNode* ptr, int NodeOrderID, bool& found);
    //bool deleteOrderID(int NodeOrderID);
    void deletetree(TreeNode* anker);
    //
    ////////////////////////////////////
    // friend-Funktionen sind für die Tests erforderlich und müssen unangetastet
    // bleiben!
    friend TreeNode* get_anker(Tree& TN);
};
