/*
 * t_mensaje.c
 *
 *  Created on: 4 jun. 2018
 *      Author: utnso
 */

#include "t_mensaje.h"

t_mensaje crear_mensaje(int header, int tam_payload){
	t_mensaje mensaje = {
			.header = header,
			.tam_payload = tam_payload,
			.payload = malloc(tam_payload)
	};

	return mensaje;
}

int enviar_mensaje(t_mensaje mensaje, int socket){
	return enviar_paquete(mensaje.header, socket, mensaje.tam_payload, mensaje.payload);
}

int enviar_mensaje_v2(int socket, t_mensaje (*serializer)(void*), void* target){
	return enviar_mensaje(serializer(target), socket);//TODO proponerle esto al chakl xd
}

void destruir_mensaje(t_mensaje mensaje){
	free(mensaje.payload);
}
