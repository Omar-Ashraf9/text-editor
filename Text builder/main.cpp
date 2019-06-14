#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>
using namespace std;
class BSTnode
{
public:
    string data;
    vector<int> linesAppear;
    BSTnode* left;
    BSTnode* right;
    BSTnode()
    {
        left = right = NULL;
    }
    BSTnode(const string &word,int appearance)
    {
        data = word;
        linesAppear.push_back(appearance);
        left = right = NULL;
    }
};
class BSTFCI
{
public:
    BSTnode* root;
    BSTFCI();
    void add(string ToBST,int lineAppear);
    BSTnode* Insert(BSTnode* node,string ToBST,int lineAppear);
    void print_inOrder(BSTnode* node);
    friend void modify(string& input);
};
BSTFCI::BSTFCI()
{
    root = NULL;
}
BSTnode* BSTFCI::Insert(BSTnode* node,string ToBST,int lineAppear)
{
    if(node == NULL)
    {
        return new BSTnode(ToBST,lineAppear);
    }
    if(ToBST > node->data)
    {
        node->right = Insert(node->right,ToBST,lineAppear);
    }
    else if(ToBST < node->data)
    {
        node->left = Insert(node->left,ToBST,lineAppear);
    }
    else
    {
        node->linesAppear.push_back(lineAppear);
    }
    return node;

}
void BSTFCI::add(string ToBST,int lineAppear)
{
    root = Insert(root,ToBST,lineAppear);
}
void modify(string& input)
{
        input.erase(std::remove(input.begin(), input.end(), '!'), input.end());
        input.erase(std::remove(input.begin(), input.end(), '"'), input.end());
        input.erase(std::remove(input.begin(), input.end(), '#'), input.end());
        input.erase(std::remove(input.begin(), input.end(), '$'), input.end());
        input.erase(std::remove(input.begin(), input.end(), '%'), input.end());
        input.erase(std::remove(input.begin(), input.end(), '&'), input.end());
        input.erase(std::remove(input.begin(), input.end(), '('), input.end());
        input.erase(std::remove(input.begin(), input.end(), ')'), input.end());
        input.erase(std::remove(input.begin(), input.end(), '*'), input.end());
        input.erase(std::remove(input.begin(), input.end(), '+'), input.end());
        input.erase(std::remove(input.begin(), input.end(), ','), input.end());
        input.erase(std::remove(input.begin(), input.end(), '-'), input.end());
        input.erase(std::remove(input.begin(), input.end(), '.'), input.end());
        input.erase(std::remove(input.begin(), input.end(), '/'), input.end());
        input.erase(std::remove(input.begin(), input.end(), ':'), input.end());
        input.erase(std::remove(input.begin(), input.end(), ';'), input.end());
        input.erase(std::remove(input.begin(), input.end(), '?'), input.end());
        input.erase(std::remove(input.begin(), input.end(), '@'), input.end());
        input.erase(std::remove(input.begin(), input.end(), '['), input.end());
        input.erase(std::remove(input.begin(), input.end(), ']'), input.end());
        input.erase(std::remove(input.begin(), input.end(), '^'), input.end());
        input.erase(std::remove(input.begin(), input.end(), '_'), input.end());
        input.erase(std::remove(input.begin(), input.end(), '`'), input.end());
        input.erase(std::remove(input.begin(), input.end(), '{'), input.end());
        input.erase(std::remove(input.begin(), input.end(), '}'), input.end());
        input.erase(std::remove(input.begin(), input.end(), '|'), input.end());
        input.erase(std::remove(input.begin(), input.end(), '~'), input.end());
}
void BSTFCI::print_inOrder(BSTnode* node)
{
    if(node != NULL)
    {
        if(node->left != NULL)
        {
            print_inOrder(node->left);
        }
        cout << "-------------------------------------------"<< endl;
        cout << node->data << " ";

        for(int i = 0; i < node->linesAppear.size(); i++)
        {
            cout <<"\t\t\t\t"<< setw(5) << node->linesAppear[i] << " ";

            cout << endl;
        }
        if(node->right != NULL)
        {
            print_inOrder(node->right);
        }

    }else{
        cout << "The tree is empty!" << endl;
    }
}

int main()
{
    cout << "Enter sentences as you want, when you finish, write (done) -without parentheses-: " << endl;
    BSTFCI o;
    string input,ToBST;
    int lineAppear = 0;
    while(getline(cin,input))
    {
        if(input == "done")
        {
            break;
        }
        modify(input);
        lineAppear++;
        istringstream convert(input);
        while(convert >> ToBST)
        {
            o.add(ToBST,lineAppear);
        }
    }
    cout << "The indices for each word in your input is: " << endl;
    cout << endl;
    cout << "words: " << "\t\t\t\t" << "lines: " << endl;
    o.print_inOrder(o.root);

    return 0;
}



/*****************************************************************************************************************************
 The algorithm goes like this:                                                                                               *
                                                                                                                             *
 first , the user enter the sentences as much as possible until the entered word is "done".                                  *
 modify function remove the punctuation from the entered word.                                                               *
 after that,we use "istringstream" which give us an stream contain the string values can i assign it to any data type        *
 in this case i passed the value to string because this is the required.                                                     *
                                                                                                                             *
*****************************************************************************************************************************/
/********************************************
 To illustrate the istringstream benefit:   *
                                            *
  string values = "122 123 124 125";        *
    istringstream convert(values);          *
    for(int i = 0; i < 4; i++)              *
    {                                       *
        int val;                            *
        convert >> val;                     *
        cout << val*2 << " ";               *
    }                                       *
********************************************/





