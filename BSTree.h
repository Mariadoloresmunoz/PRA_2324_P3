#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"

using namespace std;

template <typename T>
class BSTree {

	private:

		/*-------------------------------------------------*/
                /*                  elem (atributo)                */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Numero de elementos almacenados en el ABB.      */
                /*                                                 */
                /*-------------------------------------------------*/

		int nelem;


		/*-------------------------------------------------*/
                /*                  root (atributo)                */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Nodo raiz del ABB.                              */
                /*                                                 */
                /*-------------------------------------------------*/

		BSNode<T> *root;



		/*-------------------------------------------------*/
		/*                BUSQUEDA DE ELEMENTOS            */
		/*-------------------------------------------------*/

		/*-------------------------------------------------*/
                /*                search (recursivo)               */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* metodo recursivo para la busqueda de elementos  */
		/* en el ABB. Busca y devuelve el elemento e de    */
		/* tipo T si se encuentra en el (sub)arbol cuya    */
		/* raiz es n, de lo contrario lanza una excepcion  */
		/* std::runtime_error.				   */
                /*                                                 */
                /*-------------------------------------------------*/

		BSNode<T>* search (BSNode<T>* n, T e) const {

			if (n == nullptr) {
				throw runtime_error("Element not found!"); 
			}

			else if (n->elem < e) { 
				return search(n->right, e); 
			}

			else if (n->elem > e) { 
				return search(n->left, e); 
			}

			else { 
				return n; 
			}
		}



		/*-------------------------------------------------*/
                /*               INSERCION DE ELEMENTOS            */
                /*-------------------------------------------------*/

		/*-------------------------------------------------*/
                /*                insert (recursivo)               */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Metodo recursivo para la insercion ordenada de  */
                /* elementos. Inserta el elemento e de tipo T de   */
                /* manera ordenada en el (sub)arbol cuya raiz es n.*/
                /* Devuelve el nodo que encabeza dicho (sub)arbol  */
                /* modificado. Si el elemento e ya existe, lanza   */
		/* un std::runtime_error.			   */
                /*                                                 */
                /*-------------------------------------------------*/

		BSNode<T>* insert (BSNode<T>* n, T e) {

			if (n == nullptr) { 
				return new BSNode(e); 
			}

			else if (n->elem == e) { 
				throw runtime_error("Duplicated element!"); 
			}

			else if (n->elem < e) { 
				n->right = insert(n->right, e); 
			}

			else { 
				n->left = insert(n->left, e); 
			}

			return n;
		}



		/*-------------------------------------------------*/
                /*         RECORRIDO E IMPRESION DEL ARBOL         */
                /*-------------------------------------------------*/

		/*-------------------------------------------------*/
                /*            print_inorder (recursivo)            */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Recorrido inorden o simetrico del (sub)arbol    */
                /* cuya raiz es n para mostrar a traves de out los */
                /* elementos ordenados de menos a mayor.           */
                /*                                                 */
                /*-------------------------------------------------*/

		void print_inorder(ostream &out, BSNode<T>* n) const {

			if (n != nullptr) {
				print_inorder(out, n->left);
				out << n->elem << " ";
				print_inorder(out, n->right);
			}
		}



		/*-------------------------------------------------*/
                /*             ELIMINACION DE ELEMENTOS            */
                /*-------------------------------------------------*/

		/*-------------------------------------------------*/
                /*                remove (recursivo)               */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Metodo recursivo para la eliminacion de element.*/
                /* Elimina el elemento e del (sub)arbol cuya raiz  */
                /* es n. Devuelve el nodo que encabeza dicho (sub) */
                /* arbol modificado. En caso de eliminar un nodo   */
                /* con dos sucesores (izquierdo y derecho), se     */
                /* aplicara la politica de reemplazo por el element*/
		/* maximo del subarbol izquierdo. Para ello, se    */
		/* apoyara en los metodos privados auxiliares max()*/
		/* y remove_max(). Si el elemento e no existe,     */
		/* lanza una excepcion std::::runtimeerror.        */
                /*                                                 */
                /*-------------------------------------------------*/

		BSNode<T>* remove(BSNode<T>* n, T e) {

			if (n == nullptr) {	
				throw runtime_error("Element not found!"); 
			}

			else if (n->elem < e) { 
				n->right = remove(n->right, e); 
			}

			else if (n->elem > e) { 
				n->left = remove(n->left, e); 
			}

			else {

				/* Dos sucesores (izquierdo y derecho) */
				if ( (n->left != nullptr) && (n->right != nullptr) ) {

					n->elem = max(n->left);
					n->left = remove_max(n->left);
				}

				/* Uno o cero sucesores */
				else {
					n = (n->left != nullptr) ? (n->left) : (n->right);
				}
			}

			return n;

		}


		/*-------------------------------------------------*/
                /*                   max (recursivo)               */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Metodo recursivo que devuelve el elemento de    */
                /* maximo valor contenido en el (sub)arbol cuya    */
                /* raiz es n.                                      */
                /*                                                 */
                /*-------------------------------------------------*/

