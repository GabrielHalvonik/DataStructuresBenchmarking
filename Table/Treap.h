#pragma once

#include "BinarySearchTree.h"
#include <random>
#include <iostream>
#include <iostream>

namespace Structures {

	template <typename K, typename T>
	class TreapItem : public TableItem<K, T> {
	public:
		TreapItem(K key, T data, int priority);

		int getPriority();
		void minimizePriority();
	private:
		int priority;
	};

	template <typename K, typename T>
    class Treap : public BinarySearchTree<K, T> {
	public:
		Treap();
		Treap(const Treap<K, T>& other);
		~Treap();

		Structure* clone() const override;

		BinarySearchTree<K, T>& operator=(const BinarySearchTree<K, T>& other) override;
		virtual Treap<K, T>& operator=(const Treap<K, T>& other);

		void insert(const K& key, const T& data) override;
		T remove(const K& key) override;

	private:
		std::default_random_engine* generator;

		bool isHeapOK(BinaryTreeNode<TableItem<K, T>*>* node);

		int extractPriority(BinaryTreeNode<TableItem<K, T>*>* node);
		void rotateLeftOverParent(BinaryTreeNode<TableItem<K, T>*>* node);
		void rotateRightOverParent(BinaryTreeNode<TableItem<K, T>*>* node);
	};

	template<typename K, typename T>
	inline TreapItem<K, T>::TreapItem(K key, T data, int priority): TableItem<K, T>(key, data), priority(priority) {
	}

	template<typename K, typename T>
	inline int TreapItem<K, T>::getPriority() {
		return priority;
	}

	template<typename K, typename T>
	inline void TreapItem<K, T>::minimizePriority() {
		priority = INT_MAX;
	}

	template<typename K, typename T>
	inline Treap<K, T>::Treap() : BinarySearchTree<K, T>(), generator(new std::default_random_engine()) {
	}

	template<typename K, typename T>
	inline Treap<K, T>::Treap(const Treap<K, T>& other) : Treap() {
		*this = other;
	}

	template<typename K, typename T>
	inline Treap<K, T>::~Treap() {
		delete this->generator;
		this->generator = nullptr;
	}

	template<typename K, typename T>
	inline Structure * Treap<K, T>::clone() const {
		return new Treap<K, T>(*this);
	}

	template<typename K, typename T>
	inline BinarySearchTree<K, T>& Treap<K, T>::operator=(const BinarySearchTree<K, T>& other) {
		return *this = dynamic_cast<const Treap<K, T>&>(other);
	}

	template<typename K, typename T>
	inline Treap<K, T>& Treap<K, T>::operator=(const Treap<K, T>& other) {
		if (this != &other) {
			BinarySearchTree<K, T>::operator=(other);
			*this->generator = (*other.generator);
		}
		return *this;
	}

	template<typename K, typename T>
	inline void Treap<K, T>::insert(const K& key, const T& data) {
		std::cout << "INSERT" << std::endl;
		int priority = (*generator)();
		TreapItem<K, T>* newItem = new TreapItem<K, T>(key, data, priority);
		BinaryTreeNode<TableItem<K, T>*>* node = new BinaryTreeNode<TableItem<K, T>*>(newItem);
		if (this->tryToInsertNode(node)) {
			BinaryTreeNode<TableItem<K, T>*>* parent = node->getParent();
			while (!this->isHeapOK(node)) {
				if (node->isLeftSon()) {
					this->rotateRightOverParent(node);
				} else {
					this->rotateLeftOverParent(node);
				}
				parent = node->getParent();
			}
			++this->size_;
		} else {
			delete newItem;
			delete node;
			throw std::logic_error("Treap<K, T>::insert...table already contains key.");
		}
	}

	template<typename K, typename T>
	inline T Treap<K, T>::remove(const K& key) {

	}

	template<typename K, typename T>
	inline bool Treap<K, T>::isHeapOK(BinaryTreeNode<TableItem<K, T>*>* node) {
		std::cout << "ISHEAPOK" << std::endl;
		if (node != nullptr) {

		int nodePriority = extractPriority(node);
		int parentPriority = extractPriority(node->getParent());
		int leftSonPriority = extractPriority(node->getLeftSon());
		int rightSonPriority = extractPriority(node->getRightSon());

		return (parentPriority <= nodePriority &&
			nodePriority <= (leftSonPriority >= 0 ? leftSonPriority : INT_MAX) &&
			nodePriority <= (rightSonPriority >= 0 ? rightSonPriority : INT_MAX)) ? true : false;
		} else {
			return true;
		}
	}

	template<typename K, typename T>
	inline int Treap<K, T>::extractPriority(BinaryTreeNode<TableItem<K, T>*>* node) {
		return node != nullptr ? dynamic_cast<TreapItem<K, T>*>(node->accessData())->getPriority() : -1;
	}

	template<typename K, typename T>
	inline void Treap<K, T>::rotateLeftOverParent(BinaryTreeNode<TableItem<K, T>*>* node) {
		if (node->isRightSon()) {
			BinaryTreeNode<TableItem<K, T>*>* parent = node->getParent();
			BinaryTreeNode<TableItem<K, T>*>* left = node->changeLeftSon(nullptr);
			BinaryTreeNode<TableItem<K, T>*>* grandParent = parent->getParent();
			parent->setRightSon(nullptr);

			if (grandParent != nullptr) {
				if (parent->isLeftSon()) {
					grandParent->setLeftSon(node);
				} else {
					grandParent->setRightSon(node);
				}
			}
			node->setLeftSon(parent);
			parent->setRightSon(left);
		}
	}

	template<typename K, typename T>
	inline void Treap<K, T>::rotateRightOverParent(BinaryTreeNode<TableItem<K, T>*>* node) {
		if (node->isRightSon()) {
			BinaryTreeNode<TableItem<K, T>*>* parent = node->getParent();
			BinaryTreeNode<TableItem<K, T>*>* right = node->changeRightSon(nullptr);
			BinaryTreeNode<TableItem<K, T>*>* grandParent = parent->getParent();
			parent->setLeftSon(nullptr);

			if (grandParent != nullptr) {
				if (parent->isRightSon()) {
					grandParent->setRightSon(node);
				} else {
					grandParent->setLeftSon(node);
				}
			}
			node->setRightSon(parent);
			parent->setLeftSon(right);
		}
	}
}
