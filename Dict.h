#ifndef DICT_H
#define DICT_H
#include <string>

using namespace std;

template <typename V>
class Dict {
	public:
		/*-------------------------------------------------*/
		/*		        insert			   */
		/*-------------------------------------------------*/
		/*						   */
		/* DESCRIPCION:					   */
		/* Inserta el par ket->value en el diccionario.    */
		/* Lanza una excepción std::runtime_error si key   */
		/* ya existe en el diccionario.                    */
		/*						   */
		/*-------------------------------------------------*/

		virtual void insert(string key, V value) = 0;


		/*-------------------------------------------------*/
		/*			search			   */
		/*-------------------------------------------------*/
		/*						   */
		/* DESCRIPCION:					   */
		/* Busca el valor correspondiente a key. Devuelve  */
		/* el valor value asociado si key está en el       */
		/* diccionario. Si no se encuentra, lanza una 	   */
		/* excepción std::runtime_error.                   */
		/*						   */
		/*-------------------------------------------------*/

		virtual V search(string key) = 0;


		/*-------------------------------------------------*/
		/*		        remove			   */
		/*-------------------------------------------------*/
		/*						   */
		/* DESCRIPCION:					   */
		/* Elimina el par key->value si se encuentra en el */
		/* diccionario. Si no se encuentra, lanza una      */
		/* excepción std::runtime_error.                   */
		/*						   */
		/*-------------------------------------------------*/

		virtual V remove(string key) = 0;


		/*-------------------------------------------------*/
		/*			entries			   */
		/*-------------------------------------------------*/
		/*						   */
		/* DESCRIPCION:					   */
		/* Devuelve el número de elementos que tiene el    */
		/* diccionario.                                    */
		/*						   */
		/*-------------------------------------------------*/

		virtual int entries() = 0;

};

#endif  