		T max(BSNode<T>* n) const {

			if (n == nullptr) {	
				throw runtime_error("Element not found!"); 
			}

			else if (n->right != nullptr) { 
				return max(n->right); 
			}

			else { 
				return n->elem; 
			}
		}


		/*-------------------------------------------------*/
                /*              remove_max (recursivo)             */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Metodo recursivo que elimina el elemento de     */
                /* maximo valor contenido en el (sub)arbol cuya    */
                /* raiz es n.                                      */
                /*                                                 */
                /*-------------------------------------------------*/

		BSNode<T>* remove_max(BSNode<T>* n) {

			if (n->right == nullptr) {

				BSNode<T>* removed = n->left;
				delete n;
				return removed;
			}

			else {
				n->right = remove_max(n->right);
				return n;
			}
		}


		
		/*-------------------------------------------------*/
                /*                    DESTRUCCION                  */
                /*-------------------------------------------------*/

		/*-------------------------------------------------*/
                /*           delete_cascade (recursivo)            */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Metodo recursivo para la liberacion de la 	   */
                /* memoria dinamica ocupada por los objetos de tipo*/
                /* BSNode<T> que conforman el (sub)arbol cuya raiz */
		/* es n.					   */
                /*                                                 */
                /*-------------------------------------------------*/

		void delete_cascade(BSNode<T>* n) {

			if (n != nullptr) {
				delete_cascade(n->left);
				delete_cascade(n->right);
				delete n;
			}
		}

	public:

		/*-------------------------------------------------*/
                /*                CREACION Y TAMANO                */
                /*-------------------------------------------------*/

		/*-------------------------------------------------*/
                /*               BSTree (constructor)              */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Metodo constructor. Crea un ABB vacio.          */
		/* 						   */
                /*-------------------------------------------------*/

		BSTree() {

			this->nelem = 0;
			this->root = nullptr;
		}


		/*-------------------------------------------------*/
                /*                      size                       */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Devuelve el numero de elementos nelem del ABB.  */
                /*                                                 */
                /*-------------------------------------------------*/

		int size() const {

			return nelem;
		}


		/*-------------------------------------------------*/
                /*                 search (lanzadera)              */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Busca y devuelve el elemento e de tipo T en el  */
                /* ABB. Actua como metodo lanzadera del metodo priv*/
                /* recursivo search(BSNode<T>* n, T e). Notar que  */
                /* debera devolver el elemento contenido por el    */
		/* nodo devuelto por el metodo privado.		   */
                /*                                                 */
                /*-------------------------------------------------*/

		T search(T e) const {

			return (search(root, e))->elem;
		}


		/*-------------------------------------------------*/
                /*                  operator []                    */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Sobrecarga el operador []. Actua como interfaz  */
		/* al metodo search(T e).			   */
                /*                                                 */
                /*-------------------------------------------------*/

		T operator[](T e) const {

			return search(e);
		}



		/*-------------------------------------------------*/
                /*              INSERCION DE ELEMENTOS             */
                /*-------------------------------------------------*/

		/*-------------------------------------------------*/
                /*                 insert (lanzadera)              */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Inserta el elemento e de tipo T de manera ord.  */
                /* en el ABB. Actua como metodo lanzadera del mtdo.*/
                /* privado recursivo insert(BSNode<T>* n, T e).    */
                /*                                                 */
                /*-------------------------------------------------*/

		void insert(T e) {

			root = insert(root, e);
			nelem++;
		}



		/*-------------------------------------------------*/
                /*         RECORRIDO E IMPRESION DEL ARBOL         */
                /*-------------------------------------------------*/

		/*-------------------------------------------------*/
                /*             operator << (lanzadera)             */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Sobrecarga del operador << para mostrar a traves*/
                /* de out los contenidos del ABB bst, realizando un*/
                /* recorrido inorden o simetrico del arbol para    */
                /* mostrar los elementos ordenados de menor a mayor*/
                /* Delega en el metodo privado recursivo 	   */
		/* print_inorder().				   */
                /*                                                 */
                /*-------------------------------------------------*/

		friend ostream& operator<<(ostream &out, const BSTree<T> &bst) {

			bst.print_inorder(out, bst.root);
			return out;
		}



		/*-------------------------------------------------*/
                /*            ELIMINACION DE ELEMENTOS             */
                /*-------------------------------------------------*/

		/*-------------------------------------------------*/
                /*                 remove (lanzadera)              */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Elimina el elemento e de tipo T del ABB. Actua  */
                /* como metodo lanzadera del metodo privado recurs.*/
                /* remove(BSNode<T>* n, T e).                      */
                /*                                                 */
                /*-------------------------------------------------*/

		void remove(T e) {

			root = remove(root, e);
			nelem--;
		}



		/*-------------------------------------------------*/
                /*                  DESTRUCCION                    */
                /*-------------------------------------------------*/

		/*-------------------------------------------------*/
                /*                ~BSTree (destructor)             */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Metodo destructor. Delega en el metodo privado  */
                /* recursivo delete_cascade().                     */
                /*                                                 */
                /*-------------------------------------------------*/

		~BSTree() {

			delete_cascade(root);
		}

};

#endif
