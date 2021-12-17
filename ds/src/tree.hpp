#pragma once

#include <boost/serialization/access.hpp>
#include <boost/serialization/base_object.hpp>

namespace ymy {

template<typename Value>
class BT;

template<typename Value>
class TreeNode 
{
 public:
    explicit TreeNode(const Value &value) : _value(value) {}
    void setValue(const Value &value) { _value = value; }
    const Value& getValue() const { return _value; }
 private:
    friend class boost::serialization::access;
    template <typename Archive>
    void serialize(Archive &ar, const unsigned int version) 
    {
        ar & _value;
    }

 private:
    Value _value;
};

template<typename Value>
class BtNode : public TreeNode<Value>
{
 public:
    BtNode<Value> (const Value &value, BtNode<Value> *lhs = nullptr, BtNode<Value> *rhs = nullptr) : 
        TreeNode<Value>(value), _l(lhs), _r(rhs) 
    {}
    void setRhs(BtNode<Value> *rhs) { _r = rhs; }
    void setLhs(BtNode<Value> *lhs) { _l = lhs; }
    BtNode<Value>* getRhs() const { return _r; }
    BtNode<Value>* getLhs() const { return _l; }

 private:
    friend class boost::serialization::access;
    template <typename Archive>
    void serialize(Archive &ar, const unsigned int version) 
    {
        ar & boost::serialization::base_object<TreeNode>(*this);
        ar & _l;
        ar & _r;
    }

 private:
    // one to one friend
    friend class BT<Value>;
    BtNode<Value> *_l;
    BtNode<Value> *_r;
};

template<typename Value>
class BT
{
 private:
    friend class boost::serialization::access;

    template <typename Archive>
    void recurSerialize(Archive &ar, BtNode<Value> *node) 
    {
        if (!node) return;
        ar & node;
        recurSerialize(ar, node->_l);
        recurSerialize(ar, node->_r);
    }

    template <typename Archive>
    void serialize(Archive &ar, const unsigned int version) 
    {
        ar & _root;
    }

    void deleteTree(BtNode<Value> *node) 
    {
        if (!node) return;
        deleteTree(node->getLhs());
        deleteTree(node->getRhs());
        delete node;
    }
    void copyTree(const BtNode<Value> *from, BtNode<Value> *&to) 
    {
        if (!from) {
            to = from;
        } else {
            to = new BtNode<Value>(*from);
            copyTree(from->getLhs(), to->_l);
            copyTree(from->getRhs(), to->_r);
        }
    }

 public:
    // Rule of 5
    BT() : _root(nullptr) {}
    explicit BT(const BtNode<Value> &root) : _root(root) {}
    ~BT() { deleteTree(_root);}
    BT(const BT &other) { copyTree(other.getRoot(), _root); }
    BT& operator=(const BT &other) 
    { 
        copyTree(other.getRoot(), _root); 
        return *this; 
    }
    BT(BT &&other) 
    {
        _root = other._root;
        other._root = nullptr;
    }
    BT& operator=(BT &&other)
    {
        _root = other._root;
        other._root = nullptr;
        return *this;
    }
    void setRoot(BtNode<Value> *root) { _root = root; }
    BtNode<Value>* getRoot() const { return _root; }
 private:
    BtNode<Value> *_root;
};
}
