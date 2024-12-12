#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>


using namespace std;

template <typename V>
class TableEntry {
	public:
		/*-------------------------------------------------*/
		/*		          key  			   */
		/*-------------------------------------------------*/
		/*						   */
		/* DESCRIPCION:					   */
		/* El elemento clave del par.                      */
		/*                                         	   */
		/*-------------------------------------------------*/

		string key;


		/*-------------------------------------------------*/
		/*		        value			   */
		/*-------------------------------------------------*/
		/*						   */
		/* DESCRIPCION:					   */
		/* El elemento valor del par.                      */
		/*                      			   */
		/*-------------------------------------------------*/

		V value;


		/*-------------------------------------------------*/
		/*		TableEntry (constructor1)	   */
		/*-------------------------------------------------*/
		/*						   */
		/* DESCRIPCION:					   */
		/* Método constructor con el par clave->valor.     */
		/*						   */
		/*-------------------------------------------------*/

		TableEntry(string key, V value){

			this->key = key;
			this->value = value;
		}


		/*-------------------------------------------------*/
		/*		TableEntry (constructor2)	   */
		/*-------------------------------------------------*/
		/*						   */
		/* DESCRIPCION:					   */
		/* Crea una entrada solo con clave (sin valor).    */
		/*						   */
		/*-------------------------------------------------*/

		TableEntry(string key){

			this->key = key;
		}


		/*-------------------------------------------------*/
		/*		TableEntry (constructor3)	   */
		/*-------------------------------------------------*/
		/*						   */
		/* DESCRIPCION:					   */
		/* Crea una entrada con la clave "" (cadena vacia) */
		/* y sin valor.                                    */
		/*						   */
		/*-------------------------------------------------*/

		TableEntry(){

			this->key = "";
		}


		/*-------------------------------------------------*/
		/*		     operator==			   */
		/*-------------------------------------------------*/
		/*						   */
		/* DESCRIPCION:					   */
		/* Sobrecarga global del operador == para          */
		/* determinar que dos instancias de TableEntry son */
		/* iguales solo si comparten la misma clave (con   */
		/* independencia del valor).			   */
		/*						   */
		/*-------------------------------------------------*/

		friend bool operator==(const TableEntry<V> &te1, const TableEntry<V> &te2){

			bool result;
			(te1.key.compare(te2.key) == 0) ? (result = 1) : (result = 0);
			return result;
		}


		/*-------------------------------------------------*/
                /*                   operator!=                    */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Sobrecarga global del operador != para          */
                /* determinar que dos instancias de TableEntry son */
                /* diferentes solo si sus claves son distintas     */
                /* (con independencia del valor).                  */
                /*                                                 */
                /*-------------------------------------------------*/

		friend bool operator!=(const TableEntry<V> &te1, const TableEntry<V> &te2){

			bool result;
                        (te1.key.compare(te2.key) != 0) ? (result = 1) : (result = 0);
                        return result;
		}


		/*-------------------------------------------------*/
                /*                   operator<<                    */
                /*-------------------------------------------------*/
                /*                                                 */
                /* DESCRIPCION:                                    */
                /* Sobrecarga global del operador << para imprimir */
                /* el contenido de la entrada (par clave-> valor)  */
                /* por pantalla.                                   */
                /*                                                 */
                /*-------------------------------------------------*/

		friend ostream& operator<<(ostream &out, const TableEntry<V> &te){

			out << "('" << te.key << "' => " << te.value << ")";
			return out;
		}

	
		/*--------------------------------------------------*/
		/*                     operator <	            */
		/*--------------------------------------------------*/
		/*                                                  */
		/* DESCRIPCION:                                     */
		/* Sobrecarga global del operador < para comparar el*/
		/* contenido de dos TableEntry.                     */
		/*                                                  */
		/*--------------------------------------------------*/

		friend bool operator< (const TableEntry<V> &te1, const TableEntry<V> &te2) {

			return (te1.key < te2.key) ? (1) : (0);
		}


		/*--------------------------------------------------*/
		/*                     operator >	            */
		/*--------------------------------------------------*/
		/* EXTRA                                            */
		/* DESCRIPCION:                                     */
		/* Sobrecarga global del operador > para comparar   */
		/* el contenido de dos TableEntry.                  */
		/*                                                  */
		/*--------------------------------------------------*/

		friend bool operator> (const TableEntry<V> &te1, const TableEntry<V> &te2) {

			return (te1.key > te2.key) ? (1) : (0);
		}
		
};

#endif
