/*
File name: BinarySearchTree.cpp
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #5
Date: 10/3/2020
*/

template <typename ItemType, typename KeyType>
BinarySearchTree<ItemType,KeyType>::BinarySearchTree()
{
    m_root = nullptr;
}

template <typename ItemType, typename KeyType>
BinarySearchTree<ItemType,KeyType>::BinarySearchTree(BinarySearchTree<ItemType,KeyType>* tree)
{
    m_root = nullptr;
    copy(tree->getRoot());
}

template <typename ItemType, typename KeyType>
void BinarySearchTree<ItemType,KeyType>::copy(BinaryNode<ItemType>* subtree)
{
    if (subtree == nullptr)
    {
        return;
    }
    try
    {
        ItemType temp = subtree->getEntry();
        add(temp);
    }
    catch(const std::runtime_error& rte)
    {
        rte.what();
    }
    copy(subtree->getLeft());
    copy(subtree->getRight());
}

template <typename ItemType, typename KeyType>
BinarySearchTree<ItemType,KeyType>::~BinarySearchTree()
{
    clear();
}

template <typename ItemType, typename KeyType>
BinaryNode<ItemType>* BinarySearchTree<ItemType,KeyType>::getRoot()
{
    return m_root;
}

template <typename ItemType, typename KeyType>
void BinarySearchTree<ItemType,KeyType>::add(ItemType entry)
{
    if (m_root == nullptr)
    {
        m_root = new BinaryNode<ItemType>(entry);
    }
    else
    {
        try
        {
            recAdd(entry, m_root);
        }
        catch (std::runtime_error& rte)
        {
            throw (std::runtime_error(rte.what()));
        }
    }
}

template <typename ItemType, typename KeyType>
void BinarySearchTree<ItemType,KeyType>::recAdd(ItemType entry, BinaryNode<ItemType>* subtree)
{
    if (subtree->getEntry() == entry)
    {
        throw(std::runtime_error("ERROR: Cannot add existing value\n"));
    }
    else if (subtree->getEntry() > entry)
    {
        if (subtree->getLeft() == nullptr)
        {
            BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(entry);
            subtree->setLeft(newNodePtr);
        }
        else
        {
            recAdd(entry,subtree->getLeft());
        }
    }
    else
    {
        if (subtree->getRight() == nullptr)
        {
            BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(entry);
            subtree->setRight(newNodePtr);
        }
        else
        {
            recAdd(entry,subtree->getRight());
        }
    }
    
}

template <typename ItemType, typename KeyType>
ItemType BinarySearchTree<ItemType,KeyType>::search(KeyType key) const
{
    try
    {
        return (recSearch(key,m_root));
    }
    catch (std::runtime_error& rte)
    {
        throw (std::runtime_error(rte.what()));
    }
}

template <typename ItemType, typename KeyType>
ItemType BinarySearchTree<ItemType,KeyType>::recSearch(KeyType key, BinaryNode<ItemType>* subtree) const
{
    if (subtree == nullptr)
    {
        throw(std::runtime_error("ERROR: Given value is not present in Binary Search Tree\n"));
    }
    else if (subtree->getEntry()==key)
    {
        return (subtree->getEntry());
    }
    else if (subtree->getEntry() > key)
    {
        try
        {
            return(recSearch(key,subtree->getLeft()));
        }
        catch(const std::runtime_error& rte)
        {
            throw(std::runtime_error(rte.what()));
        }
    }
    else
    {
        try
        {
            return(recSearch(key,subtree->getRight()));
        }
        catch(const std::runtime_error& rte)
        {
            throw(std::runtime_error(rte.what()));
        }
    }
}

template <typename ItemType, typename KeyType>
void BinarySearchTree<ItemType,KeyType>::clear()
{
    recClear(m_root);
}

template <typename ItemType, typename KeyType>
void BinarySearchTree<ItemType,KeyType>::recClear(BinaryNode<ItemType>* subtree)
{
    if (subtree == nullptr)
    {
        return;
    }
    else
    {
        recClear(subtree->getLeft());
        recClear(subtree->getRight());
        delete subtree;
        subtree = nullptr;
    }
}

template <typename ItemType, typename KeyType>
void BinarySearchTree<ItemType,KeyType>::visitPostOrder(void visit(ItemType)) const
{
    visitPost(visit,m_root);
}

template <typename ItemType, typename KeyType>
void BinarySearchTree<ItemType,KeyType>::visitPost(void visit(ItemType), BinaryNode<ItemType>* subtree) const
{
    if (subtree == nullptr)
    {
        return;
    }
    visitPost(visit,subtree->getLeft());
    visitPost(visit,subtree->getRight());
    visit(subtree->getEntry());
}

template <typename ItemType, typename KeyType>
void BinarySearchTree<ItemType,KeyType>::visitPreOrder(void visit(ItemType)) const
{
    visitPre(visit,m_root);
}

template <typename ItemType, typename KeyType>
void BinarySearchTree<ItemType,KeyType>::visitPre(void visit(ItemType), BinaryNode<ItemType>* subtree) const
{
    if (subtree == nullptr)
    {
        return;
    }
    visit(subtree->getEntry());
    visitPre(visit,subtree->getLeft());
    visitPre(visit,subtree->getRight());
}

template <typename ItemType, typename KeyType>
void BinarySearchTree<ItemType,KeyType>::visitInOrder(void visit(ItemType)) const
{
    visitIn(visit,m_root);
}

