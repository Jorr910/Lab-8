#include <iostream>

using namespace std;

struct nodo {
    int dato;
    nodo *subLeft;
    nodo *subRight;
  
};

nodo *tree = NULL;

class BinarySearchTree{
    private:
        nodo *pBinarySearchTree;
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        void menu(void);
        void insertar(void);
        void insertarBST(nodo **, int);
        void showPreorder(nodo *);
        void showInorder(void);
        void showIn(nodo *);
        void showPost(nodo *);
        void showPostOrder(void);
        void showPreorder(void);
        void showPre(nodo *);
        bool search(nodo *tree, int n);
        
};

BinarySearchTree::BinarySearchTree(void)
{
    pBinarySearchTree = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
    cout << "Program Execution" << endl;
}

void BinarySearchTree::insertar(void)
{
    int dato;
    char resp;

        cout << "Elemento que desea ingresar: ";
        cin >> dato;
        insertarBST(&pBinarySearchTree, dato);
}

void BinarySearchTree::insertarBST(nodo **p, int dato)
{
    if(!(*p)){
        *p = new nodo;
        (*p)->dato = dato;
        (*p)->subLeft = NULL;
        (*p)->subRight = NULL; 
    }
    else{
        if(dato < (*p)->dato)
            insertarBST(&((*p)->subLeft), dato);
        else
            if(dato > (*p)->dato)
                insertarBST(&((*p)->subRight), dato);
            else
                cout << "El dato ya esta ingresado" << endl << endl;
    }
}

void BinarySearchTree::showInorder(void)
{
    showIn(pBinarySearchTree);
}

void BinarySearchTree::showIn(nodo *p)
{
    if(p){
        showIn(p->subLeft);
        cout << p->dato << " ";
        showIn(p->subRight);
    }
}

void BinarySearchTree::showPreorder(void)
{
    showPre(pBinarySearchTree);
}

void BinarySearchTree::showPre(nodo *p)
{
    if(p){
        cout << p->dato << " ";
        showPre(p->subLeft);
        showPre(p->subRight);
    }
}

void BinarySearchTree::showPostOrder(void)
{
    showPost(pBinarySearchTree);
}

void BinarySearchTree::showPost(nodo *p)
{
    if(p)
    {
        showPost(p->subLeft);
        showPost(p->subRight);
        cout << p->dato << " ";
    }
}

bool BinarySearchTree::search(nodo *tree, int n){
    if(!tree)
        return false;
    else if(tree->dato == n)
        return true;
    else if(n < tree->dato)
        return search(tree->subLeft, n);
    else
        return search(tree->subRight, n);
}

// ------------- 

struct nodo *minValueNode(struct nodo *Nodo)
{

    struct nodo *current = Nodo;

    while (current && current->subLeft != NULL)
        current = current->subLeft;

    return current;
}

nodo *borrarNodo(nodo *root, int key)
{
 
    if (root == NULL)
        return root;
    if (key < root->dato)
        root->subLeft = borrarNodo(root->subLeft, key);
    else if (key > root->dato)
        root->subRight = borrarNodo(root->subRight, key);
    else
    {
        if (root->subLeft == NULL)
        {
            struct nodo *temp = root->subRight;
            free(root);
            return temp;
        }
        else if (root->subRight == NULL)
        {
            struct nodo *temp = root->subLeft;
            free(root);
            return temp;
        }
     
        struct nodo *temp = minValueNode(root->subRight);
     
        root->dato = temp->dato;
    
        root->subRight = borrarNodo(root->subRight, temp->dato);
    }
    return root;
    
}
void BinarySearchTree::menu(void){
    bool op = false, count = false;
    int busqueda = 0, eliminar = 0, opcion = 0;
    do{
        
        cout << "\tMENU" << endl;
        cout << "1 - Insertar nodo" << endl;
        cout << "2 - Mostrar Pre-orden" << endl;
        cout << "3 - Mostrar post-orden" << endl;
        cout << "4 - Mostrar In-orden" << endl;
        cout << "5 - Buscar" << endl;
        cout << "6 - Eliminar valor" << endl;
        cout << "7 - Salir" << endl;
        
        cout << "Tu opcion: "; cin >> opcion;

        switch(opcion){
            case 1:
         
                cout << "Insertar datos en el arbol:" <<  endl;
                insertar();
                break;
            case 2:
                cout << "Mostrar Pre-orden: " << endl;
                showPreorder();
                cout << endl;
                break;
            case 3:
                cout << "Mostrar Post-orden: " << endl;
                showPostOrder();
                cout << endl;
                break;
            case 4:
                cout << "Mostrar In-Orden: " << endl;
                showInorder();
                cout << endl;
                break;
            case 5:
                
                cout << "Digita el valor que deseas buscar: "; cin >> busqueda;
                if(search(tree, busqueda))
                    cout << "Dato " << busqueda << " encontrado" << endl;
                else
                    cout << "No existe ese dato " << endl;
                break;
            case 6:
        
                cout << "Digita el valor que deseas eliminar: "; cin >> eliminar;
                borrarNodo(tree, eliminar);
                break;
            case 7:
                count = true;
                cout << "\nsalir" << endl;
                break;
            default:
                cout << "Opcion incorrecta" << endl;
                break;
        }
    }while(!count);
}

int main(void)
{
    BinarySearchTree objBinarySearchTree;
    objBinarySearchTree.menu();
    return 0;
}