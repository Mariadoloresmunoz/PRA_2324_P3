#ifndef BSNODE_H
#define BDNODE_H

#include <ostream>

using namespace std;

template <typename T>
class BSNode {

	public:

		/*-------------------------------------------------*/
                /*                  elem (atributo)                */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* El elemento de tipo T almacenado en el nodo.    */
                /*                                                 */
                /*-------------------------------------------------*/

		T elem;


		/*-------------------------------------------------*/
                /*                  left (atributo)                */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Puntero al nodo sucesor izquierdo.              */
                /*                                                 */
                /*-------------------------------------------------*/

		BSNode<T>* left;


		/*-------------------------------------------------*/
                /*                 right (atributo)                */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Puntero al nodo sucesor derecho.                */
                /*                                                 */
                /*-------------------------------------------------*/

		BSNode<T>* right;


		/*-------------------------------------------------*/
                /*                 BSNode (constructor)            */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Método constructor que crea un BSNode con el    */
		/* elemento elem y los punteros a los nodos 	   */
		/* sucesores left y right proporcionados (nulos por*/
		/* defecto).					   */
                /*                                                 */
                /*-------------------------------------------------*/

		BSNode(T elem, BSNode<T>* left = nullptr, BSNode<T>* right = nullptr) {

			this->elem = elem;
			this->left = left;
			this->right = right;
		}


		/*-------------------------------------------------*/
                /*                    operador <<                  */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Sobrecarga global del operador << para imprimir */
                /* el nodo por pantalla. Por simplicidad, puedes   */
                /* limitarte a imprimir el atributo elem.          */
                /*                                                 */
                /*-------------------------------------------------*/

		friend ostream& operator<<(ostream &out, const BSNode<T> &bsn) {
		  //imprimimos el atributo elem del nodo en el flujo de salida
		  // y devolvemos el flujo de salida para permitir encadenar las operaciones 
			out << bsn.elem;

			return out;
		}

};

#endif
