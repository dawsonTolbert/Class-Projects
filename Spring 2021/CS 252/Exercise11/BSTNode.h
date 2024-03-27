#ifndef BSTNODE_H
#define BSTNODE_H

class BSTNode{
private:
    int info;
    BSTNode* left;
    BSTNode* right;

public:
    BSTNode(int info, BSTNode* left, BSTNode* right){
        this->info = info;
        this->left = left;
        this->right = right;
    }

    void setInfo(int info){
        this->info = info;
    }

    int getInfo(){
        return info;
    }

    void setLeft(BSTNode* left){
        this->left = left;
    }

    BSTNode* getLeft(){
        return left;
    }

    void setRight(BSTNode* right){
        this->right = right;
    }

    BSTNode* getRight(){
        return right;
    }

};

#endif // BSTNODE_H
