#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

using namespace std;

template <typename V>
class BSTreeDict : public Dict<V> {

	private:

		/*-------------------------------------------------*/
                /*                 elem (atributo)                 */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* ABB con elementos de tipo TableEntry<V> para    */
                /* gestionar los elementos de un diccionario.      */
		/* 						   */
                /*-------------------------------------------------*/

		BSTree<TableEntry<V>>* tree;

	public:

		/*------------------- INSERT ----------------------*/
		void insert(string key, V value) override {

			tree->insert(TableEntry<V> (key, value) );
		}
		/*-------------------------------------------------*/


		/*------------------- SEARCH ----------------------*/
		V search(string key) override {

			return tree->search(TableEntry<V> (key)).value;
		}
		/*-------------------------------------------------*/


		/*------------------- REMOVE ----------------------*/
		V remove(string key) override {

			V removed = tree->search(TableEntry<V> (key)).value;
			tree->remove(TableEntry<V> (key));
			return removed;
		}
		/*-------------------------------------------------*/


		/*------------------- ENTRIES ---------------------*/
		int entries() override	{

			return tree->size();
		}
		/*-------------------------------------------------*/



		/*-------------------------------------------------*/
                /*             BSTreeDict (constructor)            */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Constructor. Crea un ABB vacio con memoria      */
                /* dinámica.                                       */
                /*                                                 */
                /*-------------------------------------------------*/

		BSTreeDict() {

			tree = new BSTree<TableEntry<V>>;
		}


		/*-------------------------------------------------*/
                /*            ~BSTreeDict (destructor)             */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Metodo destructor. Se encarga de liberar la     */
                /* memoria dinamica ocupada por el ABB tree.       */
                /*                                                 */
                /*-------------------------------------------------*/

		~BSTreeDict() {

			delete tree;
		}


		/*-------------------------------------------------*/
                /*                    operator <<                  */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Sobrecarga global del operador << para imprimir */
                /* el contenido del Diccionario por pantalla.      */
                /*                                                 */
                /*-------------------------------------------------*/

		friend ostream& operator<<(ostream &out, const BSTreeDict<V> &bs) {

			return out << *bs.tree << endl;
		}


		/*-------------------------------------------------*/
                /*                    operator []                  */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Sobrecarga del operador[]. Actua como interfaz  */
                /* al metodo heredado search(string key).          */
                /*                                                 */
                /*-------------------------------------------------*/

		V operator[](string key) {

			return search(key);
		}

};

#endif
