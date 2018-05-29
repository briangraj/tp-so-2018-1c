/*
 * hilo_esi.h
 *
 *  Created on: 22 abr. 2018
 *      Author: utnso
 */

#ifndef HILO_ESI_H_
#define HILO_ESI_H_

#include "coordinador.h"
#include "conexiones/estructuras_coord.h"

void 		 crear_hilo_esi		   (int socket_cliente);
void* 		 atender_esi		   (void* socket_esi);
t_solicitud* recibir_solicitud_esi (int socket, int id);
t_solicitud* crear_get			   (int socket);
t_solicitud* crear_set			   (int socket);
t_solicitud* crear_store		   (int socket);
t_instancia* elegir_instancia	   (t_solicitud* solicitud);
void 		 distribuir			   (t_solicitud* solicitud);
void		 agregar_pedido		   (t_instancia* instancia, t_solicitud* solicitud);
void 		 realizar_solicitud	   (t_solicitud* solicitud);
void 		 realizar_get		   (t_solicitud* solicitud);
int 		 enviar_a_planif	   (void* stream, int tam_stream);

#endif /* HILO_ESI_H_ */
