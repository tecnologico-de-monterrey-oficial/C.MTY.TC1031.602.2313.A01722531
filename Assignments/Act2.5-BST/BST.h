#ifndef BST_h
#define BST_h

#include "Node.h"
#include <queue>
#include <stack>


template <class T>
class BST {
private:
    Node<T>* root;
    void printTree(Node<T>* aux, int level);

public:
    BST();
    void insert(T data);
    bool remove(T data);
    void print();
    bool find(T data);
    void visit(int method);
    int height();
    void ancestors(T data);
    int whatLevelamI(T data);
    bool isEmpty();
};

template <class T>
BST<T>::BST() {
    root = nullptr;
}


template <class T>
void BST<T>::insert(T data) {
    if (isEmpty()) {
        root = new Node<T>(data);
    } else {
        Node<T>* aux = root;
        while (aux != nullptr) {
            if (data < aux->data) {
                if (aux->left == nullptr) {
                    aux->left = new Node<T>(data);
                    return;
                } else {
                    aux = aux->left;
                }
            } else {
                if (aux->right == nullptr) {
                    aux->right = new Node<T>(data);
                    return;
                } else {
                    aux = aux->right;
                }
            }
        }
    }
}

template <class T>
bool BST<T>::remove(T data) {
    Node<T>* auxFather = root;
    Node<T>* aux = root;
    bool found = false;
    while (!found) {
        if (data == aux->data) {
            found = true;
        } else {
            auxFather = aux;
            data < aux->data ? aux = aux->left : aux = aux->right;
            if (aux == nullptr) {
                return false;
            }
        }
    }
    int numChildren = children(aux);
    if (numChildren == 0) {
        if (aux == root) {
            root = nullptr;
            aux->data < auxFather->data ? auxFather-> left = nullptr : auxFather-> right = nullptr;
        }
        delete aux;
    }
    if (numChildren == 1) {
        if (aux == root) {
            aux->left != nullptr ? root = aux->left : root = aux->right;
        } else {
            if (data < auxFather->data) {
                aux->left != nullptr ? auxFather->left = aux->left : auxFather->left = aux->right;
            } else {                    
                aux->left != nullptr ? auxFather->right = aux->left : auxFather->right = aux->right;
            }
        }
        delete aux;
    }
    if (numChildren == 2) {
        if (aux->left->right == nullptr) {
            aux->data = aux->left->data;
            Node<T>* auxRemove = aux->left;
            aux->left = aux->left->left;
            delete auxRemove;
        } else {
            auxFather = aux->left;
            Node<T>* auxChild = auxFather->right;
            while (auxChild->right != nullptr) {
                auxFather = auxChild;
                auxChild = auxChild->right;
            }
            aux->data = auxChild->data;
            auxFather->right = auxChild->left;
            delete auxChild;
        }
    }
    return true;
}

template<class T>
void BST<T>::print() {
    if (!isEmpty()) {
        int level = 0;
        cout << endl;
        printTree(root, level);
        cout << endl;
    } else {
        cout << endl << "el BST está vacío" << endl << endl;
    }
} 


template <class T>
bool BST<T>::find(T data) {
    Node<T>* aux = root;
    while (aux != nullptr) {
        if (data == aux->data) {
            return true;
        } else {
            data < aux->data ? aux = aux->left : aux = aux->right;
        }
    }
    return false;
}

template <class T>
void BST<T>::visit(int method) {
    
    if (method == 1) {
        cout << endl << "pre order: " << endl;
        Node<T>* aux = root;
        stack<Node<T>*> s;
        s.push(aux);
        while (!s.empty()) {
            aux = s.top();
            s.pop();
            cout << aux->data << " ";
            if (aux->right != nullptr) {
                s.push(aux->right);
            }
            if (aux->left != nullptr) {
                s.push(aux->left);
            }
        }
        cout << endl;
    }
    if (method == 2) {
        cout << endl << "in order:" << endl;
        Node<T>* aux = root;
        stack<Node<T>*> s;
        while (aux != nullptr || !s.empty()) {
            while (aux != nullptr) {
                s.push(aux);
                aux = aux->left;
            }
            aux = s.top();
            s.pop();
            cout << aux->data << " ";
            aux = aux->right;
        }
        cout << endl;
    }
    if (method == 3) {
        cout << endl << "post order: " << endl;
        Node<T>* aux = root;
        stack<Node<T>*> s1;
        stack<Node<T>*> s2;
        s1.push(aux);
        while (!s1.empty()) {
            aux = s1.top();
            s1.pop();
            s2.push(aux);
            if (aux->left != nullptr) {
                s1.push(aux->left);
            }
            if (aux->right != nullptr) {
                s1.push(aux->right);
            }
        }
        while (!s2.empty()) {
            aux = s2.top();
            s2.pop();
            cout << aux->data << " ";
        }
        cout << endl;
    }
    if (method == 4) {
        cout << endl << " level by level: " << endl;
        Node<T>* aux = root;
        queue<Node<T>*> q;
        q.push(aux);
        while (!q.empty()) {
            aux = q.front();
            q.pop();
            cout << aux->data << " ";
            if (aux->left != nullptr) {
                q.push(aux->left);
            }
            if (aux->right != nullptr) {
                q.push(aux->right);
            }
        }
        cout << endl;
    }
}

template <class T>
int BST<T>::height() {
    Node<T>* aux = root;
    queue<Node<T>*> q;
    q.push(aux);
    int height = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size > 0) {
            aux = q.front();
            q.pop();
            if (aux->left != nullptr) {
                q.push(aux->left);
            }
            if (aux->right != nullptr) {
                q.push(aux->right);
            }
            size--;
        }
        height++;
    }
    return height;
}

template <class T>
void BST<T>::ancestors(T data) {
    Node<T>* aux = root;
    stack<Node<T>*> s;
    while (aux != nullptr) {
        if (data == aux->data) {
            break;
        } else {
            s.push(aux);
            data < aux->data ? aux = aux->left : aux = aux->right;
        }
    }
    while (!s.empty()) {
        aux = s.top();
        s.pop();
        cout << aux->data << " ";
    }
    cout << endl;
}

template <class T>
int BST<T>::whatLevelamI(T data) {
    Node<T>* aux = root;
    int level = 0;
    while (aux != nullptr) {
        if (data == aux->data) {
            return level;
        } else {
            level++;
            data < aux->data ? aux = aux->left : aux = aux->right;
        }
    }
    return -1;
}


template<class T>
void BST<T>::printTree(Node<T>* aux, int level) {
    if (aux != NULL) {
        printTree(aux->right,level+1);
        for (int i=0;i<level;i++) {
            cout << "  ";
        }
        cout << aux->data << endl;
        printTree(aux->left,level+1);
    }
}


template <class T>
int children(Node<T>* aux) {
    if (aux->left == nullptr && aux->right == nullptr) {
        return 0;
    }
    if (aux->left != nullptr && aux->right != nullptr) {
        return 2;
    }
    return 1;
}

template <class T>
bool BST<T>::isEmpty() {
    return root == nullptr;
}


#endif 