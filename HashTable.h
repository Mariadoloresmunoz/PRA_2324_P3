
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"
#include "/home/alumno.upv.es.mdmuogar/W/3/PRA/prac1/PRA_2324_P1/ListLinked.h"

using namespace std;

template <typename V>
class HashTable : public Dict<V> {

	private:

		/*-------------------------------------------------*/
                /*                  n (atributo)                   */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Numero de elementos almacenados actualmente en  */
                /* la tabla hash.                                  */
                /*                                                 */
                /*-------------------------------------------------*/

		int n;


		/*-------------------------------------------------*/
                /*                 max (atributo)                  */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Tamaño de la tabla hash (numero total de        */
                /* cubetas).                                       */
                /*                                                 */
                /*-------------------------------------------------*/

		int max;


		/*-------------------------------------------------*/
                /*           Tabla de cubetas (atributo)           */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Tabla de cubetas, representada por un array de  */
                /* punteros a listas enlazadas (tipo ListLinked<T>)*/
		/* que almacenan pares clave->valor,		   */
		/* (tipo TableEntry<V>).			   */
		/*                                                 */
                /*-------------------------------------------------*/

		ListLinked<TableEntry<V>>* table;


		/*-------------------------------------------------*/
                /*                h (función hash)                 */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Funcion hash que devuelve la posición (cubeta)  */
                /* en la table hash de key. Se calculara como el   */
                /* resto de la division entre la suma de los       */
                /* valores ASCII numericos de los caracteres de la */
		/* clave y el tamaño de la tabla hash.		   */
                /*                                                 */
                /*-------------------------------------------------*/

		int h(string key) {

			int sumASCII = 0;

			for (int i = 0; i < key.size(); i++){
				sumASCII += int(key.at(i));
			}

			return sumASCII % capacity();
		}

	public:

		/*-------------------- INSERT ---------------------*/
		void insert(string key, V value) override {

			int pos = h(key);
			TableEntry<V> aux(key, value);

			if ( (table[pos].search(aux) ) == -1) {
				
				table[pos].insert(table[pos].size(), aux);
				n++;
			}

			else {
				throw runtime_error("Key '" + key + "' already exits!");
			}
		}
		/*-------------------------------------------------*/


		/*-------------------- SEARCH ---------------------*/
		V search(string key) override {

			int pos = h(key);
			TableEntry<V> aux(key);

			int listPos = table[pos].search(aux);

			if (listPos == -1) {
				throw runtime_error("Key '" + key + "' not found!");
			}

			return table[pos].get(listPos).value;
		}
		/*-------------------------------------------------*/


		/*-------------------- REMOVE ---------------------*/
		V remove(string key) override {

			int pos = h(key);
			TableEntry<V> aux(key);

			int listPos = table[pos].search(aux);

			if (listPos == -1) { 
				throw runtime_error("Key '" + key + "' not found!"); 
			}

			n--;

			return table[pos].remove(listPos).value;
		}
		/*-------------------------------------------------*/


		/*-------------------- ENTRIES --------------------*/
		int entries() override {

			return n;
		}
		/*-------------------------------------------------*/



		/*-------------------------------------------------*/
                /*             HashTable (constructor)             */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Metodo constructor. Reservara memoria dinamica  */
                /* para crear una tabla "table" de tamaño size, e  */
		/* inicializara los atributos n y max de la clase. */
                /*                                                 */
                /*-------------------------------------------------*/

		HashTable(int size) {

			this->n = 0;
			this->max = size;
			this->table = new ListLinked<TableEntry<V>>[size];
		}


		/*-------------------------------------------------*/
                /*            ~HashTable (destructor)              */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Metodo destructor. Se encargara de liberar la   */
                /* memoria dinamica reservada al crear la tabla    */
                /* "table".                                        */
                /*                                                 */
                /*-------------------------------------------------*/

		~HashTable() {

			delete[] table;
		}


		/*-------------------------------------------------*/
                /*                   capacity                      */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Devuelve el numero total de cubetas de la tabla.*/
                /*                                                 */
                /*-------------------------------------------------*/

		int capacity() {

			return max;
		}


		/*-------------------------------------------------*/
                /*                     operator<<                  */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Sobrecarga global del operador << para imprimir */
                /* el contenido de la tabla hash por pantalla.     */
                /*                                                 */
                /*-------------------------------------------------*/

		friend ostream& operator<< (ostream &out, const HashTable<V> &th) {

			out << "HashTable [entries: " << (th.n) << ", capacity: " << (th.max) << "]" << endl;
			out << "------------------------" << endl << endl;

			for (int i = 0; i < (th.max); i++) {

				out << "-- Cubeta " << i << " --" << endl << endl;
				out << th.table[i] << endl << endl;
			}

			out << "-------------------------" << endl;

			return out;
		}


		/*-------------------------------------------------*/
                /*                     operator[]                  */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Sobrecarga del operador []. Devuelve el valor   */
                /* correspondiente a key. Si no existe, lanza la   */
		/* excepción runtime_error.            		   */
                /*                                                 */
                /*-------------------------------------------------*/

		V operator[] (string key) {

			return search(key);
		}

};

#endif
