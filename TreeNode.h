/*************************************************
 * ADS Praktikum 1.2
 * TreeNode.h
 * Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
 *************************************************/
#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class TreeNode
{

private:
    ///////////////////////////////////////
    // Ihr Code hier:
    int m_NodeOrderID = 0;
    int m_NodeChronologicalID = 0;
    std::string m_Name;
    int m_Age = 0;
    double m_Income = 0;
    int m_PostCode = 0;
    TreeNode* m_left = nullptr;
    TreeNode* m_right = nullptr;
    //
    ////////////////////////////////////

public:
    ///////////////////////////////////////
    // Ihr Code hier:
    TreeNode(int NodeOrderID, int NodeChronologicalID, std::string Name, int Age, double Income, int PostCode) :
            m_NodeOrderID{ NodeOrderID }, m_NodeChronologicalID{ NodeChronologicalID }, m_Name{ Name }, m_Age{ Age }, m_Income{ Income }, m_PostCode{ PostCode } {}
    int getNodeOrderID() const { return this->m_NodeOrderID; }
    void setNodeOrderID(int NodeOrderID) { this->m_NodeOrderID = NodeOrderID; }
    int getNodeChronologicalID() const { return this->m_NodeChronologicalID; }
    void setNodeChronologicalID(int NodeChronologicalID) { this->m_NodeChronologicalID = NodeChronologicalID; }
    std::string getName() const { return this->m_Name; }
    void setName(std::string Name) { this->m_Name = Name; }
    int getAge() const { return this->m_Age; }
    void setAge(int Age) { this->m_Age = Age; }
    double getIncome() const { return this->m_Income; }
    void setIncome(double Income) { this->m_Income = Income; }
    int getPostCode() const { return this->m_PostCode; }
    void setPostCode(int PostCode) { this->m_PostCode = PostCode; }
    TreeNode* getLeft() { return this->m_left; }
    void setLeft(TreeNode* left) { this->m_left = left; }
    TreeNode* getRight() { return this->m_right; }
    void setRight(TreeNode* right) { this->m_right = right; }
    void print() const;
    void allprint() const;

    //
    ////////////////////////////////////
};
