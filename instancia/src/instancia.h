/*
 * instancia.h
 *
 *  Created on: 20 abr. 2018
 *      Author: utnso
 */

#ifndef SRC_INSTANCIA_H_
#define SRC_INSTANCIA_H_

#include <dirent.h>
#include <sys/mman.h>
#include <commons/bitarray.h>
#include <commons/config.h>
#include <commons/collections/list.h>
#include <commons/log.h>
#include <conexiones/archivos.h>
#include <conexiones/protocolos.h>
#include <conexiones/serializacion.h>
#include <conexiones/sockets.h>
#include <conexiones/strings.h>
#include <conexiones/threads.h>

#define PATH_CONFIG "/home/utnso/workspace/tp-2018-1c-A-la-grande-le-puse-Jacketing/configs/instancia.cfg"

typedef struct {
	int nro_entrada;
	char* clave;
	int tamanio_bytes_clave;
	int tamanio_entradas_clave;
}t_entrada;

char* PUNTO_MONTAJE;
char* IP_COORDINADOR;
char* ALGORITMO_REEMPLAZO;
int PUERTO_COORDINADOR;
int CANTIDAD_ENTRADAS_TOTALES;
int TAMANIO_ENTRADA;
int MI_ID;
int INTERVALO_DUMP;
int socket_coordinador;
void* memoria;
pthread_mutex_t mutex_dump;

int (*algoritmo_reemplazo)(char*, char*);

//para reemplazo circular
int entrada_a_reemplazar;

t_log* log_instancia;
t_list* tabla_de_entradas;
t_bitarray* bitarray_entradas;

void inicializar();
void leer_config();
void setup_algoritmo_reemplazo();
void conectar_con_coordinador();
void enviar_entradas_al_coordinador();
void* hilo_dump(void* _);
void escuchar_coordinador();
void leer_protocolo(int protocolo);
void configuracion_entradas();
void crear_tabla_de_entradas();
void crear_bitarray();
t_entrada* levantar_entrada(char* nombre);
t_entrada* crear_entrada(char* clave);
int tamanio_entrada_en_disco(char* nombre);
void levantar_entrada_a_memoria(t_entrada* entrada);
void copiar_a_memoria(t_entrada* entrada, void* valor);
int abrir_entrada(char* nombre);
char* ruta_absoluta(char* nombre);
struct stat crear_stat(int fd);
void* mi_mmap(int fd, struct stat stat);
int entradas_ocupadas(int tamanio);
int entrada_para(int cant_entradas);
int entradas_libres_desde(int nro_entrada);
void setear_bitarray(t_entrada* entrada);
int atender_set();
int modificar_entrada(char* clave, char* valor);
int entradas_disponibles();
void actualizar_tamanio_entrada(t_entrada* entrada, char* valor);
void actualizar_valor_entrada(t_entrada* entrada, char* valor);
void liberar_entradas_desde(int desde_entrada, int cantidad);
int atender_store();
void persistir(void* entrada_void);
int atender_crear_clave();
int buscar_entrada_para_reemplazar(char* clave, char* valor);
void reemplazar_entrada(int nro_entrada, char* clave, char* valor);
void eliminar_entrada(char* nombre);
int reemplazo_circular(char* clave, char* valor);
bool es_nro_entrada_atomica(int nro_entrada);
t_entrada* buscar_entrada(void* buscado, bool (*comparador)(void*, void*));
bool buscar_entrada_clave(void* entrada_void, void* clave_void);
bool buscar_entrada_nro(void* entrada_void, void* nro_void);
int siguiente_entrada(int nro_entrada);
int reemplazo_bsu(char* clave, char* valor);
bool es_entrada_atomica(void* entrada_void);
bool mayor_entrada(void* entrada1, void* entrada2);
int reemplazo_lru(char* clave, char* valor);
void atender_compactacion();
bool menor_nro_entrada(void* entrada1, void* entrada2);
char* obtener_valor_de(t_entrada* entrada);

#endif /* SRC_INSTANCIA_H_ */