template <typename ItemType, typename KeyType>
void BinarySearchTree<ItemType,KeyType>::visitIn(void visit(ItemType), BinaryNode<ItemType>* subtree) const
{
    if (subtree == nullptr)
    {
        return;
    }
    visitIn(visit,subtree->getLeft());
    visit(subtree->getEntry());
    visitIn(visit,subtree->getRight());
}

template <typename ItemType, typename KeyType>
bool BinarySearchTree<ItemType,KeyType>::booleanSearch(KeyType target) const
{
    return(booleanRecSearch(target,m_root));
}

template <typename ItemType, typename KeyType>
bool BinarySearchTree<ItemType,KeyType>::booleanRecSearch(KeyType target, BinaryNode<ItemType>* subtree) const
{
    if(subtree == nullptr)
    {
        return(false);
    }
    else if (subtree->getEntry()==target)
    {
        return(true);
    }
    else if (subtree->getEntry() > target)
    {
        return (booleanRecSearch(target,subtree->getLeft()));
    }
    else
    {
        return(booleanRecSearch(target,subtree->getRight()));
    }
}

template <typename ItemType, typename KeyType>
void BinarySearchTree<ItemType,KeyType>::remove(KeyType key)
{
    if (m_root->getEntry() == key)
    {
        delete removeHelper(m_root, m_root, 'n');
    }
    else if (m_root->getEntry() > key)
    {
        try
        {
            removeFinder(key, m_root, m_root->getLeft(),'l');
        }
        catch(std::runtime_error& rte)
        {
            std::cout << rte.what();
        }
    }
    else
    {
        try
        {
            removeFinder(key,m_root, m_root->getRight(), 'r');
        }
        catch(std::runtime_error& rte)
        {
            std::cout << rte.what();
        }
    }
    
}

template <typename ItemType, typename KeyType>
BinaryNode<ItemType>* BinarySearchTree<ItemType,KeyType>::removeHelper(BinaryNode<ItemType>* prevSubtree,
                                                         BinaryNode<ItemType>* currSubtree, char direction)
{
    if (currSubtree->getRight() == nullptr && currSubtree->getLeft() == nullptr)
    {
        if (direction == 'l')
        {
            prevSubtree->setLeft(nullptr);
        }
        else if (direction == 'r')
        {
            prevSubtree->setRight(nullptr);
        }
        return currSubtree;
    
    }
    else if (currSubtree->getRight() == nullptr && currSubtree->getLeft() != nullptr)
    {
        if (direction == 'l')
        {
            prevSubtree->setLeft(currSubtree->getLeft());
            return currSubtree;
        }
        else if (direction == 'r')
        {
            prevSubtree->setRight(currSubtree->getLeft());
            return currSubtree;
        }
        else
        {
            BinaryNode<ItemType>* placeHolder = currSubtree;
            currSubtree = currSubtree->getLeft();
            return placeHolder;
        }
    }
    else if (currSubtree->getRight() != nullptr && currSubtree->getLeft() == nullptr)
    {
        if (direction == 'l')
        {
            prevSubtree->setLeft(currSubtree->getRight());
            return currSubtree;
        }
        else if (direction == 'r')
        {
            prevSubtree->setRight(currSubtree->getRight());
            return currSubtree;
        }
        else
        {
            BinaryNode<ItemType>* placeHolder = currSubtree;
            currSubtree = currSubtree->getRight();
            return placeHolder;
        }
    }
    else
    {
        if (direction == 'l')
        {
            prevSubtree->setLeft(leftMostFinder(currSubtree,currSubtree->getRight()));
            return currSubtree;
        }
        else if (direction == 'r')
        {
            prevSubtree->setRight(leftMostFinder(currSubtree,currSubtree->getRight()));
            return currSubtree;
        }
        else
        {
            BinaryNode<ItemType>* placeHolder = currSubtree;
            currSubtree = leftMostFinder(currSubtree, currSubtree->getRight());
            currSubtree->setLeft(placeHolder->getLeft());
            return placeHolder;
        }
    }
}

template <typename ItemType, typename KeyType>
BinaryNode<ItemType>* BinarySearchTree<ItemType,KeyType>::leftMostFinder(BinaryNode<ItemType>* prevSubtree,
                                                         BinaryNode<ItemType>* currSubtree)
{
    if (currSubtree->getLeft() == nullptr)
    {
        return (removeHelper(prevSubtree,currSubtree,'l'));
    }
    else
    {
        return (leftMostFinder(currSubtree, currSubtree->getLeft()));
    }
}

template <typename ItemType, typename KeyType>
void BinarySearchTree<ItemType,KeyType>::removeFinder(KeyType key, BinaryNode<ItemType>* prevSubtree,
                                                         BinaryNode<ItemType>* currSubtree, char direction)
{
    if (currSubtree == nullptr)
    {
        throw(std::runtime_error("ERROR: Given value is not present in Binary Search Tree\n"));
    }
    else if (currSubtree->getEntry()==key)
    {
        delete removeHelper(prevSubtree,currSubtree,direction);
    }
    else if (currSubtree->getEntry() > key)
    {
        try
        {
            removeFinder(key,currSubtree,currSubtree->getLeft(),'l');
        }
        catch(const std::runtime_error& rte)
        {
            throw(std::runtime_error(rte.what()));
        }
    }
    else
    {
        try
        {
            removeFinder(key,currSubtree,currSubtree->getLeft(),'r');
        }
        catch(const std::runtime_error& rte)
        {
            throw(std::runtime_error(rte.what()));
        }
    }
      
}